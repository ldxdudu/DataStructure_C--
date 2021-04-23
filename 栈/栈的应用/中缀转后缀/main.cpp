/*
 * @Description: 栈的应用_中缀表达式转后缀表达式
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-22 22:17:49
 * 
 */

/*
* 左括号：进栈
* 运算符号:与栈顶符号进行优先级比较>
*   >若栈顶符号优先级低:此符号进栈(默认栈顶若是左括号,左括号优先级最低)
*   >若栈顶符号优先级不低:将栈顶符号弹出并输出,之后进栈
* 右括号:将栈顶符号弹出并输出,直到匹配左括号
*/

#include "./include/LinkStack.h"
#include <string.h>

class MyChar
{
public:
    LinkNode node;
    char *pAddr;
    int my_Index;
    char my_Str;
public:
    MyChar(char *p, int index){
        this->pAddr = p;
        this->my_Index = index;
    }
    MyChar(char str, int index) {
        this->my_Str = str;
        this->my_Index = index;
    }
};

int isLeft(char c)
{
    return c == '(';
}
int isRight(char c) {
    return c == ')';
}
void showError(char *str, int pos) {
    cout << str << endl;
    for (int i = 0; i < pos; i++) {
        cout << " ";
    }
    cout << "↑" << endl;
}
void showError(string str, int pos) {
    cout << str << endl;
    for (int i = 0; i < pos; i++) {
        cout << " ";
    }
    cout << "↑" << endl;
}
// 判断是否为数字
int isNum(char c) {
    return c >= '0' && c <= '9';
}
// 判断是不是运算符
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
// 返回运算符号的优先级
int getPriority(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}
// 数字操作
void numberOperate(char *p) {
    cout << p[0];
}
// 左括号操作
void leftOperate(LinkStack *stack, char *p) {
    MyChar *mychar = new MyChar(p, 0);
    stack->pushLinkStack((LinkNode *)mychar);
}
// 右括号操作
void rightOperate(LinkStack *stack) {
    while(stack->getSize() > 0) {
        MyChar *mychar = (MyChar *)stack->topLinkStack();
        // 如果匹配到左括号弹出
        if (isLeft(*(mychar->pAddr))) {
            stack->popLinkStack();
            delete mychar;
            mychar = NULL;
            break;
        }
        cout << *(mychar->pAddr);
        stack->popLinkStack();
        delete mychar;
        mychar = NULL;
    }
}
// 运算符操作
void operatorOperate(LinkStack *stack, char *p) {
    // 取出栈顶符号
    MyChar *mycharNode1 = (MyChar *)stack->topLinkStack();
    if (mycharNode1 == NULL)
    {
        MyChar *mychar1 = new MyChar(p, 0);
        stack->pushLinkStack((LinkNode *)mychar1);
        return;
    }
    // 如果栈顶优先级低于当前字符优先级，直接入栈
    if (getPriority(*(mycharNode1->pAddr)) < getPriority(*p)) {
        MyChar *mychar1 = new MyChar(p, 0);
        stack->pushLinkStack((LinkNode *)mychar1);
        return;
    }
    // 如果栈顶优先级不低
    else {
        while (stack->getSize() > 0) {
            MyChar *mycharNode2 = (MyChar *)stack->topLinkStack();
            // 如果优先级低，当前符号入栈
            if (getPriority(*(mycharNode2->pAddr)) < getPriority(*p)) {
                // MyChar mychar2(p, 0);
                MyChar *mychar2 = new MyChar(p, 0);
                stack->pushLinkStack((LinkNode *)mychar2);
                break;
            }
            // 输出
            cout << *(mycharNode2->pAddr);
            // 弹出
            stack->popLinkStack();
            delete mycharNode2;
            mycharNode2 = NULL;

        }
    }
}
void test() {
    char *str = "8+(3-1)*5";
    char *p = str;
    LinkStack *stack = new LinkStack;
    while (*p != '\0') {
        // 如果是数字
        if (isNum(*p)) {
            numberOperate(p);
        }
        // 如果是左括号
        if (isLeft(*p)) {
            leftOperate(stack, p);
        }
        // 如果右括号
        if (isRight(*p)) {
            rightOperate(stack);
        }
        // 如果是运算符号
        if (isOperator(*p)) {
            operatorOperate(stack, p);
        }

        p++;
    }
    while (stack->getSize() > 0) {
        MyChar *mychar = (MyChar *)stack->topLinkStack();
        cout << *mychar->pAddr;
        stack ->popLinkStack();
        delete mychar;
        mychar = NULL;
    }
    cout << endl;
    delete stack;
}

int main()
{   
    test();
    return 0;
}