/*习题P71数字加密
1234567 368782971
*/
#include <cstdio>
#include <cstring>
const int maxn = 110;
char A[maxn], B[maxn], ans[maxn] = {0};

void reverse(char s[]) {
  int len = strlen(s);
  for(int i = 0; i < len / 2; i++) {
    char temp = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = temp;
  }
}

int main() {
  scanf("%s %s", A, B);
  // 反转后，字符串的最低位就是原整数的个位
  reverse(A);
  reverse(B);
  int len1 = strlen(A), len2 = strlen(B);
  int len = len1 > len2 ? len1 : len2;
  for(int i = 0; i < len; i++) {
    int numA = i < len1 ? A[i] - '0' : 0;
    int numB = i < len2 ? B[i] - '0' : 0;
    if(i % 2 == 0) {  //i为偶数,即字符串奇数位(i从0开始,字符串从1开始)
      int temp = (numA + numB) % 13;
      if(temp == 10) ans[i] = 'J';
      else if(temp == 11) ans[i] = 'Q';
      else if(temp == 12) ans[i] = 'K';
      else ans[i] = temp + '0'; //0~9,int转对应char即 +'0'
    } else {  //i为奇数,即字符串偶数位
      int temp = numB - numA;
      if(temp < 0) temp += 10;
      ans[i] = temp + '0';  //int转对应char
    }
  }
  // 此时ans最低位对应整数低位故先反转再输出
  reverse(ans);
  puts(ans);
  return 0;
}