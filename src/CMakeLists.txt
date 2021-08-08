add_executable(tests
    Inheritance.cpp
    ClassPaddingAndSize.cpp
)

target_link_libraries(tests gtest_main)
add_test(NAME all_tests COMMAND tests)