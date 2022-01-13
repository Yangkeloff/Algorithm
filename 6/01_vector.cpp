// vector翻译为向量，称为“变长数组”更好理解
#include <vector>
using namespace std;

vector<vector<int> > vc1;
/* 
若typename也是一个STL容器,>>之间要加空格,否则将被视为位移
vc1类似于二维数组
*/

vector<int> va[10];   //vector数组

/*
vector容器内元素的访问
1.下标  va[index]
2.迭代器iterator  (可理解为类似于指针的东西)
*/
int main() {
  for(int i = 1; i <= 5; i++) {
    va->push_back(i); //push_back(i)在va末尾添加元素i,时o(1)
  }
  //va.begin()为取va的首元素地址,而it指向这个地址
  vector<int>::iterator it = va->begin();   //可通过*it访问元素
  for(int i = 0; i < 5; i++)
    printf("%d ", *(it + i)); //输出va[i]
  printf("\n");
  // 可以看出va[i]和*(va.begin() + i)是等价的

  // pop_back()删除vector尾元素
  va->pop_back();
  va->pop_back();

  // end()取va❗️尾元素地址的下一个地址❗️,美国人思维习惯左闭右开[)
  // 另一种遍历方法
  for(; it != va->end(); it++)
    printf("%d ", *it);
  printf("\n");

  printf("size:%d\n", (int)va->size());  //size()获得vector中元素的个数返回类型unsigned,时o(1)
  
  va->insert(va->begin() + 2, -1); // 在va[2]位置插入-1
  for(it = va->begin(); it != va->end(); it++)
    printf("%d ", *it);
  printf("\n");

  for(int i = 5; i <= 8; i++) {
    va->push_back(i);
  }

  va->erase(va->begin() + 2);   //erase(it)删除it位置元素
  //erase(first, last)删除[first,last)内的所有元素❗️左闭右开[)
  va->erase(va->begin(), va->begin() + 3);
  for(it = va->begin(); it != va->end(); it++)
    printf("%d ", *it);
  printf("\n");
  // clear()清空vector中所有元素,时o(N)
  return 0;
}
