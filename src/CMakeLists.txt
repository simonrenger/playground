add_library(
    cpp_playground
    "sr/vector_sort.cpp"
      "sr/peak_finder.cpp"
      "sr/vector_shifts.cpp"
       "sr/operator.cpp")
target_include_directories(cpp_playground
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    )


