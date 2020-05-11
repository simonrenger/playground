add_executable(
    cpp_playground
    sr/main.cpp
     "sr/utils.cpp")
target_include_directories(cpp_playground
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    )
