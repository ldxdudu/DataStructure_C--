#ifndef __LINKLIST__H__
#define __LINKLIST__H__

// 定义函数模板，并在main中进行重载
template <typename T>
void myPrint(T *data);

// 定义比较函数的函数模板
template <typename T>
bool myCompare(T *data1, T *data2);

// 结点
template<class T>
class LinKNode {
public:
    T* data;
    LinKNode* next;
};

// 链表
template<class T1>
class LinkList {
private:
    LinKNode<T1>* head;
    int size;
public:
    LinkList();
    ~LinkList();
    // 在指定位置插入
    void insert(int pos, T1* data);
    // 在指定位置删除
    void remove(int pos);
    // 获得链表的长度
    int getSize() const;
    // 查找元素所在位置
    int find(T1* data) const;
    // 返回第一个节点
    T1 *frontNode();
    // 打印链表节点
    void printLinkList();
};
#endif
