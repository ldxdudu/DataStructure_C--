#ifndef __CIRCLELINKLIST_H__
#define __CIRCLELINKLIST_H__
#include <cstdlib>
#include <iostream>
using namespace std;
#include <string>
#include <string.h>

typedef struct CIRCLELINKNODE {
    struct CIRCLELINKNODE *next;
} CircleLinkNode;

typedef  void(*PRINTLINKNODE)(CircleLinkNode *dniata);

template<typename T> // 定义函数模板，并在main中进行重载
void myPrint(T *data) {
    // cout << *data << endl;
}

class CircleLinkList {
private:
    int size;
    CircleLinkNode *head;
public:
    CircleLinkList();
    void insertLinkList(int pos, CircleLinkNode *data);
    void removeLinkListPos(int pos);
    void printLinkList(PRINTLINKNODE print);
    void printLinkList();
    ~CircleLinkList();
};


#endif