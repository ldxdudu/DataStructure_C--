#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

// 二叉树节点
typedef struct BINARYNODE {
    char ch;
    struct BINARYNODE  *lchild;
    struct BINARYNODE  *rchild;
} BinaryNode;

BinaryNode *CreateBinaryTree() {
    char ch;
    cin >> ch;
    BinaryNode *node;
    if (ch == '#')
    {
        node = NULL;
    }
    else {
        node = new BinaryNode;
        node->ch = ch;
        node->lchild = CreateBinaryTree();
        node->rchild = CreateBinaryTree();
    }

    return node;
}

// 递归遍历
void recursion(BinaryNode* root) {
    if (root == NULL) {
        return;
    }
    // 前序遍历
    // 先访问根节点
    cout << root->ch << " ";
    // 再遍历左子树
    recursion(root->lchild);
    // 再遍历右子树
    recursion(root->rchild);

}

int main() {
    // 创建树
    BinaryNode *root = CreateBinaryTree();
    // 打印树
    recursion(root);
    cout << endl;
    return 0;
}