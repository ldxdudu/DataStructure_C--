/*
 * @Description: 栈的应用_就近匹配
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-22 22:17:57
 */


#include "./include/LinkStack.h"
#include <string.h>
class MyChar {
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

int isLeft(char c) {
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
int main()
{   
    // char *实现
    // LinkStack *stack = new LinkStack;
    // char *str = "1+2+5(ed*uj))s)((";
    // char *p = str;
    // int index = 0;
    // while (*p != '\0') {
    //     // 如果左括号，直接进栈
    //     if (isLeft(*p)) {
    //         MyChar mychar(p, index);
    //         stack->pushLinkStack((LinkNode *)&mychar);
    //     }
    //     // 如果是右括号，从栈顶弹出元素，判断不是左括号
    //     if (isRight(*p)) {
    //         if (!stack->isEmpty()) {
    //             MyChar *mychar = (MyChar *)stack->topLinkStack();
    //             if (isLeft(*(mychar->pAddr))) {
    //                 stack->popLinkStack();
    //             }
                
    //         }
    //         else {
    //             cout << "右括号没有匹配的左括号" << endl;
    //             showError(str, index);
    //         }
    //     }
    //     p++;
    //     index++;
    // }
    // while (stack->getSize() > 0) {
    //     cout << "左括号没有匹配的右括号" << endl;
    //     MyChar *mychar = (MyChar *)stack->topLinkStack();
    //     showError(str, mychar->my_Index);
    //     stack->popLinkStack();
    // }

    // delete stack;
    
    // string 容器实现
    LinkStack *stack = new LinkStack;

    string str1 = "1+2+5(ed*uj))s)((";

    unsigned int index = 0;

    for (unsigned int p = 0; p < str1.size(); p++) {
        // 如果左括号，直接进栈
        if (isLeft(str1[p]))
        {
            MyChar mychar(str1[p], index);
            stack->pushLinkStack((LinkNode *)&mychar);
        }
        // 如果是右括号，从栈顶弹出元素，判断不是左括号
        if (isRight(str1[p]))
        {
             if (!stack->isEmpty())
            {
                MyChar *mychar = (MyChar *)stack->topLinkStack();
                if (isLeft(mychar->my_Str))
                {
                    stack->popLinkStack();
                }
            }
            else
                {
                    cout << "右括号没有匹配的左括号" << endl;
                    showError(str1, index);
                }
            }
        index++;
    }
    while (stack->getSize() > 0) {
        cout << "左括号没有匹配的右括号" << endl;
        MyChar *mychar = (MyChar *)stack->topLinkStack();
        showError(str1, mychar->my_Index);
        stack->popLinkStack();
    }

    delete stack;

    return 0;
}