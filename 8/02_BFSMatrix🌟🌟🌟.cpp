// 书P276 求给定矩阵中的“块”的个数
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;

// 矩阵结点坐标x,y
struct node{
  int x;
  int y;
} Node;

int n, m; // n*m矩阵
int matrix[maxn][maxn];
bool intq[maxn][maxn] = {false};  // 位置(x,y)是否已访问过
/* 
位置(x,y)的4个相邻位置为
(x,y+1),(x,y-1),(x+1,y),(x-1,y)
*/
int addX[4] = {0, 0, 1, -1};
int addY[4] = {1, -1, 0, 0};

// 判断位置(x,y)是否需要访问
bool judge(int x, int y) {
  if(x < 0 || x >= n || y < 0 || y >=m) return false; // 越界情况
  if(matrix[x][y] == 0 || intq[x][y] == true) return false; // 位置(x,y)值为0或已访问过
  return true;
}

// 访问位置(x,y)所在的块，将该块中所有值为1的intq设为true
void BFS(int x, int y) {
  queue<node> Q;  // 初始化队列
  Node.x = x;
  Node.y = y;
  Q.push(Node); // 第一个结点入队
  intq[x][y] = true;  // 访问第一个结点
  while(!Q.empty()) { // 队列不空则循环
    node top = Q.front(); // 取出队首元素
    Q.pop();  // 队首元素出队
    for(int i = 0; i < 4; i++) {  // 访问元素4个相邻位置
      int newX = top.x + addX[i];
      int newY = top.y + addY[i];
      if(judge(newX, newY)) { // 若新位置(newX, newY)需要访问
        Node.x = newX;
        Node.y = newY;
        intq[newX][newY] = true;
      }
    }
  }
}


int main() {
  scanf("%d%d", &n, &m);
  for(int x = 0; x < n; x++) {
    for(int y = 0; y < m; y++) {
      scanf("%d", &matrix[x][y]); // 读入01矩阵
    }
  }
  int ans = 0;  // 块数
  for(int x = 0; x < n; x++) {
    for(int y = 0; y < m; y++) {
      // 如果元素为1，且未入过队
      if(matrix[x][y] == 1 && intq[x][y] == false) {
        ans++;
        BFS(x,y); // 访问整个块
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}