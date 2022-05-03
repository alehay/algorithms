
add_executable(insertion-sort-kormen insertion-sort-kormen.cpp)
add_test(Test-insertion-sort insertion-sort-kormen 0 8 16 17 28 33 54 57 70 89 100 99 -3 -12 7 19 -99 20 5 100 0)
set_tests_properties(Test-insertion-sort PROPERTIES
PASS_REGULAR_EXPRESSION "-99 -12 -3 0 0 5 7 8 16 17 19 20 28 33 54 57 70 89 99 100 100")


add_executable(merge_sort_kormen merge_sort_kormen.cpp)
add_test(Test-merge_sort merge_sort_kormen 0 8 16 17 28 33 54 57 70 89 100 99 -3 -12 7 19 -99 20 5 100 0)
set_tests_properties(Test-merge_sort PROPERTIES
PASS_REGULAR_EXPRESSION "-99 -12 -3 0 0 5 7 8 16 17 19 20 28 33 54 57 70 89 99 100 100")



add_executable(bubble_sort_kormen bubble_sort_kormen.cpp)
add_test(Test_bubble_sort bubble_sort_kormen 0 8 16 17 28 33 54 57 70 89 100 99 -3 -12 7 19 -99 20 5 100 0)
set_tests_properties(Test_bubble_sort PROPERTIES
PASS_REGULAR_EXPRESSION "-99 -12 -3 0 0 5 7 8 16 17 19 20 28 33 54 57 70 89 99 100 100")

#merge sorting without memory allocation 
add_executable(merge_sort_kormen2 merge_sort_kormen2.cpp)
add_test(Test_merge_sort_kormen2 merge_sort_kormen2 0 8 16 17 28 33 54 57 70 89 100 99 -3 -12 7 19 -99 20 5 100 0)
set_tests_properties(Test_merge_sort_kormen2 PROPERTIES
PASS_REGULAR_EXPRESSION "-99 -12 -3 0 0 5 7 8 16 17 19 20 28 33 54 57 70 89 99 100 100")
