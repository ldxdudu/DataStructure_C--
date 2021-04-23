#include "./include/LinkList.h"

template<class T>
LinkList<T>::LinkList() {
    this->size = 0;
    this->head = new LinKNode<T>;
    head->next = nullptr;
    head->data = nullptr;
}
template<class T>
LinkList<T>::~LinkList() {
    auto *pCurrent = this->head->next;
    while (pCurrent != nullptr) {
        // 缓存下一个结点
        auto *pNext = pCurrent->next;
        delete pCurrent;
        pCurrent = pNext;
    }
    this->size = 0;
}
template<class T>
void LinkList<T>::insert(int pos, T* data) {
    if (data == nullptr) {
        return;
    }
    // 友好处理，如果pos越界，将pos指向最后的链表，即插入到链表的尾部
    if (pos < 0 || pos > this->size) {
        pos = this->size;
    }
    // 创建新的节点
    auto *newNode = new LinKNode<T>;
    newNode->data = data;
    newNode->next = nullptr;
    // 找节点 
    auto *pCurrent = this->head;
    for (int i = 0; i < pos; i++) { // 新节点的前一个节点
        pCurrent = pCurrent->next;
    }
    // 插入新节点
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;

    this->size++;
}
template<class T>
void LinkList<T>::printLinkList() {
    auto *pCurrent = this->head->next;
    while (pCurrent != nullptr) {
        myPrint<T>(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}
template<class T>
void LinkList<T>::remove(int pos) {
    if (pos < 0 || pos >= this->size) {
        return;
    }
    // 查找删除节点的前一个节点
    auto *pCurrent = this->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    // 缓存删除de节点
    auto *pDel = pCurrent->next;
    pCurrent->next = pDel -> next;
    // 释放删除节点的测IC
    delete pDel;

    this->size--;    
}
template<class T>
int LinkList<T>::getSize() const {
    return this->size;
}
template<class T>
int LinkList<T>::find(T* data) const {
    if (data == nullptr) {
        return -1;
    }
    // 遍历查找
    auto *pCurrent = this->head->next;
    int flag = -1;
    int index = 0;
    while (pCurrent != nullptr)
    {
        if (myCompare<T>(data, pCurrent->data)) {
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
    return this->head->next;
}