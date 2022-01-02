// 习题P59换个格式输出整数
#include <cstdio>

int main() {
  int n, ans[5], m=0;   // m为n的位数
  scanf("%d", &n);
  while (n != 0)
  {
    // printf("n=%d m=%d\n", n, m);
    ans[m] = n % 10;
    m++;
    n = n / 10;
  }
  for(int i = m - 1; i >= 0; i--) {   // 从高位到低位枚举
    if(i == 2)
      for(int j = 0; j < ans[i]; j++) printf("B");
    else if(i == 1)
      for(int j = 0; j < ans[i]; j++) printf("S");
    else 
    for(int j = 1; j <= ans[i]; j++) printf("%d", j);
  }
  printf("\n");
  return 0;
}