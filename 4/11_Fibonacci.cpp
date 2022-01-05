#include <cstdio>

int Fib(int n) {
  if(n == 0 || n == 1) return 1;
  else return Fib(n - 1) + Fib(n - 2);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", Fib(n));
  return 0;
}