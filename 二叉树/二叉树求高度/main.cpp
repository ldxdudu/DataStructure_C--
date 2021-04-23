#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉树节点
typedef struct BINARYNODE {
    char ch;
    struct BINARYNODE  *lchild;
    struct BINARYNODE  *rchild;
} BinaryNode;

void CalculateTreeHeight(BinaryNode *root, int &height) {
    if (root == NULL) {
        return;
    }
    int lh = 0;
    int rh = 0;
    CalculateTreeHeight(root->lchild, lh);
    CalculateTreeHeight(root->rchild, rh);
    if (lh >= rh) {
        height = 1 + lh;
    }
    else { 
        height = 1 + rh;
    }
    // height = 1 + ((lh > rh) ? lh : rh);
    /**
     * Exp1 ? Exp2 : Exp3;
     * 其中，Exp1、Exp2 和 Exp3 是表达式。
     * 请注意冒号的使用和位置。? : 表达式的值取决于 Exp1 的计算结果。
     * 如果 Exp1 为真，则计算 Exp2 的值，且 Exp2 的计算结果则为整个 ? : 表达式的值。
     * 如果 Exp1 为假，则计算 Exp3 的值，且 Exp3 的计算结果则为整个 ? : 表达式的值。
     */
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

    int height = 0;
    CalculateTreeHeight(&node1, height);
    printf("二叉树的高度：%d\n", height);
}

int main() {
    CreateBinaryTree();
    return 0;
}