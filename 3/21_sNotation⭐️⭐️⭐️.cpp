/*习题P69科学计数法
+3.1415E+004
-3.1415926E+4
+3.1415926E-01
-3.1415926E-0005
*/
#include <cstdio>
#include <cstring>

int main() {
  char str[10010];
  gets(str);
  int len = strlen(str);
  if(str[0] == '-') printf("-");  //如果是负数输出负号

  int pos = 0;    //pos存放字符串中E的位置
  while(str[pos] != 'E') pos++;

  int exp = 0;  //exp存放指数(不考虑正负)
  for (int i = pos + 2; i < len; i++) {
    exp = exp * 10 + (str[i] - '0');
  }
  if(exp == 0) {    //指数为0,直接输出
    for(int i = 1; i < pos; i++)
      printf("%c", str[i]);
  }
  if(str[pos + 1] == '-') {   //如果指数为负
    printf("0.");
    for(int i = 0; i < exp - 1; i++)  //输出exp-1个0
      printf("0");
    //输出除小数点以外的数字
    printf("%c", str[1]);
    for(int i = 3; i < pos; i++)
      printf("%c", str[i]);
  } else {    //如果指数为正
    for(int i = 1; i < pos; i++) {
      if(str[i] == '.') continue; //略过小数点
      printf("%c", str[i]);
      if(i == exp + 2 && pos - 3 != exp) {
        //小数点加在位置exp+2上
        //原小数点和E之间的数字个数pos-3不能等于小数点右移位数exp
        printf(".");
      }
    }
    //指数exp较大，输出多余的0
    for(int i =0; i < exp - (pos - 3); i++)
      printf("0");
  }
  return 0;
}