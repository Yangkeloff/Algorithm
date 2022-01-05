/* 习题P138编程团体赛 
🌟由于队伍编号是1～1000任意数，需要hash数组记录总分，而不能边输入边求最大值
*/
#include <cstdio>

const int maxn = 1010;
int hashTable[maxn] = {0};

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int teamId, teamMember, score;
    scanf("%d-%d %d", &teamId, &teamMember, &score);
    hashTable[teamId] += score;
  }
  int k = 0;
  for(int i = 0; i < maxn; i++) {
    if(hashTable[i] > hashTable[k]) k = i;
  }
  printf("%d %d\n", k, hashTable[k]);
  return 0;
}
/*
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-1 61
*/