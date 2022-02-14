#include <cstdio>
#include <vector>
using namespace std;

// 邻接矩阵版
const int maxv = 1000;  // 最大顶点数
const int INFINITE = 999999999999;  // ∞

int n, G[maxv][maxv]; // 顶点数,邻接矩阵
bool visit[maxv] = {false}; // 顶点是否被访问

void DFS_1(int u, int depth) {
  visit[u] = true;  // 设置u已被访问
  // 枚举u出发所有能到达的顶点
  for(int v = 0; v < n; v ++) {
    // v未被访问,且u可到达v
    if(visit[v] == false && G[u][v] != INFINITE) {
      DFS_1(v, depth + 1);  // 访问v，深度+1
    }
  }
}

// 邻接表版

vector<int> Adj[maxv];

void DFS_2(int u, int depth) {
  visit[u] = true;
  // 枚举u出发所有能到达的顶点
  for(int i = 0; i < Adj[u].size(); i++) {
    int v = Adj[u][i];
    if(visit[v] == false) {
      DFS_2(v, depth + 1);
    }
  }
}

// 访问每个连通分量
void DFSTrave() {
  for(int u = 0; u < n; u++) {
    if(visit[u] == false) {
      DFS_1(u, 1);
      // DFS_2(u, 1);
    }
  }
}