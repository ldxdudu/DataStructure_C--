/*
 * @Description: 队列的顺序存储 (使用.hpp将声明和实现写到了同一个文件里)
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-23 10:09:54
 */


#include "./include/SeqQueue.hpp"

class Person {
public:
    string m_Name;
    int m_Age;
public:
    Person(string name, int age) : m_Name(name), m_Age(age){

    }
};

int main() {

    Person p1 = Person("aaa", 10);
    Person p2 = Person("bbb", 20);
    Person p3 = Person("ccc", 30);
    Person p4 = Person("ddd", 40);
    Person p5 = Person("eee", 50);
    // 使用Person型队列
    SeqQueue<Person> *queue = new SeqQueue<Person>;

    queue->pushQueue(&p1);
    queue->pushQueue(&p2);
    queue->pushQueue(&p3);
    queue->pushQueue(&p4);
    queue->pushQueue(&p5);
    cout << "队列元素数目:" << queue->getSize() << endl;
    while (queue->getSize() > 0) {
        Person *p = queue->frontQueue();
        cout << p->m_Name << " " << p->m_Age << endl;
        queue->popQueue();
    }
    cout << "队列元素数目:" << queue->getSize() << endl;
    delete queue;
    return 0;
}