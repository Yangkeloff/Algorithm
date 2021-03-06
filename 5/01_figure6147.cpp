#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
  return a > b;
}

void to_array(int n, int num[]) {
  for(int i = 0; i < 4; i++) {
    num[i] = n % 10;
    n = n / 10;
  }
}

int to_number(int num[]) {
  int sum = 0;
  for(int i = 0; i < 4; i++) {
    sum = sum * 10 + num[i];
  }
  return sum;
}

int main() {
  int n, num[4], min, max;
  scanf("%d", &n);
  while(1) {
    to_array(n, num);
    sort(num, num + 4);
    min = to_number(num);
    sort(num, num + 4, cmp);
    max = to_number(num);
    n = max - min;
    printf("%04d-%04d=%04d\n", max, min, n);
    if(n == 0 || n == 6174) break;
  }
  return 0;
}