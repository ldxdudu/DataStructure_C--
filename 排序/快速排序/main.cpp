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
// 快速排序 分治法 + 挖坑填数
void quickSort(int arr[], int start, int end) {
    int i = start;
    int j = end;
    int temp = arr[start]; // 基准数
    if (i < j)
    {
        while (i < j) {
            // 从右向左找比基准数小的数
            while (i < j && arr[j] >= temp) {
                j--;
            }
            // 填坑
            // if (i < j) {
            //     arr[i] = arr[j];
            //     i++;
            // }
            swap(arr[i], arr[j]); // 讲小于基准数的数与挖的坑做交换
            // 从左向右找比基准数大的数
            while (i < j && arr[i] <= temp) {
                i++;
            }
            // 填坑
            // if (i < j) {
            //     arr[j] = arr[i];
            //     j--;
            // }
            swap(arr[i], arr[j]);
        }
        // 把基准数放到 i=j 的位置
        arr[i] = temp;
        // 对左半部分进行快速排序
        quickSort(arr, start, i - 1);
        // 对右半部分进行快速排序
        quickSort(arr, i + 1, end);
    }
}
int pivotPar(int array[], int start, int end) {
    int i = start;
    int j = end;
    int pivotKey = array[i];
    while (i < j) {
        while (i < j && array[j] > pivotKey) {
            j--;
        }
        swap(array[j], array[i]);
        while (i < j && array[i] < pivotKey) {
            i++;
        }
        swap(array[i], array[j]);
    }
    return i;
}
void quickSort1(int array[], int start, int end) {
    int i = start;
    int j = end;
    int pivot;
    if (i < j) {
        pivot = pivotPar(array, i, j);
        quickSort1(array, i, pivot - 1); // 左
        quickSort1(array, pivot + 1, j); // 右
    }
}
int main() {
    int arr[MAX];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX;
    }
    int myArr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int length = sizeof(myArr) / sizeof(int);
    printArray(myArr, length);
    quickSort1(myArr, 0, length);
    printArray(myArr, length);
    // cout << "排序前：" << endl;
    // printArray(arr, MAX);
    // cout << "排序后：" << endl;
    // long tStart = getSystemTime();
    // quickSort(arr, 0, MAX);
    // long tEnd = getSystemTime();
    // cout << "快速排序" << MAX << "个元素，所需时间: " << tEnd - tStart << "ms" << endl;
    // printArray(arr, MAX);
}