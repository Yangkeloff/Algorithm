#include <cstdio>

void insertSort(int A[], int n) {
  int i, j, temp;
  for(i = 1; i < n; i++) {
    if(A[i] < A[i - 1]) {
      temp = A[i];
      for(j = i - 1; j >=0 && temp < A[j]; j--)
        A[j + 1] = A[j];
      A[j + 1] = temp;
    }
  }
}

int main() {
  int A[5] = {9, 8, 7, 6, 5};
  insertSort(A, 5);
  for(int i = 0; i < 5; i++) {
    printf("%d ", A[i]);
    if(i==4) printf("\n");
  }
  return 0;
}