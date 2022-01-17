#include <cstdio>
#include <stdlib.h>

const int maxn = 7;

struct node{
  int data;
  node* next;
};

// 创建链表
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

// 搜索在以head为头结点的链表中含元素x的数量
int searchCount(node *head, int x) {
  int count = 0;
  node *p = head -> next;  // 从第一个结点开始查找
  while(p != NULL) {
    if(p->data == x) count++;
    p = p->next; 
  }
  return count;
}

// 插入元素
void insert(node *head, int pos, int x) {
  node *p = head;
  for(int i = 0; i < pos - 1; i++) {  // 找到待插入位置的前一位置
    p = p->next;
  }
  node *q;
  q = new node;
  q->data = x;
  q->next = p->next;
  p->next = q;
}

// 删除以head为头结点的链表中所有数据域为x的结点
void del(node *head, int x) {
  node *pre, *p;
  pre = head;
  p = head->next;
  while(p != NULL) {
    if(p->data == x) {
      pre->next = p->next;
      delete(p);  // 约等于free(p)
      p = pre->next;
    } else {
      pre = p;
      p = p->next;
    }
  }
}

int main() {
  int A[maxn] = {5, 5, 8, 7, 6, 5, 8};
  create(A);
  node *L = create(A);  // 新建链表,返回头指针赋给L
  L = L -> next;  // 从第一个结点开始有数据域
  while(L != NULL) {
    printf("%d ", L -> data);
    L = L -> next;
  }
  int count = searchCount(create(A), 8);
  printf("\n%d\n", count);
  node *L2 = create(A);
  insert(L2, 3, 7);
  L2 = L2 -> next;  // 从第一个结点开始有数据域
  while(L2 != NULL) {
    printf("%d ", L2 -> data);
    L2 = L2 -> next;
  }
  printf("\n");
  node *L3 = create(A);
  del(L3, 5);
  L3 = L3 -> next;
  while(L3 != NULL) {
    printf("%d ", L3->data);
    L3 = L3->next;
  }
  printf("\n");
  return 0;
}