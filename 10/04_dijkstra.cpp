#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxv = 1000;
const int INF = 1000000000; // ∞

int n, d[maxv], s;
bool vis[maxv] = {false};

// 邻接矩阵
int G[maxv][maxv];
void dijkstra_1(int s) {
  fill(d, d + maxv , INF);  // 整个d数组设为∞
  d[s] = 0; // 到自身距离为0
  for(int i = 0; i < n; i++) {  // 循环n次
    int u = -1, MIN = INF;  // u使d[u]最小, MIN存放该最小的d[u]
    for(int j = 0; j < n; j++) {  // 找未访问结点中d[]最小的
      if(vis[j] == false && d[j] < MIN) {
        u = j;
        MIN = d[j];
      }
    }
    if(u == -1) return; // 找不到小于∞ ∴和起点都不连通
    vis[u] = true;
    for(int v = 0; v < n; v++) {
      if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
        d[v] = d[u] + G[u][v];
      }
    }
  }
}

// 邻接表
struct Node {
  int v, dis; // v为边的目标顶点,dis为边权
};
vector<Node> Adj[maxv];

void dijkstra_2(int s) {
  fill(d, d + maxv, INF);
  d[s] = 0;
  for(int i = 0; i < n; i++) {
    int u = -1, MIN = INF;
    for(int j = 0; j < n; j++) {
      if(vis[j] == false && d[j] < MIN) {
        u = j;
        MIN = d[j];
      }
    }
    if(u == -1) return;
    vis[u] = true;
    // 邻接表的不同仅在下面这个循环
    for(int j = 0; j < Adj[u].size(); j++) {
      int v = Adj[u][j].v;  // 邻接表可直接得到u能到达的顶点
      if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]) {
        d[v] = d[u] + Adj[u][j].dis;
      }
    }
  }
}

int main() {
  int u, v, m, w; // 弧尾, 弧头, 总边数, 边权值
  scanf("%d%d%d", &n, &m, &s);
  fill(G[0], G[0] + maxv * maxv, INF);
  for(int i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &w);  // 输入边u->v及权值
    G[u][v] = w;
  }
  dijkstra_1(s);
  for(int i = 0; i < n; i++) {
    printf("%d ", d[i]);
  }
  printf("\n");
  return 0;
}

/* 测试数据
6 8 0
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3

res: 0 1 5 3 4 6
*/