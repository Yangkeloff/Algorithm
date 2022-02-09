#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;

int heap[maxn], n = 10;

// low为欲调整结点数组下标,high为堆最后一个元素数组下标
void downAdjust(int low, int high) {
  int i = low, j = i * 2;
  while(j <= high) {  // 存在孩子结点
    if(j + 1 <= high && heap[j + 1] > heap[j]) {
      j = j + 1;
    }
    if(heap[j] > heap[i]) {
      swap(heap[j], heap[i]);
      i = j;  // 保持i为欲调整的结点
      j = i * 2;  // 保持j为i的左孩子
    } else {
      break;
    }
  }
}

void createHeap() {
  for(int i = n / 2; i >= 1; i--) {
    downAdjust(i, n);
  }
}

/*添加一个元素
新元素放在数组末尾，然后向上调整
对heap数组再[low,high]范围进行向上调整
low一般设置为1, high表示欲调整结点的数组下标
*/
void upAdjust(int low, int high) {
  int i = high, j = i / 2;  // i为欲调整结点, j为其父结点
  while(j >= 1) {
    if(heap[j] < heap[i]) {
      swap(heap[j], heap[i]);
      i = j;  // 保持i为欲调整结点
      j = i / 2;  // 保持j为i的父结点
    } else {
      break;
    }
  }
}

// 添加元素
void insert(int x) {
  heap[++n] = x;  // 元素个数+1，数组末位赋值为x
  upAdjust(1, n);   // 向上调整最后加入的结点
}

void heapSort() {
  createHeap();
  for(int i = n; i > 1; i--) {  // 倒着枚举，直到堆中只有一个元素
    swap(heap[i], heap[1]);
    downAdjust(1, i - 1);
  }
}