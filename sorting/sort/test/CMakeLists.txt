add_executable(sort_test sort_test.cpp)
target_link_libraries(sort_test gtest) 
gtest_discover_tests(sort_test)