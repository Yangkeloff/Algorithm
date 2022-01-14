#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
  map<char, int> mp;  // 映射前类型char,映射后类型int
  mp['c'] = 3;
  printf("%d\n", mp['c']);
  
  mp['a'] = 1;
  mp['b'] = 2;
  for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    printf("%c %d\n", it -> first, it -> second);   // first为key, second为value
  }
  /*
  find(key), erase(it), erase(key), erase(first, last), size(), clear()
  */

  // map头文件包含utility
  pair<string, int> p1("haha", 5);
  cout << p1.first << " " << p1.second << endl;
  p1 = make_pair("heihei", 55);
  cout << p1.first << " " << p1.second << endl;
  return 0;
}