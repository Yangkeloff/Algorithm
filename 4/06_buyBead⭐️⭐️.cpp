/*习题P133到底买不买
输入样例1
ppRYYGrrYBR2258
YrR8RrY
输入样例2
ppRYYGrrYB225
YrR8RrY */
#include <cstdio>
#include <cstring>
const int maxn = 1010;
int hashTable[62] = {0}, miss = 0;

int hashFunc(char c) {
  if(c >= '0' && c <= '9') return c - '0';
  if (c >= 'a' && c <= 'z') return c - 'a' + 10;
  if (c >= 'A' && c >= 'Z') return c - 'A' + 36;
}

int main() {
  char bead[maxn], target[maxn];
  gets(bead); gets(target);
  int len1 = strlen(bead), len2 = strlen(target);
  for(int i = 0; i < len1; i++) {
    hashTable[hashFunc(bead[i])] ++;
  }
  for(int i = 0; i < len2; i++) {
    int id = hashFunc(target[i]);
    hashTable[id]--;
    if(hashTable[id] < 0) miss++;
  }
  if(miss > 0) printf("No %d\n", miss);
  else printf("Yes %d\n", len1 - len2);
  return 0;
}