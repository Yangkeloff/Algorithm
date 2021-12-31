#include <stdio.h>
#include <string.h>

int main() {
  int a[3][3], b[3][3];
  
  memset(a, -1, sizeof(a)); // memset()需要头文件string.h
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) {
      printf("input a[%d][%d]:", i, j);
      scanf("%d", &a[i][j]);
    }
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) {
      printf("input b[%d][%d]:", i, j);
      scanf("%d", &b[i][j]);
    }

  int c[3][3];
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}