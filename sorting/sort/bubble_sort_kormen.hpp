#ifndef __BUBBLE_SORT_KORMEN_H__
#define __BUBBLE_SORT_KORMEN_H__



void bubble_sort (int *arr, const int start, const int lenght) {
    
    for (int stop = lenght; stop > start + 1 ; --stop){
      for (int i = start; i < stop - 1; ++i) {
        if (arr[i] > arr[i+1] ) {
          int temp = arr[i+1];
          arr[i+1] = arr[i];
          arr[i] = temp;
        } 
      }
    }
}
#endif // __BUBBLE_SORT_KORMEN_H__