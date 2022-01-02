#include <cstdio>

int main() {
  int a[1010] = {0};
  int k, e, count = 0; // k为底数，e为指数，count为求导后非零个数
  while (scanf("%d%d", &k, &e) != EOF)
  {
    a[e] = k;
  }
  a[0] = 0;
  for (int i = 1; i <= 1000; i++)
  {
    a[i - 1] = i * a[i];
    a[i] = 0;   // 求导后，当前系数清空
    if (a[i - 1] != 0) count++;   // count计数不为零的导数项个数
  }
  if (count == 0)
  {
    printf("0 0");
  } else {
    for (int i = 1000; i >= 0; i--) {
      if (a[i] != 0)
      {
        printf("%d %d", a[i], i);
        count--;
        if(count != 0) printf(" ");
      }
    }
  }
    
  printf("\n");
  
  return 0;
}