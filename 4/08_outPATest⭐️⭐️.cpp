/* 习题P136输出PATest
redlesPayBestPATTopTeePHPereatitAPPT
*/
#include <cstdio>
#include <cstring>

const int maxn = 10010;
int hashTable[6] = {0};
char dict[6] = {'P', 'A', 'T', 'e', 's', 't'};  //dict与hashtable下标对应

int main() {
  char str[maxn];
  gets(str);
  int len = strlen(str), sum = 0; //sum记录输出PATest这几个字符的总个数
  for(int i = 0; i < len; i++) {
    for(int j = 0; j < 6; j++) {
      if(str[i] == dict[j]) {
        hashTable[j]++;
        sum++;
      }
    }
  }
  while(sum > 0) {
    for(int i = 0; i < 6; i++) {
      if(hashTable[i] > 0) {
        printf("%c", dict[i]);
        hashTable[i]--;
        sum--;
      }
    }
  }
  printf("\n");
  return 0;
}