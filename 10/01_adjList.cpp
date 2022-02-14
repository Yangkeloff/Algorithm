#include <cstdio>
#include <vector>
using namespace std;

const int N = 5;  // N为顶点数

struct arcNode {
  int v, w; // 结点编号, 权值
  arcNode(int _v, int _w) : v(_v), w(_w) {};
};

vector<arcNode> Adj[N]; // 用vector实现邻接表比链表更简单

// 添加从rear结点到v结点的有向边,权值为w
void addArc(int rear, int v, int w) {
  Adj[rear].push_back(arcNode(v, w));
}

int main() {
  return 0;
}
