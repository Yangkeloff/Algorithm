// 习题P12
// 先输出n-m~n-1，再输出0~n-m-1
#include <cstdio>

int main() {
  int a[101], n, m, count = 0;
  scanf("%d%d", &n, &m);
  m = m % n;  // 保证m小于n
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = n - m; i < n; i++)
  {
    printf("%d", a[i]);
    count++;
    if (count < n)
      printf(" ");
  }
  for (int i = 0; i < n - m; i++)
  {
    printf("%d", a[i]);
    count++;
    if (count < n)
      printf(" ");
  }
  printf("\n");
  return 0;
}
