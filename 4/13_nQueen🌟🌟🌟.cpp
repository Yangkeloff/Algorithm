#include <cstdio>
const int N = 10;
int n, count = 0;
int a[N]; // a[i]表示第i行上皇后放在a[i]列

bool check(int row, int col) {  //判断第row行可否将皇后放在第col列上
  for(int i = 1; i <= row; i++) {
    if(a[i] == col) return false;  //col列上有皇后，不可放
    if(i + a[i] == row + col) return false;  //上对角线
    if(i - a[i] == row - col) return false;   //下对角线
  }
  return true;
}

void DFS(int row) {
  if(row == n + 1) {  //递归边界，产生一组解
    count++;
    return;
  }
  for(int i = 1; i <= n; i++){
    if(check(row, i)){
      a[row] = i;   //皇后放在第row行第i列
      DFS(row + 1);   //处理下一行
      a[row] = 0;   //回溯需清零给下一层递归用
    }
  }
}

int main() {
  scanf("%d", &n);
  DFS(1);
  printf("%d\n", count);
  return 0;
}