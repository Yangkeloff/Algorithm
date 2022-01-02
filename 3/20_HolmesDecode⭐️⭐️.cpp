/* 
习题P66福尔摩斯的约会
输入样例
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
*/
#include <cstdio>
#include <cstring>

char week[8][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
  char str1[70], str2[70], str3[70], str4[70];
  gets(str1);
  gets(str2);
  gets(str3);
  gets(str4);
  int len1 = strlen(str1), len2 = strlen(str2), len3 = strlen(str3), len4 = strlen(str4);
  int i;
  for (i = 0; i < len1 && i < len2; i++)
  {
    if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G') //周一到周日只有A～G
    {
      printf("%s ", week[str1[i] - 'A']);
      break;
    }
  }
  for (i++; i < len1 && i < len2; i++)  // i在上一个结束基础上向后
  {
    if (str1[i] == str2[i])   // 输出小时,0～9直接输出,A~N转化为10~24
    {
      if (str1[i] >= '0' && str1[i] <= '9') printf("%02d:", str1[i] - '0');
      else if(str1[i] >= 'A' && str1[i] <= 'N') printf("%02d:", str1[i] - 'A' + 10);
    }
  }
  for (int i = 0; i < len3 && i < len4; i++)
  {
    if (str3[i] == str4[i] && 
    ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z')))
    {
      printf("%02d\n", i);
    }
  }
  return 0;
}