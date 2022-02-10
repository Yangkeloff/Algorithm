#include <cstdio>

/* A[]为递增序列,x为欲查询元素
返回第一个【大于等于】x元素的位置 
二分上下界为[left, right],传入的初值为[0,n]🌟
欲查询元素可能比序列中所有元素都大 ∴上界为n而不是n-1,即假设x存在应所在的位置
 */
int lower_bound(int A[], int left, int right, int x) {
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(A[mid] >= x) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

/* 返回第一个【大于】x元素的位置
若中间元素大于x,则第一个大于x元素位置为[left,mid]
若中间元素小于等于x,则第一个大于x的位置为[mid+1, right]
*/
int upper_bound(int A[], int left, int right, int x) {
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(A[mid] > x) {
      right = mid;
    } else {  // 中间元素小于等于x
      left = mid + 1;
    }
  }
  return left;
}