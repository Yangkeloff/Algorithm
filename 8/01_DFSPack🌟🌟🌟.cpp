/* 书P271
有n件物品,每件物品重量为w[i],价值为c[i]
现在需要选出若干件物品放入容量为V的背包，使物品重量总和不超过V时背包物品总价值最大
求最大价值(1<=n<=20)
*/
#include <cstdio>

const int maxn = 30;
int n, V, maxValue = 0; // 物品件数，背包容量，最大总价值
int w[maxn], c[maxn];   // 物品重量，物品价值

// index为当前处理物品编号,sumW为当前重量,sumC为当前总价值
void DFS(int index, int sumW, int sumC) {
  if(index == n) {
    return;   // 已经完成对n件物品的选择
  }
  DFS(index + 1, sumW, sumC); // 不选择index号物品
  if(sumW + w[index] <= V) { // 只有加入index号物品还不超重才继续
    if(sumC + c[index] > maxValue) {
      maxValue = sumC + c[index];   // 更新最大价值
    }
    DFS(index + 1, sumW + w[index], sumC + c[index]);   // 加入index号物品
  }
}

int main() {
  scanf("%d%d", &n, &V);
  for(int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  DFS(0, 0, 0);  // 从0号物品开始，初始重量、总价值为0
  printf("%d\n", maxValue);
  return 0;
}
/*
5 8
3 5 1 2 2
4 5 2 1 3

结果为10
*/