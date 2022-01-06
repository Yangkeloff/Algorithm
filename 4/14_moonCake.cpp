/*书P118～120月饼
3 20
18 15 10
75 72 45
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct moonCake {
  double store; //库存
  double amount;  //总价
  double price; //单价
}moon[1010];

bool cmp(moonCake a, moonCake b) {  //单价从高到低排序
  return a.price > b.price;
}

int main() {
  int n, D;   //n为种类数，D为总需求量
  scanf("%d%d", &n, &D);
  for(int i = 0; i < n; i++)
    scanf("%lf", &moon[i].store);
  for(int i = 0; i < n; i++) {
    scanf("%lf", &moon[i].amount);
    moon[i].price = moon[i].amount / moon[i].store;
  }
  sort(moon, moon + n, cmp);
  double earnings = 0;  //收益
  for(int i = 0; i < n; i++) {
    if(moon[i].store < D) {  //单价最高月饼不足满足全部需求量
      D -= moon[i].store;
      earnings += moon[i].amount;
    } else {
      earnings += moon[i].price * D;
      break;
    }
  }
  printf("%.2f\n", earnings);
  return 0;
}