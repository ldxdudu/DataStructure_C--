/*
 * @Description: 
 * @Version: 1.0
 * @Autor: LDX
 * @Date: 2021-04-22 16:13:45
 */
#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__
#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include <cstdlib>
class DynamicArray {
private:
    int size;
    int capacity;
    int *pAddr;
public:
    DynamicArray();
    ~DynamicArray();
    // 尾插
    void pushBackArray(int value);
    // 在指定位置插入一个数据
    void insertArray(int pos, int value);
    // 尾删
    void popBackArray();
    // 据位置删除
    void removeArrayPos(int pos);
    // 根据值删除
    void removeArrayVal(int value);
    // 清空数组
    void clearArray();
    // 查找
    int findArrayPos(int value);
    // 获得动态数组中当前元素的个数
    int getSizeArray();
    // 获得数组容量
    int getCapactity();
    // 获得某个位置的元素的值是否为输入的值
    bool atArray(int pos, int& value);
    // 打印数组
    void showArray();
};
#endif // __DYNAMICARRAY_H__
