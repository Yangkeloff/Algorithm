#include <stdio.h>

int main() {
  int n, step = 0;
  printf("input n:");
  scanf("%d", &n);
  while (n != 1)
  {
    if(n % 2 == 0) n/=2;
    else n= (3 * n + 1) / 2;
    step++;
  }
  printf("\n step=%d \n", step);
  return 0;
}