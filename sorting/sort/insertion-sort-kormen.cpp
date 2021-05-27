#include <stdlib.h>
#include <stdio.h>
/* c style */
void sort (int*arr, int lenght){
  for (int j = 1; j < lenght; ++j) {
    int key = arr[j];
    for (int i = j - 1; i >= 0 && arr[i] > key; --i) {
      arr[i+1] = arr[i];
      arr[i] = key;
    }
  }
}

int main (int argc, char * argv[]) {
  int lenght = argc -1;
  int * arr = (int *) malloc (sizeof(int) * lenght);

  printf("\n source arr : \n");
  for (int i = 0; i < lenght; ++i) {
    arr[i] = atoi(argv[i+1]);
    printf(" %d", arr[i]);
  }
  printf("\n sorted array : \n");
  sort(arr, lenght);
  for (int i = 0; i < lenght; ++i){
    printf(" %d",arr[i]);
  }
  printf("\n");
  free (arr);
  return 0;
}
