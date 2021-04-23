#ifndef __LINKLIST__H__
#define __LINKLIST__H__

// 定义函数模板，并在main中进行重载
template <typename T>
void myPrint(T *data);

// 定义比较函数的函数模板
template <typename T>
bool myCompare(T *data1, T *data2);

class LinkNode {
public:
    LinkNode *next;
};

template<class T>
class LinkList {
private:
    LinkNode head;
    int size;
public:
    LinkList();
    ~LinkList();
    // 在指定位置插入
    void insert(int pos, LinkNode* data);
    // 在指定位置删除
    void remove(int pos);
    // 获得链表的长度
    int getSize() const;
    // 查找元素所在位置
    int find(LinkNode* data) const;
    // 返回第一个节点
    T *frontNode();
    // 打印链表节点
    void printLinkList();
};

#endif