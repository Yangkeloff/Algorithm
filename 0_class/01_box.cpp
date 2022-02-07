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
    /* 类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。
    构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。
    构造函数可用于为某些成员变量设置初始值。 */

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