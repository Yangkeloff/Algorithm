/*书P121组个最小数
2 2 0 0 0 3 0 0 1 0
*/
#include <cstdio>

int count[10] = {0};  //0~9每个整数的个数

int main() {
  for(int i = 0; i < 10; i++) {
    scanf("%d", &count[i]);
  }
  for(int i = 1; i < 10; i++) { //输出不为0最小的数做首位
    if(count[i] > 0) {  
      printf("%d", i);
      count[i]--;
      break;  //输出首位就跳出
    }
  }
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < count[i]; j++){
      printf("%d", i);
    }
  }
  printf("\n");
  return 0;
}