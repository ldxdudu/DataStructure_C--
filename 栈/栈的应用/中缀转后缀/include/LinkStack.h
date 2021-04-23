#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
#include <cstdlib>
#include <iostream>
using namespace std;
#include <string>

class LinkNode {
public:
    LinkNode *next;
};

class LinkStack {
private:
    LinkNode head;
    int size;
public:
    LinkStack();
    ~LinkStack();
    // 入栈
    void pushLinkStack(LinkNode *data);
    // 出栈
    void popLinkStack();
    // 返回栈顶元素
    LinkNode *topLinkStack() const; // 在一个类的成员函数后面加上const后，就表明这个函数是不能改变类的成员变量的
    // 清空栈
    void clearLinkStack();
    // 返回元素的个数
    int getSize() const;
    // 判断栈是否为空
    bool isEmpty() const;
};
#endif // __LINKSTACK_H__