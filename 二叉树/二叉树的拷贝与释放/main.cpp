#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉树节点
typedef struct BINARYNODE {
    char ch;
    struct BINARYNODE  *lchild;
    struct BINARYNODE  *rchild;
} BinaryNode;

// 遍历二叉树
void Recursion(BinaryNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->ch);
    // 遍历左子树
    Recursion(root->lchild);
    // 遍历右子树
    Recursion(root->rchild);

}
// 拷贝二叉树
BinaryNode *CopyBinaryNode(BinaryNode *root) {
    if (root == NULL) {
        return NULL;
    }

    // 拷贝左子树
    BinaryNode *child = CopyBinaryNode(root->lchild);
    // 拷贝右子树
    BinaryNode *rchild = CopyBinaryNode(root->rchild);

    // 创建结点
    BinaryNode *newNode = (BinaryNode *)malloc(sizeof(BinaryNode));
    newNode->ch = root->ch;
    newNode->lchild = root->lchild;
    newNode->rchild = root->rchild;

    return newNode;
}
//释放二叉树内存
void FreeSpaceBinary(BinaryNode *root) {
    if (root == NULL) {
        return;
    }
    // 释放左子树
    FreeSpaceBinary(root->lchild);
    // 释放右子树
    FreeSpaceBinary(root->rchild);
    // 释放当前结点
    free(root);
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

    BinaryNode *root = CopyBinaryNode(&node1);
    Recursion(root);
    FreeSpaceBinary(root);
    printf("\n");
}

int main() {
    CreateBinaryTree();
    return 0;
}