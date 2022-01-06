#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];

// 在[i+1, n-1]范围内查找第一个大于x的数的位置
int binarySearch(int i, long long x) {
  if(a[n - 1] <= x) return n; //若所有数都不大于x，返回n
  int l = i + 1, h = n - 1, mid;
  while(l < h) {
    mid = (l + h) / 2;
    if(x >= a[mid]) l = mid + 1;
    else h = mid;
  }
  return l;
}

int main() {
  scanf("%d%d", &n, &p);
  for(int i = 0; i < n; i++)
   scanf("%d", &a[i]);
  sort(a, a + n);
  int ans = 1;  //最大长度，初值为1(表示至少有一个数)
  for(int i = 0; i < n; i++) {
    //在a[i+1]～a[n-1]中查找第一个超过a[i]*p的数,返回其位置j
    int j = binarySearch(i, (long long)a[i] * p);
    ans = max(ans, j - i);
  }
  printf("%d\n", ans);
  return 0;
}