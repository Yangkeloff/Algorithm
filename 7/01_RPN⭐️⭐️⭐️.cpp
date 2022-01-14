// 书p247简单计算器(中缀转后缀再计算)
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
using namespace std;

struct node {
  double num;   // 操作数
  char op;  // 操作符
  bool flag;  // true为数,false为符
};

string str;   // 输入字符串
stack<node> s;  // 运算符栈
queue<node> q;  // 后缀表达式队列
map<char, int> op;  // 操作符优先级

void Change() {  // 中缀转后缀
  node temp;
  for(int i = 0; i < str.length();) {   // 从左到右扫描中缀表达式
    if(str[i] >= '0' && str[i] <= '9') {    // 若是操作数
      temp.flag = true;
      temp.num = str[i++] - '0';
      while(i < str.length() && str[i] >= '0' && str[i] <= 9) {
        temp.num = temp.num * 10 + (str[i] - '0');
        i++;
      }
      q.push(temp); // 加入后缀表达式
    } else {  // 若是操作符
      temp.flag = false;
      // 扫描到的运算符优先级小于等于栈顶操作符优先级,则操作符栈的操作符不断弹出到后缀表达式
      while(!s.empty() && op[str[i]] <= op[s.top().op]) {
        q.push(s.top());
        s.pop();
      }
      temp.op = str[i];
      s.push(temp);   // 操作符入栈
      i++;
    }
  }
  while(!s.empty()) {   // 若操作符栈不空，则全部加入后缀表达式
    q.push(s.top());
    s.pop();
  }
}

double cal() {  // 计算后缀表达式
  double temp1, temp2;
  node cur, temp;
  while(!q.empty()) { // 若后缀表达式非空
    cur = q.front();  // cur记录队首元素
    q.pop();
    if(cur.flag == true)  s.push(cur);  // 是操作数，直接入栈
    else {
      // 若是操作符,从栈中弹出两个操作数(先弹temp2再temp1)
      temp2 = s.top().num;
      s.pop();
      temp1 = s.top().num;
      s.pop();
      temp.flag = true; // temp记录临时操作数
      if(cur.op == '+') temp.num = temp1 + temp2;
      else if (cur.op == '-') temp.num = temp1 - temp2;
      else if (cur.op == '*') temp.num = temp1 * temp2;
      else if (cur.op == '/') temp.num = temp1 / temp2;
      s.push(temp); // 新得到的操作数入栈
    }
  }
  return s.top().num;   // 栈顶元素即后缀表达式结果
}

int main() {
  op['+'] = op['-'] = 1;  // 设定运算符优先级
  op['*'] = op['/'] = 2;
  printf("整数和运算符之间用一个空格分隔,当一行中只有0时输入结束\n");
  while(getline(cin, str), str != "0") {
    for(string::iterator it = str.end(); it != str.begin(); it--) {
      if(*it == ' ') str.erase(it); // 去空格
    }
    while(!s.empty()) s.pop();  // 初始化栈
    Change(); // 中缀转后缀
    printf("%.2f\n", cal());
  }
  return 0;
}
/*测试
1 + 3 * 5 / 4 * 8 / 9 * 6 * 2 / 3 / 7 + 3 * 8 / 2         // 14.9
*/