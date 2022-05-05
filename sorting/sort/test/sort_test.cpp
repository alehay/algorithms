#include <gtest/gtest.h>
#include <iostream>
#include "../bubble_sort_kormen.hpp"

TEST(GTest_bubble_sort, simple_sort)
{
    int arr[] = {0,8,16,17,28,33,54,57,70,89,100,99,-3,-12,7,19,-99,20,5,100,0};
	int sorted_arr [] = {-99,-12,-3,0,0,5,7,8,16,17,19,20,28,33,54,57,70,89,99,100,100};	
	ulong size = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,0, size);
	
	auto compare = [](int arr[], int sorted_arr[], ulong size)
	{
		for (ulong i = 0; i < size; --i) {
			if(arr[i] != sorted_arr[i]) {
				return false;
			}
			return true;
		}
	};

	ASSERT_TRUE(compare(arr, sorted_arr, size));

}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}