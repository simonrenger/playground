add_library(
    cpp_playground
    sr/main.hpp
    sr/main.cpp
    )
add_library(sr::cpp_playground ALIAS cpp_playground)
target_include_directories(cpp_playground
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    )
