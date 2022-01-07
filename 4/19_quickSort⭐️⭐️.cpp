#include <cstdio>

int Partition(int A[], int low, int high) {
  int pivot = A[low];
  while(low < high) {
    while(A[high] >= pivot && low < high) high--;
    A[low] = A[high];
    while(A[low] <= pivot && low < high) low++;
    A[high] = A[low];
  }
  A[low] = pivot;
  return low;
}

void QuickSort(int A[], int low, int high) {
  if(low < high) {
    int pivotPos = Partition(A, low, high);
    QuickSort(A, low, pivotPos - 1);
    QuickSort(A, pivotPos + 1, high);
  }
}

int main() {
  int arr[6] = {2, 8, 7, 9, 6, 5};
  QuickSort(arr, 0, 5);
  for(int i = 0; i < 5; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}