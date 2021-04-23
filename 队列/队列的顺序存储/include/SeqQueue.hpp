#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>

const int MAX_SIZE = 1024;

template<class T> //
class SeqQueue {
private:
    T *data[MAX_SIZE];
    int size;
public:
    SeqQueue();
    ~SeqQueue();
    // 入队
    void pushQueue(T *data);
    // 出队
    void popQueue();
    // 返回对头元素
    T *frontQueue();
    // 返回队尾元素
    T *backQueue();
    // 返回大小
    int getSize();
    // 清空队列
    void clearQueue();
};

template<class T>
SeqQueue<T>::SeqQueue() {
    for (int i = 0; i < MAX_SIZE; i++) {
        this->data[i] = NULL;
    }
    this->size = 0;
}
template<class T>
SeqQueue<T>::~SeqQueue() {

}
template<class T>
void SeqQueue<T>::pushQueue(T *pushData) {
    if (data == NULL) {
        return;
    }
    if (this->size == MAX_SIZE) {
        return;
    }
    this->data[this->size] = pushData;
    this->size++;
}
// 出队
template<class T>
void SeqQueue<T>::popQueue() {
    if (this->size == 0) {
        return;
    }
    for (int i = 0; i < this->size; i++) {
        this->data[i] = this->data[i + 1];
    }
    this->size--;
}
template<class T>
T *SeqQueue<T>::frontQueue() {
    if (this->size == 0) {
        return NULL;
    }
    return this->data[0];
}
template<class T>
T *SeqQueue<T>::backQueue() {
    if (this->size == 0 ){
        return NULL;
    }
    return data[this->size - 1];
}

template<class T>
int SeqQueue<T>::getSize() {
    return this->size;
}

template<class T>
void SeqQueue<T>::clearQueue() {
    this->size = 0;
}

#endif 