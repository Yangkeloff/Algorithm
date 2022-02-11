#include <cstdio>
#include <queue>
using namespace std;

/*
优先队列priority_queue包含队列的所有特性和基本操作,
只是在这基础上添加了内部的一个排序,它本质是一个堆实现的
定义
priority_queue<Type, Container, Functional>
Type:数据类型
Container:容器类型(Container必须是用数组实现的容器, 如vector,deque等, 但不能用list. STL默认vector)
Functional:比较的方式,当需要用自定义的数据类型时才需要传入这三个参数,使用基本数据类型时,只需要传入数据类,默认是大顶堆
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列
priority_queue <int,vector<int>,less<int> >q;
*/

// 代表小顶堆的优先队列
priority_queue<long long, vector<long long>, greater<long long> > q;

int main() {
  int n;
  long long temp, x, y, ans = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &temp);
    q.push(temp); // 初值加入优先队列
  }
  while(q.size() > 1) { // 优先队列中至少有2个元素
    x = q.top();
    q.pop();
    y = q.top();
    q.pop();
    q.push(x + y);  // 堆顶2元素求和后加入队列
    ans += x + y; // 累计求和结果
  }
  printf("%lld\n", ans);
  return 0;
}

/*
n = 5
weight:1 2 2 3 6
ans = 30
*/