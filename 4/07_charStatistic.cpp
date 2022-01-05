/*习题P135字符统计
This is a simple TEST.  There ARE numbers and other symbols 1&2&3
*/
#include <cstdio>
#include <cstring>

const int maxn = 1010;
int hashTable[30] = {0};
int main() {
  char str[maxn];
  gets(str);
  int len = strlen(str);
  for(int i = 0; i < len; i++) {
    if(str[i] >= 'a' && str[i] <= 'z') {
      hashTable[str[i] - 'a']++;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      hashTable[str[i] - 'A']++;
    }
  }
  int k = 0;  //记录数组中最大元素下标
  for(int i = 0; i < 26; i++) {
    if(hashTable[i] > hashTable[k]) k = i;
  }
  printf("%c %d\n", k + 'a', hashTable[k]);
  return 0;
}