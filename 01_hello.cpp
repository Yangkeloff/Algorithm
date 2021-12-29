#include <cstdio>
#include <math.h>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void my_sscan() {
  char str[10] = "123";
  int n;
  sscanf(str, "%d", &n);  // 左→右,把str内容以%d格式写入n
  printf("sscanf output:n=%d\n", n);
  
  char str2[100] = "1024 : 3.14 , hello", str3[10];
  int m;
  double db;
  sscanf(str2, "%d : %lf , %s", &m, &db, str3);
  printf("sscanf: m=%d db=%.2f str3=%s", n, db, str3);
}

void my_sprint() {
  int n = 233;
  char str[10];
  sprintf(str, "%d", n);  // 左←右,把n内容以%d格式写入str
  printf("sprintf output:str=%s\n", str);

  int m = 996;
  char str2[15] = "inevitable", str3[100];
  double pi = 3.1415926;
  sprintf(str3, "suffering is %s, just like %d. pi = %.2f", str2, m, pi);
  printf("SPRINTF: %s\n", str3);
}

void BubbleSort(int A[], int n) {
  my_sscan();
  my_sprint();
  int i,j;
  for(i = 0; i < 8; i++){
    bool flag = false;
    for(j = n - 1; j > i; j--) {
      if(A[j - 1] > A[j]) {
        swap(A[j - 1], A[j]);
        flag = true;
      }
    }
    if (flag == false) return;
  }
}

int main(){
  int A[10] = {8, 6, 3, 1, 7, 4, 5, 2, 0};
  BubbleSort(A, 9);
  for(int i=0; i < 9; i++) printf("A[%d]=%d\t", i, A[i]);
  return 0;
}