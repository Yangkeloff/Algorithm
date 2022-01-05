/*习题p143继续(3n+1)猜想
6
3 5 6 7 8 11
*/
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
  return a > b;
}

bool hashTable[10000] = {false};

int main() {
  int k, n, a[110];
  scanf("%d", &k);
  for(int i = 0; i < k; i++) {
    scanf("%d", &a[i]);
    n = a[i];
    while(n != 1) {
      if(n % 2 == 0) n /= 2;
      else n = (3 * n + 1) / 2;
      hashTable[n] = true;
    }
  }
  int count = 0;
  for(int i = 0; i < k; i++) {
    if(hashTable[a[i]] == false)
      count++;
  }
  sort(a, a + k, cmp);
  for(int i = 0; i < k; i++) {
    if(hashTable[a[i]] == false) {
      printf("%d", a[i]);
      count--;
      if(count > 0) printf(" ");
    }
  }
  printf("\n");
  return 0;
}