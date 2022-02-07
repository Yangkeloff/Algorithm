#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
  int data, height; // height记录当前子树高度
  node  *lchild, *rchild;
};

node* newNode(int x) {
  node *Node = new node;
  Node->data = x;
  Node->height = 1; // 新结点初始高度为1
  Node->lchild = Node->rchild = NULL;
  return Node;
}

// 获取以root为根结点的子树当前height
int getHeight(node* root) {
  if(root == NULL) return 0;  // 空结点高度为0
  return root->height;
}

// 计算root结点平衡因子
int getBalanceFactor(node* root) {
  // 左子树高度减右子树高度
  return getHeight(root->lchild) - getHeight(root->rchild);
}

// 更新结点root的height
void updateHeight(node* root) {
  // 左子树右子树最大高度 + 1
  root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

// 查找操作 AVL即BST
void search(node* root, int x) {
  if(root == NULL) {
    printf("search failed\n");
    return;
  }
  if(x == root->data) {
    printf("%d\n", root->data);
  } else if(x < root->data) {
    search(root->lchild, x);
  } else {
    search(root->rchild, x);
  }
}

// 左旋
void L(node* &root) {
  node *temp = root->rchild;
  root->rchild = temp->lchild;
  temp->lchild = root->rchild;
  updateHeight(root);
  updateHeight(temp);
  root = temp;  // 更新根结点
}

// 右旋
void R(node* &root) {
  node *temp = root->lchild;
  root->lchild = temp->rchild;
  temp->rchild = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;  // 更新根结点
}

/* AVL插入情况汇总  BF即getBalanceFactor返回的平衡因子
LL BF(root) = 2, BF(root->lchild) = 1 右单旋
RR BF(root) = -2, BF(root->rchild) = -1 左单旋
LR BF(root) = 2, BF(root->lchild) = -1 左旋+右旋
RL BF(root)= -2, BF(root->rchild)= 1 右旋+左旋
*/
void insert(node* &root, int x) {
  if(root == NULL) {
    root = newNode(x);
    return;
  }
  if(x < root->data) {
    insert(root->lchild, x);
    updateHeight(root); // 更新树高
    if(getBalanceFactor(root) == 2) {
      if(getBalanceFactor(root->lchild) == 1) {
        // LL型，右单旋
        R(root);
      } else if(getBalanceFactor(root->lchild) == -1) {
        // LR型，左旋+右旋
        L(root->lchild);
        R(root);
      }
    }
  } else {
    insert(root->rchild, x);
    updateHeight(root);
    if(getBalanceFactor(root) == -2) {
      if(getBalanceFactor(root->rchild) == -1) {
        // RR型，左单旋
        L(root);
      } else if(getBalanceFactor(root->rchild) == 1) {
        // RL型，右旋+左旋
        R(root->rchild);
        L(root);
      }
    }
  }
}