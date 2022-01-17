#include <cstdio>
#include <stdlib.h>

const int maxn = 5;

struct node{
  int data;
  node* next;
};

node* create(int A[]) {
  node *pre, *p, *head;
  head = new node;  // C++中new与malloc类似
  head -> next = NULL;  // 头指针数据域为空,初始next为空
  pre = head;
  for(int i = 0; i < maxn; i++) {
    p = new node;
    p -> data = A[i];
    p -> next = NULL;
    pre -> next = p;
    pre = p;
  }
  return head;
}

int main() {
  int A[maxn] = {5, 9, 7, 6, 8};
  create(A);
  node *L = create(A);  // 新建链表,返回头指针赋给L
  L = L -> next;  // 从第一个结点开始有数据域
  while(L != NULL) {
    printf("%d ", L -> data);
    L = L -> next;
  }
  printf("\n");
  return 0;
}