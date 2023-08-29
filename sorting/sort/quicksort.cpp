#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

#include <stack>

#include <cstdlib>
#include <chrono>




  


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
/* This function is same in both iterative and recursive*/
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
  
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* A[] --> Array to be sorted, 
l --> Starting index, 
h --> Ending index */
void quickSort(int A[], int l, int h)
{
    if (l < h) {
        /* Partitioning index */
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}

  
/* A[] --> Array to be sorted, 
l --> Starting index, 
h --> Ending index */
void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
  
// A utility function to print contents of arr
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
}
  
struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> begin_time;

    Timer(){
        begin_time = std::chrono::high_resolution_clock::now();
    }

    std::uint64_t get_duration(){
        auto end_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(
                end_time - begin_time).count();
    }
};

// Driver code
int main()
{
    const int n = 1000000;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    
    std::vector<int> vec;
    vec.assign(arr, arr+n);
    
    //int n = sizeof(arr) / sizeof(*arr);
    
    Timer t1;

    quickSortIterative(arr, 0, n - 1);
    //quickSort(arr, 0, n - 1);
    std::cout <<"quickSortIterative " <<  t1.get_duration() << std::endl;

    //std::qsort(arr[] , 0 , n-1);

    Timer t2;
    std::sort(vec.begin(), vec.end());
    std::cout << "std::sort " << t2.get_duration() << std::endl;


    for (std::size_t i = 0 ; i < n ; ++i) {
        if(vec[i] != arr[i]) {
            std::cout << "error" << " ";
        }
    }
    

//    printArr(arr, n);
    return 0;
}

