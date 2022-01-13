#include <cstdio>
#include <iostream>
#include <string> // 注意区分<string>和<string.h>是不同的头文件
using namespace std;

string str = "abcd";

int main() {
  // 可像字符数组一样访问string
  for(int i = 0; i < str.length(); i++) {
    printf("%c", str[i]);
  }
  printf("\n");

  // 读入和输出整个字符串,❗️只能用cin和cout❗️
  string str2;
  cin >> str2;
  cout << "str2:" << str2 << endl;

  // printf输出string
  printf("printf输出str:%s\n", str.c_str());  //c_str()使str变为字符数组

  // 通过迭代器访问
  cout << "iterator str:";
  for(string::iterator it = str.begin(); it != str.end(); it++) {
    printf("%c", *it);
  }
  cout << endl;

  string str3 = str + str2;  // str与str2拼接赋值给str3
  str += str2;  // str2直接拼接到str上
  cout << "str3:" << str3 << endl;
  cout << "str:" << str << endl;

  string s1 = "Thank you for your smile;", s2 = "you", s3 = "me";
  if(s1.find(s2) != string::npos) {   // string::npos为find()失配时的返回值
    cout << s1.find(s2) << endl;
  }
  if(s1.find(s2, 7) != string::npos) {   // find(x, pos)表示从pos号位开始匹配x
    cout << s1.find(s2, 7) << endl;
  }
  if(s1.find(s3) != string::npos) {
    cout << s1.find(s3) << endl;
  } else {
    cout << "I know there is no position for me" << endl;
  }
  return 0;
}