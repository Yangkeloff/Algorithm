//书p110给出n个字符串，再给出m个查询字符串，每个查询字符串在n个字符串中出现的次数
#include <cstdio>

const int maxn = 110;
char s[maxn][5], temp[5];
int hashTable[26 * 26 * 26 + 10] = {0};

int hashFunc(char s[], int len) {   //字符串转换为整数
  int id = 0;
  for(int i = 0; i < len; i++)
    id = id * 26 + (s[i] - 'A');
  return id;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    hashTable[hashFunc(s[i], 3)]++;
  }
  for(int i = 0; i < m; i++) {
    scanf("%s", temp);
    printf("%d\n", hashTable[hashFunc(temp, 3)]);
  }
  return 0;
}