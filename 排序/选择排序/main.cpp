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

// 选择排序减少了交换次数
void selectSort(int arr[], int length) {
    int min = 0;
    for (int i = 0; i < length; i++) {
        min = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr[min], arr[i]);
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
    cout << "排序前：" << endl;
    // printArray(arr, MAX);
    cout << "排序后：" << endl;
    long tStart = getSystemTime();
    selectSort(arr, MAX);
    long tEnd = getSystemTime();
    cout << "选择排序" << MAX << "个元素，所需时间: " << tEnd - tStart << "ms" << endl;
    // printArray(arr, MAX);

}