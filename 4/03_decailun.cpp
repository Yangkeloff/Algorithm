// 习题p87德才论
#include <stdio.h>
#include <algorithm>
using namespace std;
struct student
{
  char id[10];
  int de, cai, sum;
  int flag;
}stu[10010];

bool cmp(student a, student b) {
  if(a.flag != b.flag) return a.flag < b.flag;  //类别小在前
  else if(a.sum != b.sum) return a.sum > b.sum;   //类别相同则总分大在前
  else if(a.de != b.de) return a.de > b.de;   //总分相同，德分大在前
  else return strcmp(a.id, b.id) < 0;   //德分相同，准考证小在前
}

int main() {
  int n, L, H, num = 0;
  scanf("%d%d%d", &n, &L, &H);
  for(int i = 0; i < n; i++) {
    scanf("%s%d%d", stu[i].id, &stu[i].de, &stu[i].cai);
    stu[i].sum = stu[i].de + stu[i].cai;
    if(stu[i].de < L || stu[i].cai < L) stu[i].flag = 5;
    else if (stu[i].de >= H && stu[i].cai >= H) stu[i].flag = 1;
    else if (stu[i].de >= H && stu[i].cai < H) stu[i].flag = 2;
    else if (stu[i].de >= stu[i].cai) stu[i].flag = 3;
    else stu[i].flag = 4;
    if(stu[i].flag != 5) num++;
  }
  sort(stu, stu + n, cmp);
  printf("%d\n", num);
  for(int i = 0; i < num; i++)
    printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
  return 0;
}

/*输入样例
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
*/