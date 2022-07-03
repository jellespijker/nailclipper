#  Copyright (c) 2022 Jelle Spijker
#  NailClipper is released under the terms of the AGPLv3 or higher

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conans import tools


class NailClipperConan(ConanFile):
    name = "NailClipper"
    version = "0.1.0"
    description = "A modern polygon clipper lib"
    topics = ("conan", "vtk")
    license = "MIT"
    homepage = "https://github.com/jellespijker/NailClipper"
    url = "https://github.com/jellespijker/NailClipper"
    settings = "os", "compiler", "build_type", "arch"
    exports = "LICENSE*"
    options = {
        "tests": [True, False],
        "benchmarks": [True, False],
        "shared": [True, False],
        "fPIC": [True, False],
        "with_mesh": [True, False]
    }
    default_options = {
        "tests": True,
        "benchmarks": True,
        "shared": True,
        "fPIC": False,
        "with_mesh": True
    }
    scm = {
        "type": "git",
        "subfolder": ".",
        "url": "auto",
        "revision": "auto"
    }

    def build_requirements(self):
        if self.options.tests:
            self.tool_requires("catch2/[>=2.13.8]")
        if self.options.benchmarks:
            self.tool_requires("benchmark/[>=1.6.1]")
            self.tool_requires("clipper/[>=6.4.2]")

    def requirements(self):
        self.requires("range-v3/[>=0.11.0]")
        self.requires("fmt/[>=8.1.1]")
        self.requires("spdlog/[>=1.10.0]")
        self.requires("pugixml/[>=1.12.1]")
        if self.options.with_mesh:
            self.requires("ctre/[>=3.6]")

    def validate(self):
        if self.settings.compiler.get_safe("cppstd"):
            tools.check_min_cppstd(self, 20)

    def layout(self):
        cmake_layout(self)

    def generate(self):

        deps = CMakeDeps(self)
        deps.build_context_activated = ["benchmark", "catch2", "clipper"]
        deps.build_context_build_modules = ["benchmark", "catch2", "clipper"]
        deps.generate()

        tc = CMakeToolchain(self)
        tc.variables["ENABLE_TESTS"] = self.options.tests
        tc.variables["ENABLE_BENCHMARKS"] = self.options.benchmarks
        tc.variables["WITH_MESH"] = self.options.with_mesh
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.install()
