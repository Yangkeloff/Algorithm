#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100;

// 静态定义结点
struct node
{
  int data;
  vector<int> child;
} Node[maxn];

int nodeIndex = 0;

int newNode(int x) {
  Node[nodeIndex].data = x;
  Node[nodeIndex].child.clear();  // 清空子结点 clear():清空vector中所有元素
  return nodeIndex++;
}

// 树的先根遍历
void preOrder(int root) {
  printf("%d", Node[root].data);
  for(int i = 0; i < Node[root].child.size(); i++) {
    preOrder(Node[root].child[i]);  // 递归访问root的所有子结点
  }
}