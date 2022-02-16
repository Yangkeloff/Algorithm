#include <cstdio>
#include <queue>
using namespace std;

const int maxv = 100;
const int INF = 9999999999; // ∞

int n;
bool inq[maxv] = {false};

// 邻接矩阵版
int G[maxv][maxv];

void BFS_1(int u) {
  queue<int> q;
  q.push(u);
  inq[u] = true;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v = 0; v < n; v++) {
      if(inq[v] == false && G[u][v] != INF) {
        q.push(v);
        inq[v] = true;
      }
    }
  }
} 

// 邻接表版
vector<int> Adj[maxv];

void BFS_2(int u) {
  queue<int> q;
  q.push(u);
  inq[u] = true;
  while(!q.empty()) {
    for(int i = 0; i < Adj[u].size(); i++) {  // 遍历该结点边集
      int v = Adj[u][i];
      if(inq[v] == false) {
        q.push(v);
        inq[v] = true;
      }
    }
  }
}

// 遍历所有连通分量
void BFSTrave() {
  for(int u = 0; u < n; u++) {
    if(inq[u] == false) {
      BFS_1(u);
      // BFS_2(u);
    }
  }
}