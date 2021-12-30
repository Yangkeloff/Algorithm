#include <stdio.h>

int main() {
  int n;
  printf("数据个数：");
  scanf("%d", &n);
  int num[n];
  for (int i = 0; i < n; i++)
  {
    printf("输入元素：");
    scanf("%d", &num[i]);
  }
  int x, k = -1;
  printf("输入x：");
  scanf("%d", &x);
  for (int i = 0; i < n; i++)
  {
    if (x == num[i]) {
      k = i;
      break;
    };
  }
  printf("%d \n", k);
  return 0;
}