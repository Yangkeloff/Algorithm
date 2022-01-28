#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

class Box {
  public:
    double length;
    double breadth;
    double height;

    // 带参数的构造函数
    Box(string str) {
      cout << str << endl;
    }

    // 成员函数声明
    double get(void);
    void set(double len, double bre, double hei);

    double getVol() {
      return length * breadth * height;
    }
};

// 成员函数定义
double Box::get() {
  return length * breadth * height;
}
void Box::set(double len, double bre, double hei) {
  length = len;
  breadth = bre;
  height = hei;
}

int main() {
  Box box1("构造函数执行");
  double vol = 0; // 体积

  box1.length = 2.0;
  box1.breadth = 3.0;
  box1.height = 4.0;

  vol = box1.getVol();

  cout << vol << endl;

  return 0;
}