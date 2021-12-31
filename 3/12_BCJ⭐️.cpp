// 习题P16～17
// 注意到B,C,J是字典序且刚好是相克关系

#include <cstdio>

int change(char c) {
  if(c == 'B') return 0;
  if(c == 'C') return 1;
  if(c == 'J') return 2;
  return -1;
}

int main () {
  int mp[3] = {'B', 'C', 'J'};
  int n;
  scanf("%d", &n);
  int resA[3] = {0}, resB[3] = {0}, handA[3] = {0}, handB[3] = {0}, k1, k2;
  char ca, cb;
  for (int i = 0; i < n; i++)
  {
    getchar();
    scanf("%c %c", &ca, &cb);
    k1 = change(ca);
    k2 = change(cb);
    if((k1 + 1) % 3 == k2) {  // 甲赢
      resA[0]++;
      resB[2]++;
      handA[k1]++;
    } else if (k1 == k2) {  // 平
      resA[1]++;
      resB[1]++;
    } else {    // 乙赢
      resB[0]++;
      resA[2]++;
      handB[k2]++;
    }
  }
  for (int i = 0; i < 3; i++) printf("%d ", resA[i]);
  printf("\n");
  for (int i = 0; i < 3; i++) printf("%d ", resB[i]);
  printf("\n");
  int id1 = 0, id2 = 0;
  for (int i = 0; i < 3; i++)
    if (handA[i] > handA[id1]) id1 = i;
  for (int i = 0; i < 3; i++)
    if (handA[i] > handA[id2]) id2 = i;
  printf("%c %c\n", mp[id1], mp[id2]);

  return 0;
}