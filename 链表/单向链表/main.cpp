/*
 * @Description: 单链表
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-22 16:42:04
 */

#include "./include/LinkList.h"
#include "LinkList.cpp" // 由于使用了类模板分文件编写， 需要包含.cpp源文件
#include <string>
#include <iostream>
//自定义数据类型
class Person {
public:
	std::string myName;
	int myAge;
	int myScore;
public:
	Person(std::string name, int age, int score) : myName(name), myAge(age), myScore(score) {

	}
};

// 模板重载，将myPrint函数模板进行重载
template<> void myPrint(Person *data){
	using namespace std;
	auto p = data;
	cout << "name:" << p->myName << " age:" << p->myAge << " score:" << p->myScore << endl;
}
// 模板重载，将myCompare函数模板进行重载
template<> bool myCompare(Person *data1, Person *data2) {
	if (data1->myName == data2->myName && data1->myAge == data2->myAge && data1->myScore == data2->myScore) {
		return true;
	}
	return false;
}
int main(){

	Person p1("aaa", 11, 100);
	Person p2("bbb", 22, 100);
	Person p3("ccc", 33, 100);
	Person p4("ddd", 44, 100);
	Person p5("eee", 55, 100);

	auto *list = new LinkList<Person>;
	
	list->insert(0, &p1);
	list->insert(0, &p2);
	list->insert(0, &p3);
	list->insert(0, &p4);
	list->insert(0, &p5);

	list->printLinkList(); // 打印链表

	Person p6("bbb", 22, 100);
	using namespace std;
	cout << "find p6 pos: "<< list->find(&p6) << endl;

	list->remove(2);
	cout << "链表中的元素个数：" << list->getSize() << endl;

	list->printLinkList(); // 打印链表

	delete list;
	return 0;
}