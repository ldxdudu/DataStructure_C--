#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <sys/timeb.h>

const int MAX = 10;

long getSystemTime() {
    struct timeb tb;
    ftime(&tb);
    return tb.time * 1000 + tb.millitm; // 精确到毫秒 1s = 1000ms
}

void InsertSort(int arr[], int length) {
    int j;
    for (int i = 1; i < length; i++)
    {
        if (arr[i] < arr[i -1 ]) {
            int temp = arr[i]; // 先缓存
            for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
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
    printArray(arr, MAX);
    cout << "排序后：" << endl;
    long tStart = getSystemTime();
    InsertSort(arr, MAX);
    long tEnd = getSystemTime();
    cout << "插入排序" << MAX << "个元素，所需时间: " << tEnd - tStart << "ms" << endl;
    printArray(arr, MAX);
}