#include <cstdio>
#include <cstdlib>
#include <climits>

void merge (int * arr, int iter_start_first, int iter_start_second, int lenght) {
  int left_range = iter_start_second - iter_start_first; 
  int right_range = lenght - iter_start_second;
  int * left_arr = (int*)malloc(sizeof(int)*(left_range + 1));
  int * right_arr = (int*)malloc(sizeof(int)*(right_range + 1));

  for (int i = 0; i < left_range ; ++i) {
    left_arr[i] = arr[iter_start_first + i]; 
  } 
  left_arr[left_range] = INT_MAX;

  for (int j = 0; j < right_range; ++j) {
    right_arr[j] = arr[iter_start_second + j];
  }
  right_arr[right_range] = INT_MAX;

  for ( int i = 0, j = 0, k = iter_start_first ; k < iter_start_second; ++k) {
    if (left_arr[i] < right_arr[j]) {
        arr[k] = left_arr[i];
        ++i;
    } else {
        arr[k] = right_arr[j];
        ++j;
    }
  }

  free(left_arr);
  free(right_arr);
  return;
}

void sort (int * arr, int lenght, int start = 0) {
  if (start < lenght) {
      int iter = (start+lenght) /2;
      sort(arr,iter,start);
      sort(arr,lenght,start+1);
      merge(arr,start, iter, lenght);
      return;
  }
}

int main (int argc, char * argv []) {
  int lenght = argc - 1;
  int * arr = (int*) malloc (sizeof(int) * lenght);
  printf("\n source arr : \n");
  for (int i = 0; i < lenght; ++i) {
    arr[i] = atoi(argv[i+1]);
    printf(" %d", arr[i]);
  }
  printf("\n sorted array : \n");
  sort(arr, lenght);
  //merge (arr, 0,3,6);
  
  for (int i = 0; i < lenght; ++i){
    printf(" %d",arr[i]);
  }
  printf("\n");
  free (arr);
  return 0;

}