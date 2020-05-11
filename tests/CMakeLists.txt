add_executable(
    cpp_playground_benchmarks
    benchmarks/benchmarks.cpp
    )
target_include_directories(cpp_playground_benchmarks
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(cpp_playground_benchmarks cpp_playground)
target_link_libraries(cpp_playground_benchmarks benchmark::benchmark)
target_link_libraries(cpp_playground_benchmarks Shlwapi.lib)

add_executable(
    cpp_playground_tests
    tests/main.cpp
     )

target_link_libraries(cpp_playground_tests PUBLIC
cpp_playground
Catch2)

target_include_directories(cpp_playground_tests
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

include(CTest)
include(Catch)
catch_discover_tests(cpp_playground_tests)
