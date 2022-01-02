#include <cstdio>
#include <cstring>

int main() {
  char str[90];
  gets(str);
  int len = strlen(str);

  char ans[90][90]; // ans[0]~ans[r]存放单词
  int r=0, h=0; // r为行，h为列
  for (int i = 0; i < len; i++)
  {
    if(str[i] != ' ') {
      ans[r][h++] = str[i];
    } else {  // 若是空格，该行结束，行r加1，列恢复到0
      ans[r][h] = '\0';   // 字符数组行尾结束符\0
      r++;
      h = 0;
    }
  }

  for (int i = r; i >= 0; i--)  // 倒着输出
  {
    printf("%s", ans[i]);
    if(i > 0) printf(" ");
    else printf("\n");
  }

  return 0;
}