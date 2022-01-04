#include <cstdio>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void selectSort(int A[], int n) {
  int min;
  for(int i = 0; i < n; i++) {
    min = i;
    for(int j = i; j < n; j++) {
      if(A[j] < A[min]) {
        min = j;
      }
      if(min != i) swap(A[i], A[min]);
    }
  }
}

int main() {
  int A[5] = {9, 8, 7, 6, 5};
  selectSort(A, 5);
  for(int i = 0; i < 5; i++) {
    printf("%d ", A[i]);
    if(i==4) printf("\n");
  }
  return 0;
}