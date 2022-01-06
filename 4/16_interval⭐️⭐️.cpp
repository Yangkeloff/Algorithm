/* 书P122区间贪心,不相交区间个数
(1,3),(2,4),(3,5),(6,7) */
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;

struct Interval{
  int x, y;  //开区间左右端点
}I[maxn];

bool cmp(Interval I1, Interval I2) {
  if(I1.x != I2.x) return I1.x > I2.x;  //先左端点由大到小排列
  else return I1.y < I2.y;  //左端点相同，则右端点由小到大排列
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &I[i].x, &I[i].y);
  }
  sort(I, I + n, cmp);
  int count = 1;  //不相交区间个数,最小为1
  int lastX = I[0].x; //上一个区间的左端点
  for(int i = 1; i < n; i++) {  //初始记录左端点为I[0].x，所以循环检查是否相交从I[1]开始
    if(I[i].y <= lastX) { //判断当前区间右端点是否与上一个区间左端点相交
      count++;
      lastX = I[i].x; //更新左端点以进行下次判断
    }
  }
  printf("%d\n", count);
  return 0;
}