#include "./include/LinkStack.h"

LinkStack::LinkStack() {
    this->head.next = NULL;
    this->size = 0;
}

LinkStack::~LinkStack(){

}

void LinkStack::pushLinkStack(LinkNode *data) {
    if (data == NULL) {
        return;
    }
    data->next = head.next;
    head.next = data;
    this->size++;
}

void LinkStack::popLinkStack() {
    if (this->size == 0) {
        return;
    }
    head.next = head.next->next;
    this->size--;
}

LinkNode *LinkStack::topLinkStack() const {
    if (this->size == 0) {
        return NULL;
    }
    return this->head.next;
}

void LinkStack::clearLinkStack() {
    if (this->size == 0) {
        return;
    }
    this->head.next = NULL;
    this-> size = 0;
}

int LinkStack::getSize() const {
    return this->size;
}

bool LinkStack::isEmpty() const {
    if (this->size == 0) {
        return true;
    }
    return false;
}