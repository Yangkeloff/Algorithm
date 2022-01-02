//习题P63写出这个数
#include <cstdio>
#include <cstring>

int main() {
  char str[110];
  gets(str);
  int len = strlen(str), sum = 0;
  for (int i = 0; i < len; i++)
  {
    sum = sum + str[i] - '0';   // 每一位累加
  }
  int num = 0, ans[10];   // num表示sum的位数
  while (sum != 0)
  { // sum每一位存入数组，sum低位存到ans[]低位
    ans[num] = sum % 10;
    num++;
    sum = sum / 10;
  }
  char change[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
  for (int i = num - 1; i >= 0; i--)
  { // 从高位开始输出
    printf("%s", change[ans[i]]);
    if (i != 0) printf(" ");
    else printf("\n");
  }
  
  return 0;
}