// 实战p8
#include <cstdio>

int main() {
  long long a, b, Da, Db;
  scanf("%lld%lld%lld%lld", &a, &Da, &b, &Db);
  long long Pa = 0, Pb = 0;
  while (a != 0)  // 枚举a的每一位
  {
    if(a % 10 == Da) Pa = Pa * 10 + Da; // 如果当前位为Da，给pa增加一位Da
    a = a / 10;
  }
  while (b != 0)
  {
    if(b % 10 == Db) Pb = Pb * 10 + Db;
    b = b / 10; 
  }
  printf("%lld\n", Pa + Pb);

  return 0;
}