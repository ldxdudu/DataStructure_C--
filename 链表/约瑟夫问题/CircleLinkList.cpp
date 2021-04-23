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
void CircleLinkList::removeLinkListVal (CircleLinkNode *data, COMPAERNODE compare) {
    if (data == NULL) {
        return;
    }

    CircleLinkNode *pPrev = this->head;
    CircleLinkNode *pCurrent = this->head->next;
    
    for (int i = 0; i < this->size; i++) {
        if (compare(pCurrent, data)== true) {
           pPrev->next = pCurrent->next;
            this->size--;
            break;
        }
        pPrev= pCurrent;
        pCurrent = pCurrent->next;
    }
}

void CircleLinkList::printLinkList(PRINTLINKNODE print) {
    CircleLinkNode *pCurrent = this->head->next;
    for (int i = 0; i < this->size; i++) {
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
    cout << endl;
}

CircleLinkNode* CircleLinkList::getHead() {
    return this->head;
}

int CircleLinkList::getSize() {
    return this->size;
}

CircleLinkNode* CircleLinkList::getFront() {
    return this->head->next;
}
