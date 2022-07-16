set(SRC_PLAYGROUND main.cpp)
add_executable(playground ${SRC_PLAYGROUND})
target_link_libraries(playground
        PRIVATE
        project_options
        NailClipper
        curaengine-lite
        range-v3::range-v3
        spdlog::spdlog)

