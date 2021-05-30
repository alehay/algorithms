#include <cstdio>
#include <cstdlib>
#include <climits>

void merge (int * arr, int begin, int median, int end) {
  int left_range = median - begin; 
  int right_range = end - median;
  int * left_arr = (int*)malloc(sizeof(int)*(left_range + 1));
  int * right_arr = (int*)malloc(sizeof(int)*(right_range + 1));

  for (int i = 0; i < left_range ; ++i) {
    left_arr[i] = arr[begin + i]; 
  } 
  left_arr[left_range] = INT_MAX;

  for (int j = 0; j < right_range; ++j) {
    right_arr[j] = arr[median + j];
  }
  right_arr[right_range] = INT_MAX;

  for ( int i = 0, j = 0, k = begin ; k < end; ++k) {
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

void sort (int * arr, int begin,int end ) {
  if (begin < end) {
      int median = (begin+end) /2;
      sort(arr,begin,median);
      sort(arr,median+1,end);
      merge(arr,begin, median, end);
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
  sort(arr, 0, lenght);
  //merge (arr, 0,lenght/2,lenght);
  
  for (int i = 0; i < lenght; ++i){
    printf(" %d",arr[i]);
  }
  printf("\n");
  free (arr);
  return 0;

}