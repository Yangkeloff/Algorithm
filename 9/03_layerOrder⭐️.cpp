#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 100;

struct node
{
  int layer;  // 记录层数
  int data;
  vector<int> child;
}Node[maxn];

void layerOrder(int root) {
  queue<int> Q;
  Node[root].layer = 1; // 根结点层数记为1
  Q.push(root);
  while (!Q.empty())
  {
    int front = Q.front();
    printf("%d", Node[front].data);
    Q.pop();
    for (int i = 0; i < Node[front].child.size(); i++)
    {
      int child = Node[front].child[i]; // 当前结点第i个子结点的编号
      Node[child].layer = Node[front].layer + 1;  // 子结点层号为当前结点层号+1
      Q.push(child);
    }
  }
  
}
