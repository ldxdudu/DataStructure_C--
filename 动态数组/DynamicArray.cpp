#include "./include/DynamicArray.h"

DynamicArray::DynamicArray() {
    this->size = 0;
    this->capacity = 20;
    this->pAddr = new int[capacity];
}
DynamicArray::~DynamicArray() {
    delete[] pAddr;
    cout << "free array" << endl;
}
void DynamicArray::pushBackArray(int value) {
    if (this->pAddr == nullptr) {
        return;
    }
    if (this->size == this->capacity) {
        int *newSpace = new int[capacity*2];
        memcpy(newSpace, pAddr, capacity*sizeof(int));
        delete[] pAddr;
        this->pAddr = newSpace;
        this->capacity = capacity * 2;
    }
    this->pAddr[this->size] = value;
    this->size++;
}
// 在指定位置增加一个数据
void DynamicArray::insertArray(int pos, int value) {
    if (this->pAddr == nullptr) {
        return;
    }
    if (this->size < pos || pos < 0) {
        return;
    }
    if (this->size == this->capacity) {
        int *newSpace = new int[capacity*2];
        memcpy(newSpace, pAddr, capacity*sizeof(int));
        delete[] pAddr;
        this->pAddr = newSpace;
        this->capacity = capacity * 2;
    }
    int *test = new int [size - pos];
    for (int i = 0; i < size - pos; i++) {
        test[i] = pAddr[pos + i];
    }
    pAddr[pos] = value;
    int j = 0;
    for (int i = 1; i <= size - pos; i++, j++) 
    {
        pAddr[pos + i] = test[j];
    }
    this->size++;
    delete[] test;
}
void DynamicArray::popBackArray() {
    if (this->pAddr == nullptr) {
        return;
    }
    if (this->size == 0) {
        return;
    }
    this->size--;
}
void DynamicArray::showArray() {
    if (this->pAddr == nullptr) {
        return;
    }
    if (this->size == 0) {
        cout << "数组为空" << endl;
        return;
    }
    for (int i = 0; i < this->size; i++) {
        cout << this->pAddr[i] << " ";
    }
    cout << endl;
}
int DynamicArray::findArrayPos(int value) {
    if (this->pAddr == nullptr) {
        return -1;
    }
    for (int i = 0; i < this->size; i++) {
        if (this->pAddr[i] == value) {
            return i;
        }
    }
    return -1;
}
void DynamicArray::removeArrayPos(int pos){
    if (this->pAddr == nullptr) {
        return;
    }
    if (this->size <= pos || pos < 0) {
        return;
    }
    for (int i = pos; i < this->size-1; i++) {
        this->pAddr[i] = this->pAddr[i+1];
    }
    this->size--;
}
void DynamicArray::removeArrayVal(int value) {
    if (this->pAddr == nullptr) {
        return;
    }
    int pos = findArrayPos(value);
    removeArrayPos(pos);
}
bool DynamicArray::atArray(int pos, int& value) {
    if (this->pAddr == nullptr) {
        return false;
    }
    if (pos < 0 || pos >= size) {
        return false;
    }
    value = this->pAddr[pos];
    return true;
}
void DynamicArray::clearArray() {
    size = 0;
}
int DynamicArray::getSizeArray() {
    return size;
}
int DynamicArray::getCapactity() {
    return capacity;
}