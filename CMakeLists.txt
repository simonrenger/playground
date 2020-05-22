cmake_minimum_required(VERSION 3.10)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/third_party/Catch2/contrib")

project(cpp_playground VERSION 0.0.1 DESCRIPTION "A great new project")


set(BENCHMARK_ENABLE_GTEST_TESTS off)
set(BENCHMARK_ENABLE_TESTING off)
option(BUILD_TESTING "Build tests" ON)

# Include third-party components we need for the build

add_subdirectory(third_party/benchmark)
add_subdirectory(third_party/Catch2)
add_subdirectory(src)



if(BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    enable_testing()
    add_subdirectory(tests)
endif()



