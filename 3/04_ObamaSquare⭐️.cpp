#include <stdio.h>
#include <math.h>

// 输入格式：在一行中给出正方形边长N(3<=N<=20)和组成正方形的某种字符C，间隔一个空格
// 由给定字符C画出正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，所输出的行数实际上是列数的50%

int main() {
  int row, col;
  char c;
  scanf("%d %c", &col, &c);
  row = ceil(col/2);
  for (int i = 0; i < col; i++)
    printf("%c", c);
  printf("\n");
  for (int i = 2; i < row; i++)
  {
    printf("%c", c);
    for(int j = 0; j < col - 2; j++)
      printf(" ");
    printf("%c\n", c);
  }
  for (int i = 0; i < col; i++)
    printf("%c", c);
  printf("\n");
  return 0;
}