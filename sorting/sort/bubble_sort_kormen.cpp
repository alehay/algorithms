#include <cstdio>
#include <cstdlib>
#include <climits>

#include "bubble_sort_kormen.hpp"

int main (int argc, char * argv []) {
  int lenght = argc - 1;
  int * arr = (int*) malloc (sizeof(int) * lenght);
  
  printf("\n source arr : \n");
  for (int i = 0; i < lenght; ++i) {
    arr[i] = atoi(argv[i+1]);
    printf(" %d", arr[i]);
  }
  
  bubble_sort(arr, 0, lenght);

  printf("\n sorted array : \n");
  for (int i = 0; i < lenght; ++i){
    printf(" %d",arr[i]);
  }
  printf("\n");
  free (arr);
  return 0;
}