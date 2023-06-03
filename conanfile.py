#  Copyright (c) 2022 Jelle Spijker
#  NailClipper is released under the terms of the AGPLv3 or higher

from os import path

from conan import ConanFile, Version
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.env import VirtualBuildEnv
from conan.tools.files import copy
from conan.tools.build import check_min_cppstd
from conan.tools.microsoft import check_min_vs, is_msvc, is_msvc_static_runtime
from conans.errors import ConanInvalidConfiguration


class NailClipperConan(ConanFile):
    name = "nailclipper"
    version = "0.1.0-alpha.1"
    description = "A modern polygon clipper lib"
    topics = ("conan", "vtk")
    license = "AGPL-3.0"
    homepage = "https://github.com/jellespijker/NailClipper"
    url = "https://github.com/jellespijker/NailClipper"
    settings = "os", "compiler", "build_type", "arch"
    exports = "LICENSE*"
    options = {
        "enable_tests": [True, False],
        "enable_benchmarks": [True, False],
        "shared": [True, False],
        "fPIC": [True, False],
    }
    default_options = {
        "enable_tests": True,
        "enable_benchmarks": True,
        "shared": True,
        "fPIC": False,
    }

    @property
    def _min_cppstd(self):
        return 20

    @property
    def _compilers_minimum_version(self):
        return {
            "gcc": "12",
            "clang": "14",
            "apple-clang": "14",
            "msvc": "192",
            "visual_studio": "17",
        }

    def export_sources(self):
        copy(self, "CMakeLists.txt", self.recipe_folder, self.export_sources_folder)
        copy(self, "LICENSE", self.recipe_folder, self.export_sources_folder)
        copy(self, "*", path.join(self.recipe_folder, "include"), path.join(self.export_sources_folder, "include"))
        copy(self, "*", path.join(self.recipe_folder, "benchmark"), path.join(self.export_sources_folder, "benchmark"))
        copy(self, "*", path.join(self.recipe_folder, "tests"), path.join(self.export_sources_folder, "tests"))

    def build_requirements(self):
        self.test_requires("standardprojectsettings/[>=0.1.0]@ultimaker/stable")
        if self.options.enable_tests:
            self.test_requires("catch2/[>=2.13.8]")
        if self.options.enable_benchmarks:
            self.test_requires("benchmark/[>=1.6.1]")

    def requirements(self):
        self.requires("range-v3/[>=0.11.0]", transitive_headers=True)
        self.requires("fmt/[>=8.1.1]", transitive_headers=True)
        self.requires("spdlog/[>=1.10.0]", transitive_headers=True)
        self.requires("ctre/[>=3.6]", transitive_headers=True)

    def package_id(self):
        self.info.clear()

    def validate(self):
        if self.settings.compiler.cppstd:
            check_min_cppstd(self, self._min_cppstd)
        check_min_vs(self, 192)  # TODO: remove in Conan 2.0
        if not is_msvc(self):
            minimum_version = self._compilers_minimum_version.get(str(self.settings.compiler), False)
            if minimum_version and Version(self.settings.compiler.version) < minimum_version:
                raise ConanInvalidConfiguration(
                    f"{self.ref} requires C++{self._min_cppstd}, which your compiler does not support."
                )

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables["ENABLE_TESTS"] = self.options.enable_tests
        tc.variables["ENABLE_BENCHMARKS"] = self.options.enable_benchmarks
        if is_msvc(self):
            tc.variables["USE_MSVC_RUNTIME_LIBRARY_DLL"] = not is_msvc_static_runtime(self)
        tc.cache_variables["CMAKE_POLICY_DEFAULT_CMP0077"] = "NEW"
        tc.generate()

        tc = CMakeDeps(self)
        tc.generate()

        tc = VirtualBuildEnv(self)
        tc.generate(scope="build")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.install()

    def package(self):
        copy(
            self,
            pattern="*.h",
            dst=path.join(self.package_folder, "include"),
            src=path.join(self.source_folder, "include"),
        )

    def package_info(self):
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []
