/*
 * @Description: 队列的链式存储
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-23 10:09:33
 */

#include "./include/LinkQueue.h"

class Person {
public:
    LinkNode Node;
    string m_Name;
    int m_Age;
    int m_Score;
public:
    Person(string name, int age, int score) {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Score = score;
    }
};


int main () {

    Person p1("aaa", 10, 100);  
    Person p2("bbb", 20, 100);
    Person p3("ccc", 30, 100);

    LinkQueue queue;
    queue.pushLinkQueue((LinkNode *)&p1);
    queue.pushLinkQueue((LinkNode *)&p2);
    queue.pushLinkQueue((LinkNode *)&p3);
    LinkNode *data = queue.backLinkQueue();
    Person *p = (Person *) data;
    cout << "name:" << p->m_Name << " age:" << p->m_Age << " score:" << p->m_Score << endl;


    while (queue.getSize() > 0) {
        LinkNode *data = queue.frontLinkQueue();
        Person *p = (Person *) data;
        cout << "name:" << p->m_Name << " age:" << p->m_Age << " score:" << p->m_Score << endl;
        queue.popLinkQueue();
    }

    return 0;
}