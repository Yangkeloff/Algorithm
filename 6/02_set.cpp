// set集合,内部自动有序且不含重复元素的容器
#include <set>
using namespace std;

set<int> d1;
set<double> db1;
set<char> c1;

set<int> a[100];

int main() {
  set<int> st;
  /* insert(x)将x插入set容器中，并自动递增排序和去重
  时间复杂度o(logN),其中N为set内元素个数 */
  st.insert(3);
  st.insert(5);
  st.insert(2);
  st.insert(3);
  //set只能通过迭代器(iterator)访问
  for(set<int>::iterator it = st.begin(); it != st.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");

  //find(value)返回set中对应值为value的迭代器,时o(logN)
  set<int>::iterator it = st.find(3); //st中查找3,返回其迭代器
  printf("%d\n", *it);
  /*
  size(), earse(), clear()用法同vector
  */
  return 0;
}