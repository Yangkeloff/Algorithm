#include <stdio.h>

int main() {
  int A, B, D;
  while (scanf("%d %d %d", &A, &B, &D) != EOF)
  {
    int C = A + B, z[48], num = 0;
    do
    {
      z[num++] = C % D;
      C = C / D;
    } while (C != 0);
    for (int i = num - 1; i >= 0; i--)
    {
      printf("%d", z[i]);
    }
  }
  return 0;
}