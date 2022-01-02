// 习题P60个位数统计
#include <cstdio>
#include <cstring>

int main() {
  char str[1010];
  gets(str);
  int len = strlen(str), count[10] = {0};
  for (int i = 0; i < len; i++)
  {
    count[str[i] - '0']++;
    // char变量c为'0'~'9'的一个字符，则c对应的数字为c-'0'
    // 即把'0'对应到0，'1'对应到1以此类推
  }
  for (int i = 0; i < 10; i++)
  {
    if (count[i] != 0)
    {
      printf("%d:%d\n", i, count[i]);
    }
  }
  return 0;
}