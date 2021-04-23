#include "./include/LinkQueue.h"

LinkQueue::LinkQueue() {
    this->head.next = NULL;
    this->size = 0;
}
LinkQueue::~LinkQueue() {

}
void LinkQueue::pushLinkQueue(LinkNode *data) {
    if (data == NULL) {
        return;
    }
    if (this->size == 0) {
        this->head.next = data;
        this->size++;
        return;
    }
    LinkNode *pCurrent = &this->head;
    for (int i = 0; i < this->size; i++) {
        pCurrent = pCurrent->next;
    }
    pCurrent->next = data;
    data->next = NULL;
    this->size++;
}

void LinkQueue::popLinkQueue() {
    if (this->size == 0) {
        return;
    }
    head.next = head.next->next;
    size--;
}

LinkNode *LinkQueue::frontLinkQueue() const {
    if (this->size == 0) {
        return NULL;
    }
    return this->head.next;
}

LinkNode *LinkQueue::backLinkQueue(){
    if (this->size == 0) {
        return NULL;
    }
    LinkNode *pCurrent = &this->head;
    for (int i = 0; i < this->size; i++) {
        pCurrent =   pCurrent->next;
    }
    return pCurrent;
}

int LinkQueue::getSize() const {
    return this->size;
}

void LinkQueue::clearLKQueue() {
    if (this->size == 0) {
        return;
    }
    head.next = NULL;
    this->size = 0;
}