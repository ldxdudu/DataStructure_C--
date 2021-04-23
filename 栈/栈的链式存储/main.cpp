/*
 * @Description: 栈的链式存储
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-22 22:16:26
 */

#include "./include/LinkStack.h"

class Person{
public:
    LinkNode *node;
    string m_Name;
    int m_Age;
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
};

int main () {

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    LinkStack *stack = new LinkStack;
    stack->pushLinkStack((LinkNode *)&p1);
    stack->pushLinkStack((LinkNode *)&p2);
    stack->pushLinkStack((LinkNode *)&p3);
    stack->pushLinkStack((LinkNode *)&p4);
    stack->pushLinkStack((LinkNode *)&p5);

    cout << "堆栈元素的个数：" << stack->getSize() << endl;

    if (stack->isEmpty()) {
        cout << "堆栈为空" << endl;
    }
    else {
        cout << "堆栈不为空" << endl;
    }
    
    // stack->clearLinkStack();

    while (stack->getSize() > 0) {
        
        Person *p1 = (Person *)stack->topLinkStack();
        cout << "name: " << p1->m_Name << " age: " << p1->m_Age << endl;
        stack->popLinkStack();
    }

    cout << "堆栈元素的个数：" << stack->getSize() << endl;

    if (stack->isEmpty()) {
        cout << "堆栈为空" << endl;
    }
    else {
        cout << "堆栈不为空" << endl;
    }

    delete stack;

    return 0;
}