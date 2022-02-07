#include <cstdio>

struct node
{
  int data;
  node* lchild;
  node* rchild;
};

node* newNode(int x) {
  node* Node = new node;
  Node->data = x;
  Node->lchild = Node->rchild = NULL;
  return Node;
}

void search(node* root, int x) {
  if(root == NULL) {  // 空树,查找失败
    printf("search failed\n");
    return;
  }
  if(x == root->data) { // 查找成功,访问
    printf("%d\n", root->data);
  }else if(x < root->data) {
    search(root->lchild, x);
  } else {
    search(root->rchild, x);
  }
}

// 插入数据域为x的结点,注意root要引用&
void insert(node* &root, int x) {
  if(root == NULL) {
    root = newNode(x);
    return;
  }
  if(x == root->data) {
    return; // BST中已有值为x的结点,直接返回
  } else if(x < root->data) {
    insert(root->lchild, x);
  } else {
    insert(root->rchild, x);
  }
}

// 寻找以root为根结点关键字最大的结点
node* findMax(node* root) {
  while (root->rchild != NULL)
  {
    root = root->rchild;
  }
  return root;
}

node* findMin(node* root) {
  while (root->lchild != NULL)
  {
    root = root->lchild;
  }
  return root;
}

/* 删除操作的基本思路
1.若当前root为空，直接返回
2.若当前root关键字等于x，即找到要删除的结点，则进入删除处理
  a.若当前root无左右孩子，则为叶结点，直接删除
  b.若当前root有左孩子，则在左子树中找到关键字最大结点为pre，用pre覆盖root，再删除左子树中的pre
  c.若当前root有右孩子，则在右子树中找到关键字最小结点为next，用next覆盖root，再删除右子树中的next
3.若当前root关键字大于x，则在左子树递归
4.若当前root关键字小于x，则在右子树递归
*/

// 在以root为根结点的BST中删除关键字为x的结点,注意root引用&
void deleteNode(node* &root, int x) {
  if(root == NULL) return;
  if(x == root->data) {
    if(root->lchild == root->rchild == NULL) {
      root == NULL;
    } else if(root->lchild != NULL) {
      node* pre = findMax(root);  // 找root前驱
      root->data = pre->data; // 覆盖
      deleteNode(root->lchild, pre->data);  // 左子树中删除pre
    } else {
      node* next = findMin(root); // 找root后继
      root->data = next->data;  // 覆盖
      deleteNode(root->rchild, next->data); // 右子树中删除next
    }
  } else if(x < root->data) {
    deleteNode(root->lchild, x);
  } else {
    deleteNode(root->rchild, x);
  }
}