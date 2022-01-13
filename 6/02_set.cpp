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
    printf("%d", *it);
  }
  return 0;
}