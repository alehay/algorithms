#include <cstdio>
#include <cstdlib>
#include <climits>

void merge (int * arr, int const begin, int const median, int const end) {
  printf ("\n b %d ; m %d ; e %d\n",begin, median, end );
  
  printf("merge input:");
  for (int i = begin; i < end; ++i){
    printf(" %d",arr[i]);
  }
  printf("\n");
  // the left array is always less than or equal to the right one 
  if (begin == median) {
     printf ("skip: \n");
    return;
  }

  int left_range = median - begin; 
  int right_range = end - median;
  
  int * left_arr = (int*)malloc(sizeof(int) * left_range);
  int * right_arr = (int*)malloc(sizeof(int) * right_range);
  
  printf ("\n left arr: \n");
  for (int i = 0; i < left_range; ++i) {
    left_arr[i] = arr[begin + i];
  }
  
  for (int i = 0; i < left_range; ++i) {
    printf (" %d", left_arr[i]);
  }

  printf ("\n right arr: \n");
  for (int j = 0; j < right_range; ++j) {
    right_arr[j] = arr[median + j];
  }

  for (int j = 0; j < right_range; ++j) {
   printf(" %d", right_arr[j] );
  }
  
  
  for (int i=0, j=0, k = begin; k < end; ++k) {
    printf("\n left[%d] %d < right[%d] %d \n", i, left_arr[i], j , right_arr[j] );
    if (left_arr[i] < right_arr[j]) {
      arr[k] = left_arr[i++];
    } else {
      arr[k] = right_arr[j++];
    }
    // left array ended 
    if (i == left_range) {
      while (j != right_range) {
        arr[++k] = right_arr[j++];
      }
    }
    if (j == right_range) {
      while (i != left_range) {
        arr[++k] = left_arr[i++];
      }
    }
  }

  printf("\n merge result:");
  for (int i = begin; i < end; ++i){
    printf(" %d",arr[i]);
  }
  printf("\n");
  free(left_arr);
  free(right_arr);
  return;
}

void sort (int * arr, int const begin,int const end ) {

  if (begin < end) {

      int median = (begin+end) /2; printf(" \n  median %d",median );
      sort(arr,begin,median);
      sort(arr,median + 1,end);
      merge(arr,begin, median, end);
      
  }
  return;
}

int main (int argc, char * argv []) {
  int lenght = argc - 1;
  int * arr = (int*) malloc (sizeof(int) * lenght);
  printf("\n source arr : \n");
  for (int i = 0; i < lenght; ++i) {
    arr[i] = atoi(argv[i+1]);
    printf(" %d", arr[i]);
  }
  
  sort(arr, 0, lenght);
  //merge (arr, 0,lenght/2,lenght);
  //printf("\n median %d; lenght %d \n", lenght/2, lenght );

  printf("\n sorted array : \n");
  for (int i = 0; i < lenght; ++i){
    printf(" %d",arr[i]);
  }
  printf("\n");
  free (arr);
  return 0;

}