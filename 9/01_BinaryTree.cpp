#include <cstdio>

struct node{
  char data;
  node* lchild;
  node* rchild;
};

node* newNode(char x) {
  node* Node = new node;  // 申请一个node型变量的地址空间
  Node->data = x;
  Node->lchild = Node->rchild = NULL;
  return Node;
}

// 找到指定值所在结点并修改
void search(node* root, char x, char newX) {
  if(root == NULL) return;  // 空树；死胡同(递归边界)
  if(root->data == x) root->data = newX;
  search(root->lchild, x, newX);
  search(root->rchild, x, newX);
}

// 插入结点,注意根节点要引用，否则无法插入
void insert(node* &root, char x) {
  // 若空树,即查找失败，也即插入位置(递归边界)
  if(root == NULL) {
    root = newNode(x);
    return;
  }
  /*
  根据要求做判断是左子树还是右子树
  insert(root->lchild, x);
  insert(root->rchild, x);
  */
}

int main() {
  return 0;
}