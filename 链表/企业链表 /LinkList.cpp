#include "./include/LinkList.h"

template<class T>
LinkList<T>::LinkList() {
    this->size = 0;
    this->head.next = nullptr;
}
template<class T>
LinkList<T>::~LinkList() {
    this->head.next = nullptr;
    this->size = 0;
}
template<class T>
void LinkList<T>::insert(int pos, LinkNode* data) {
    if (data == nullptr) {
        return;
    }
    // 友好处理，如果pos越界，将pos指向最后的链表，即插入到链表的尾部
    if (pos < 0 || pos > this->size) {
        pos = this->size;
    }
    // 查找插入位置
    LinkNode *pCurrent = &this->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    // 插入新节点
    data->next = pCurrent->next;
    pCurrent->next = data;
    this->size++;
}
template<class T>
void LinkList<T>::printLinkList() {
    auto *pCurrent = this->head.next;
    for (int i = 0; i < this->size; i++) {
        myPrint<LinkNode>(pCurrent); // 使用函数模板打印数组
        pCurrent = pCurrent->next;
    }
}
template<class T>
void LinkList<T>::remove(int pos) {
    if (pos < 0 || pos >= this->size) {
        return;
    }
    // 查找删除节点的前一个节点
    auto *pCurrent = &this->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    pCurrent->next = pCurrent->next->next;
    this->size--;
}
template<class T>
int LinkList<T>::getSize() const {
    return this->size;
}
template<class T>
int LinkList<T>::find(LinkNode* data) const {
    if (data == nullptr) {
        return -1;
    }
    // 遍历查找
    auto *pCurrent = this->head.next;
    int flag = -1;
    int index = 0;
    while (pCurrent != nullptr)
    {
        if (myCompare<LinkNode>(data, pCurrent)) {
            flag = index;
            break;
        }
        index ++;
        pCurrent = pCurrent->next;
    }
    return flag;
}
template<class T>
T* LinkList<T>::frontNode() {
    return this->head.next;
}