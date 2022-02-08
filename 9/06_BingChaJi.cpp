#include <cstdio>

const int maxn = 10;

int father[maxn];

// 一开始，每个元素都是一个独立的集合
void init() {
  for (int i = 0; i < maxn; i++)
  {
    father[i] = i;
  }
}

// 查找：findFather查找根结点

// (递推法)
int findFather1(int x) {
  while (x != father[x])  // 若不是根结点
  {
    x = father[x];  // 获得自己的根结点
  }
  return x;
}

// (递归法)
int findFather2(int x) {
  if(x == father[x]) return x;
  else return findFather2(father[x]);
}

/* 合并：两个集合合并成一个集合。一般给出两个元素，把这两个元素所在的集合合并
1. 判断两个元素是否属于同一集合，即根结点是否为同一个
2. 得到两个根结点后，将一个结点的父结点指向另一个结点
*/
void Union(int a, int b) {
  int faA = findFather1(a), faB = findFather1(b);
  if(faA != faB) father[faA] = faB;
}

// 同一个集合中一定没有环，即并查集产生的每一个集合都是一棵树

/* 路经压缩
1.按原写法获得x的根结点r
2.重新由x出发寻找根结点，将路径上所有结点的父结点设为根结点r
*/
int findFather(int x) {
  int a = x;  // x要出发走向根结点,用a暂存初始的x
  while(x != father[x]) {
    x = father[x];
  }
  // 此时x已为根结点r,用a再从初始位置走一遍
  while(a != father[a]) {
    int z = a;  // a要走向根结点,每一步a都会被father[a]覆盖,z暂存这一步的a
    a = father[a];  // a出发直到根结点
    father[z] = x;  // ⭐️每一个结点的父结点都为根结点
  }
  return x; // 返回根结点
}