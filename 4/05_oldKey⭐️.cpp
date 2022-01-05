//习题P128旧键盘
#include <cstdio>
#include <cstring>

int main() {
  bool hashTable[128] = {false};  //ascii码128个,记录是否已输出
  char str1[100], str2[100];
  gets(str1); gets(str2);
  int len1 = strlen(str1), len2 = strlen(str2);
  for(int i = 0; i < len1; i++) {
    char c1, c2;
    int j;
    for(j = 0; j < len2; j++) {
      c1 = str1[i], c2 = str2[j];
      if(c1 >= 'a' && c1 <= 'z') c1 -= 32;   //若为小写字母，转为大写
      if(c2 >= 'a' && c2 <= 'z') c2 -= 32;
      if(c1 == c2) break;   //c1在str2中出现跳出循环
    }
    if(j == len2 && hashTable[c1] == false) {   //c1在str2未出现，且c1未被输出过
      printf("%c", c1);
      hashTable[c1] = true;
    }
  }
  printf("\n");
  return 0;
}