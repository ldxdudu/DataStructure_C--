/*
 * @Description: 动态数组
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-22 16:13:45
 */

#include "./include/DynamicArray.h"

int main() {
    DynamicArray array;
    
    for (int i = 0; i < 20; i++) {
        array.pushBackArray(i);
    }
    array.showArray();          // 打印生成的数组
    array.insertArray(15, 100); // 在数组下标为 '15' 处，插入值 '100'
    array.showArray();
    cout << array.findArrayPos(5) << endl; 
    array.removeArrayPos(5);
    array.removeArrayVal(6);
    array.showArray();
    int value = 0;
    if (array.atArray(2, value)) {
        cout << value << endl;
    }
    array.popBackArray();
    array.showArray();
    return 0;
}