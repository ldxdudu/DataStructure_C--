#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <iostream>
using namespace std;
// 二叉树节点
typedef struct BINARYNODE {
    char ch;
    struct BINARYNODE  *lchild;
    struct BINARYNODE  *rchild;
} BinaryNode;

// satck<pair<node, bool>>
// 二叉树非递归遍历
typedef struct BITREEESTACKNODE{
    BinaryNode *root;
    bool flag;
} BiTreeStackNode;
// 创建栈中的结点
BiTreeStackNode *CreateBiTreeStackNode(BinaryNode *node, bool flag) {
    auto *newNode = new BiTreeStackNode;
    // BiTreeStackNode test;
    // BiTreeStackNode *newNode = &test;
    newNode->root = node;
    newNode->flag = flag;
    return newNode;
}
void NoRecursion(BinaryNode *root) {
    // 创建栈
    stack<BiTreeStackNode *> stk;
    // 把根节点扔到栈里
    stk.push(CreateBiTreeStackNode(root, false));
    while (!stk.empty()) {
        // 先弹出栈顶元素
        BiTreeStackNode *node = stk.top();
        stk.pop();
        // 判断弹出的结点是否为空
        if (node->root == NULL) {
            continue;
        }
        if (node->flag == true) {
            cout << node->root->ch << " ";
        }
        else { // 先序
            stk.push(CreateBiTreeStackNode(node->root->rchild, false)); // 先压入右结点
            stk.push(CreateBiTreeStackNode(node->root->lchild, false)); // 再压入左结点
            // 当前结点入栈
            node->flag = true;
            stk.push(node);
        }
    }
}
//使用satck<pair<BinaryNode *, bool>>进遍历
void NoRecursion_Pair(BinaryNode *root) {
    // 创建栈
    stack<pair<BinaryNode *, bool>> stk1;
    // 把根节点扔到栈里
    stk1.push(make_pair(root, false));
    while (!stk1.empty()) {
        // 先弹出栈顶元素
        pair<BinaryNode*, bool> node1 = stk1.top();
        stk1.pop();
        // 判断弹出的结点是否为空
        if (node1.first == NULL) {
            continue;
        }
        if (node1.second == true) {
            cout << node1.first->ch << " ";
        }
        else { // 先序
            stk1.push(make_pair(node1.first->rchild, false)); // 先压入右结点
            stk1.push(make_pair(node1.first->lchild, false)); // 再压入左结点
            // 当前结点入栈
            node1.second = true;
            stk1.push(node1);
        }
    }
}
void CreateBinaryTree() {
    // 创建节点
    BinaryNode node1 = {'A', NULL, NULL};
    BinaryNode node2 = {'B', NULL, NULL};
    BinaryNode node3 = {'C', NULL, NULL};
    BinaryNode node4 = {'D', NULL, NULL};
    BinaryNode node5 = {'E', NULL, NULL};
    BinaryNode node6 = {'F', NULL, NULL};
    BinaryNode node7 = {'G', NULL, NULL};
    BinaryNode node8 = {'H', NULL, NULL};
    // 建立节点关系
    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    node7.lchild = &node8;
    
    // 二叉树的非递归打印
    // NoRecursion(&node1);\
    // 使用satck<pair<BinaryNode *, bool>>进行
    NoRecursion_Pair(&node1);
    cout << endl;
}

int main() {
    CreateBinaryTree();
    return 0;
}