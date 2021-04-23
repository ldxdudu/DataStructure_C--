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

class CircleLinkList {
private:
    int size;
    CircleLinkNode *head;

typedef  void (*PRINTLINKNODE)(CircleLinkNode *data);
typedef  bool (*COMPAERNODE)(CircleLinkNode *data1, CircleLinkNode *data2);

public:
    CircleLinkList();
    void insertLinkList(int pos, CircleLinkNode *data);
    void removeLinkListPos(int pos);
    void removeLinkListVal(CircleLinkNode *data, COMPAERNODE compare);
    void printLinkList(PRINTLINKNODE print);
    CircleLinkNode *getHead();
    int getSize();
    ~CircleLinkList();
    CircleLinkNode *getFront();
};
#endif