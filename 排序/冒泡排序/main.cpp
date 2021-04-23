#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <sys/timeb.h>

const int MAX = 10000;

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

void bubbleSort(int arr[], int length) {
    bool flag = false; // 标识没有排序好
    for (int i = 0; i < length && flag == false; i++) {
        flag = true;
        for (int j = length - 1; j > i ; j--) {
            if (arr[j - 1] < arr[j]) {
                flag = false;
                swap(arr[j], arr[j - 1]);
            }
        }
    } 

}
// 打印函数
void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}
int main() {
    int arr[MAX];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX;
    }
    // cout << "排序前：" << endl;
    // printArray(arr, MAX);
    // cout << "排序后：" << endl;
    long tStart = getSystemTime();
    bubbleSort(arr, MAX);
    long tEnd = getSystemTime();
    cout << "冒泡排序" << MAX << "个元素，所需时间: " << tEnd - tStart << "ms" << endl;
    // printArray(arr, MAX);
}