#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__
#include <iostream>
using namespace std;
#include <string>
#include <cstdio>

class LinkNode {
public: 
    LinkNode *next;
};

class LinkQueue {
private:
    LinkNode head;
    int size;
public:
    LinkQueue();
    ~LinkQueue();
    void pushLinkQueue(LinkNode *data);
    void popLinkQueue();
    LinkNode *frontLinkQueue() const;
    LinkNode *backLinkQueue();
    int getSize() const;
    void clearLKQueue();
};
#endif // __LINKQUEUE_H__