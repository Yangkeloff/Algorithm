#include <stdio.h>

int main () {
  int school[10000] = {0};
  int n;
  printf("参赛人数：");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int schId, score;
    printf("学校编号 总分：");
    scanf("%d%d", &schId, &score);
    school[schId] += score;
  }

  int k=1, maxScore = -1;
  for(int i = 1; i <= n; i++) {
    if(school[i] > maxScore) {
      maxScore = school[i];
      k = i;
    }
  }
  printf("school: %d score:%d \n", k, maxScore);
  return 0;
}