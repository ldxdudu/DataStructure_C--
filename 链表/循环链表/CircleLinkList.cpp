#include "./include/CircleLinKList.h"

CircleLinkList::CircleLinkList() {
    this->size = 0;
    this->head = new CircleLinkNode;
    this->head->next = this->head;
}
CircleLinkList::~CircleLinkList() {
    delete head;
    this->head = NULL;
    size = 0;
    cout << "free" << endl;
}

void CircleLinkList::insertLinkList(int pos, CircleLinkNode *data){
    if (data == NULL) {
        return;
    }
    if (pos < 0 || pos >= this->size) {
        pos = this->size;
    }
    CircleLinkNode *pCurrent = this->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    data->next = pCurrent->next;
    pCurrent->next = data;

    this->size++;
}
void CircleLinkList::removeLinkListPos(int pos) {
    if (pos < 0 || pos >= this->size) {
        return;
    }
    CircleLinkNode *pCurrent = this->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    pCurrent->next = pCurrent->next->next;

    this->size--;
}
void CircleLinkList::printLinkList(PRINTLINKNODE print) {
    CircleLinkNode *pCurrent = this->head->next;
    for (int i = 0; i < this->size; i++) {
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
}
// 使用函数模板的重载版本
void CircleLinkList::printLinkList() {
    CircleLinkNode *pCurrent = this->head->next;
    for (int i = 0; i < this->size; i++) {
        myPrint<CircleLinkNode>(pCurrent); // 使用函数模板打印数组
        pCurrent = pCurrent->next;
    }
}