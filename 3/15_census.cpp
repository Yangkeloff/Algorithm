// 习题P32~34人口普查
/* 输入样例
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
*/
#include <cstdio>

struct person
{
  char name[15];
  int yy, mm, dd;
}youngest, oldest, left, right, temp;

bool lessEqu(person a, person b) {
  if(a.yy != b.yy) return a.yy <= b.yy;
  else if(a.mm != b.mm) return a.mm <= b.mm;
  else return a.dd <= b.dd;
}

bool moreEqu(person a, person b) {
  if(a.yy != b.yy) return a.yy >= b.yy;
  else if(a.mm != b.mm) return a.mm >= b.mm;
  else return a.dd >= b.dd;
}

void init() {
  left.yy = 1814, left.mm = 9, left.dd = 6;
  right.yy = 2014, right.mm = 9, right.dd = 6;
  youngest.yy = 1814, youngest.mm = 9, youngest.dd = 6;
  oldest.yy = 2014, oldest.mm = 9, oldest.dd = 6;
}

int main() {
  init();
  int n, num = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
    if (moreEqu(temp, left) && lessEqu(temp, right))
    {
      num++;
      if (moreEqu(temp, youngest)) youngest = temp;
      if (lessEqu(temp, oldest)) oldest = temp;
    }
  }
  if(num == 0) printf("0\n");
  else printf("%d %s %s\n", num, oldest.name, youngest.name);
  return 0;
}