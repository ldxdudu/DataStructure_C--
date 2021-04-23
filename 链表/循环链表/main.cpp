/*
 * @Description: 循环链表
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-22 21:53:10
 */

#include "./include/CircleLinKList.h"

class Person {
public:
    CircleLinkNode Node;
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
// 模板重载，将myPrint函数模板进行重载
template<> void myPrint(CircleLinkNode *data){ 
    Person *p = (Person *) data;
    cout << "name:" << p->m_Name << " age:" << p->m_Age << " score:" << p->m_Score << endl;
}
// 正常版本
void printList(CircleLinkNode *data) {
    Person *p = (Person *) data;
    cout << "name:" << p->m_Name << " age:" << p->m_Age << " score:" << p->m_Score << endl;
}
int main() {

    Person p1("aaa", 10, 100);  
    Person p2("bbb", 20, 100);
    Person p3("ccc", 30, 100);


    CircleLinkList *list1 = new CircleLinkList;
    
    list1->insertLinkList(0, (CircleLinkNode *)&p1);
    list1->insertLinkList(0, (CircleLinkNode *)&p2);
    list1->insertLinkList(0, (CircleLinkNode *)&p3);

    list1->printLinkList(printList);
    list1->printLinkList(); // 使用函数模板的版本

    delete list1;

    return 0;
}