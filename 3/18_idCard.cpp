/* 习题p61查验身份证
输入样例1
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输入样例2
2
320124198808240056
110108196711301862  */

#include <cstdio>
#include <cstring>

int weigh[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};  // 权重
char change[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};  // 校验码
int main() {
  int n;
  scanf("%d", &n);
  bool flag = true;
  char str[20];
  for (int i = 0; i < n; i++)
  {
    scanf("%s", str);
    int j, sum = 0;
    for (j = 0; j < 17; j++)
    {
      if (!(str[j] >= '0' && str[j] <='9')) break; // 输入中有非数字
      sum = sum + (str[j] - '0') * weigh[j];
    }
    if (j < 17)   // 有非数字
    {
      flag = false;
      printf("%s\n", str);
    } else {
      if (str[17] != change[sum % 11])  // 校验码不等于身份证号最后一位
      {
        flag = false;
        printf("%s\n", str);
      }
    }
  }
  if (flag == true)
  {
    printf("All passed\n");
  }
  
  return 0;
}