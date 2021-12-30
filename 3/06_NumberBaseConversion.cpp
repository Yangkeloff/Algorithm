#include <stdio.h>

// P进制数转换为十进制数
void PToDeci(int &x, int p) {
  int y = 0, product = 1;
  while (x != 0)
  {
    y = y + (x % 10) * product;
    x = x / 10;
    product = product * p;
  }
  x = y;
}

// 十进制数转换为P进制数
void DeciToP(int &x, int p) {
  int z[48], num = 0;
  do
  {
    z[num++] = x % p;
    x = x / p;
  } while (x != 0);
}


int main() {
  return 0;
}