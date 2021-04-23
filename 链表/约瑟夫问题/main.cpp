/*
 * @Description: 约瑟夫问题
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-22 22:12:17
 * @Problem:
 *  例题:m个人围成一个圆圈,首先第1个人从1开始一个人一个人顺时针报数,
 *  报到第n个人,令其出列,然后再从下一个人开始从1顺时针报数,报到第n个人再令其出列..,
 *  如此下去,求出列顺序
 */

#include "./include/CircleLinKList.h"

const int M = 8; // 总人数
const int N = 3; // 数N个数出列

class myNum{
public: 
    CircleLinkNode *Node;
    int val;
};

void myPrint(CircleLinkNode *data) {
    myNum *num = (myNum *)data;
    cout << num->val << " ";
}

bool myCompare(CircleLinkNode *data1, CircleLinkNode *data2) {
    myNum *num1 = (myNum *)data1;
    myNum *num2 = (myNum *)data2;
    if (num1->val== num2->val)
    {
        return true;
    }
    return false;
}

int main()
{
    CircleLinkList *list = new CircleLinkList;
    
    myNum num[M];
    for (int i = 0; i < M; i++) {
        num[i].val = i + 1;
        list->insertLinkList(i, (CircleLinkNode *)&num[i]);
    }
    // 打印
    list->printLinkList(myPrint);

    int index = 1;
    CircleLinkNode *pCurrent = list->getHead()->next;
    while (list->getSize() > 1) {
        if (index == N) {
            if (pCurrent == list->getHead()) { // 跳过头结点
                pCurrent = pCurrent->next;
            }
            myNum *temNum = (myNum *)pCurrent; // 输出
            cout << temNum->val << " ";

            // 缓存待删除结点的下一个结点
            CircleLinkNode *pNext = pCurrent->next;

            // 根据值删除
            list->removeLinkListVal(pCurrent, myCompare);

            pCurrent = pNext;
            index = 1;
        }
        
        if (pCurrent == list->getHead()) { // 跳过头结点
            pCurrent = pCurrent->next;
        }
        pCurrent = pCurrent->next;
        index++;
    }
    
    if (list->getSize() == 1) // 输出最后链表中剩下的一个数
    {
        myNum *finally = (myNum *)list->getFront();
        cout << finally->val << endl;
        cout << endl;
    }
    else {
        cout << "出错" << endl;
    }

    delete list;
    return 0;
}