#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <sys/timeb.h>

const int MAX = 100000;

long getSystemTime() {
    struct timeb tb;
    ftime(&tb);
    return tb.time * 1000 + tb.millitm; // 精确到毫秒 1s = 1000ms
}
// 交换函数
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// 打印函数
void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}
// 在堆上创建一个随机数组
int *createArray() {
    auto *arr = new int[MAX];
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX;
    }
    return arr;
}
/*
* @param myArr 待调整的数组
* @param index 待调整的结点的下标
* @param len 数组的长度
*/
void heapJust(int myArr[], int index, int len) {
    // 先保存当前节点的下标
    int max = index;
    int lchild = index * 2 + 1; // +1 下标从0开始； 任意结点（非叶子结点）左子树 = 2 * i，右子树 = 2 * i + 1
    int rchild = index * 2 + 2;
    if (lchild < len && myArr[lchild] > myArr[max]) { 
        max = lchild;
    }
    if (rchild < len && myArr[rchild] > myArr[max]) {
        max = rchild;
    }
    if (max != index) {
        // 交换连个结点
        swap(myArr[index], myArr[max]);
        heapJust(myArr, max, len);
    }
}
void heapSort(int array[], int length) {
    // 初始化堆 大顶堆：从小到大
    for (int i = length / 2 - 1; i >= 0; i--) { // 最大的非叶子节点下标 length/2
        heapJust(array, i, length);
    }
    // 交换堆顶元素和最后一个元素
    for (int i = length - 1; i >= 0; i--) {
        swap(array[i], array[0]);
        heapJust(array, 0, i); // 从堆顶元素到第i个元素进行调整
    }
}
int main() {

    srand((unsigned int)time(NULL));
    int *arr = createArray();
    // 申请辅助空间
    int *temp = new int[MAX];

    // printArray(arr, MAX);
    // heapSort(arr, MAX);
    // printArray(arr, MAX);

    cout << "排序前：" << endl;
    cout << "排序后：" << endl;
    long tStart = getSystemTime();
    heapSort(arr, MAX);
    long tEnd = getSystemTime();
    cout << "归并排序" << MAX << "个元素，所需时间: " << tEnd - tStart << "ms" << endl;


    delete[] temp;
    delete[] arr;
}