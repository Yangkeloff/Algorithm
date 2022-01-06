//二路归并(递归)
#include <cstdio>
const int maxn = 100;

//将A[l1,h1]与[l2,h2]区间合并为有序区间
void Merge(int A[], int l1, int h1, int l2, int h2) {
  int i = l1, j = l2;
  int temp[maxn], index = 0;  //index为temp下标
  while(i <= h1 && j <=h2) {  //左右子表选最小加入temp
    if(A[i] <= A[j]) {
      temp[index++] = A[i++];
    } else {
      temp[index++] = A[j++];
    }
  }
  while(i <= h1) temp[index++] = A[i++];
  while(j <= h2) temp[index++] = A[j++];
  for(int i = 0; i < index; i++) {
    A[l1 + i] = temp[i];
  }
}

void mergeSort(int A[], int low, int high) {
  if(low < high) {
    int mid = (low + high) / 2;
    mergeSort(A, low, mid);   //递归,左区间[low,mid]归并排序
    mergeSort(A, mid + 1, high);  //递归,右区间[mid+1,high]归并排序
    Merge(A, low, mid, mid + 1, high);  //左子区间与右子区间合并
  }
}

int main() {
  int arr[8] = {9, 8, 1, 3, 7, 6, 2, 0};
  mergeSort(arr, 0, 7);
  for(int i = 0; i < 8; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}