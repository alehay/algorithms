#include <iostream>
#include <stdio.h>
#include <cstdlib>

void insertion_sort (int arr[], int length) {
    int iteration = 1; 
    for (int j = 1; j < length; ++j) {
        int temp_key = arr[j];
        int i = j - 1;
        while (i>=0 && arr[i] > temp_key)
        {
            arr[i+1] = arr[i];
            --i;
            arr[i+1] = temp_key;

            // print 
            printf("\n iter is %d \n", iteration++);
            for (int index = 0; index < length; ++index) {
                printf(" %d",arr[index]);
            }
        }
    }
    printf("\n");
    return;
}

int main (int argc , char * argv []) {
    if (argc > 0) {
        printf ("program run %s \n" , argv[0]);
    }

    int* num_arr_ptr = (int*) malloc (argc-1);
    if (num_arr_ptr == nullptr) {
        return 1; 
    }

    printf ("source array : \n");
    for (int i = 0; i < argc-1; ++i ) {
        num_arr_ptr[i] = std::atoi(argv[i+1]);
        printf(" %d",num_arr_ptr[i]);
    }
    printf ("\n");

    insertion_sort(num_arr_ptr, argc-1);

    printf ("sorted array : \n");
    for (int i = 0; i < argc-1; ++i ) {
        printf(" %d",num_arr_ptr[i]);
    }
    printf ("\n");
    free (num_arr_ptr);

    return 0; 
}