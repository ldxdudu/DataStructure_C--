/*
 * @Description: 栈的应用_后缀表达式求解 (包含中缀转后缀，和计算后缀表达式两个部分, 并使用STL中的stack容器)              
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-22 22:19:06
 */

/*
 *遍历后缀表达式中的数字和符号
 *  对于数字:进栈
 *  对于符号:从栈中弹出右操作数从栈中弹出左操作数，
 *          根据符号进行运算将运算结果压入栈中遍历结束:栈中的唯一数字为计算结果。
*/


#include <iostream>
using namespace std;
#include <string>
#include <stack>
#include <algorithm>
#include <cstdlib>
bool isNum(char ch) {
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}
int calculateNum(int ch1, int ch2, char operation) {
    int ret = 0;
    switch (operation) {
        case '+':
            ret = ch1 + ch2;
            break;
        case '-':
            ret = ch1 - ch2;
            break;
        case '*':
            ret = ch1 * ch2;
            break;
        case '/':
            ret = ch1 / ch2;
            break;
        default:
            break;
    }
    return ret;
}
void test(string ret) {
    // string str = "831-5*+";
    string str = ret;
    stack<int> stk;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (isNum(str[i])) {
            int intNum = str[i] - '0'; // 转数字
            stk.push(intNum);
        }
        else {
            int rightInt = stk.top();
            stk.pop();
            int leftInt = stk.top();
            stk.pop();
            int ret = calculateNum(leftInt, rightInt, str[i]);
            stk.push(ret);
        }
    }
    if (stk.size() == 1) {
        cout << "后缀表达式运算结果为：" << stk.top() << endl;
    }
}
int getPriority(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}
string test02() {
    string str = "8+(3-1)*5";
    cout << "中缀表达式：" << str << endl;
    string ret;
    stack<char> stk1;

    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (isNum(str[i])) {
            ret += str[i];
        }
        if (str[i] == '(') { // 如果是左括号进栈
            stk1.push(str[i]);
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') { // 如果是运算符
            if (stk1.empty()) {
                stk1.push(str[i]); //入栈
            }
            else if(getPriority(stk1.top()) < str[i]) {
                stk1.push(str[i]); //入栈
            }
            else {
                while (!stk1.empty()) {
                    if (getPriority(stk1.top()) < str[i]) {
                        stk1.push(str[i]); //入栈
                        break;
                    }
                    ret += stk1.top();
                    stk1.pop();
                }
            }
        }
        if (str[i] == ')') { // 如果是右括号
            while (!stk1.empty()) {
                if (stk1.top() == '(') {
                    stk1.pop();
                    break;
                }
                ret += stk1.top();
                stk1.pop();
            }
        }
    }
    while (!stk1.empty()) {
        ret += stk1.top();
        stk1.pop();           
    }
    cout << "中缀转后缀：" << ret << endl;
    return ret;
}
int main()
{
    string ret =  test02(); // 中缀表达式转后缀后缀表达式
    test(ret); // 计算后缀表达式结果
    return 0;
}