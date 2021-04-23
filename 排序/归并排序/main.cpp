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
// 在堆上创建一个随机数组
int *createArray() {
    auto *arr = new int[MAX];
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX;
    }
    return arr;
}
// 合并算法
void merge(int arr[], int start, int end, int mid, int *temp) {
    int i_start = start;
    int i_end = mid;
    int j_start = mid + 1;
    int j_end = end;
    int length = 0; // 表示辅助空间有多少个辅助元素
    // 合并两个有序序列
    while (i_start <= i_end && j_start <= j_end) {
        if (arr[i_start] < arr[j_start]) {
            temp[length] = arr[i_start];
            i_start++;
            length++;
        }
        else {
            temp[length] = arr[j_start];
            j_start++;
            length++;
        }
    }
    // i序列
    while (i_start <= i_end) {
        temp[length] = arr[i_start];
        i_start++;
        length++;
    }
    // j序列
    while (j_start <= j_end) {
        temp[length] = arr[j_start];
        j_start++;
        length++;
    }
    // 把辅助空间的元素覆盖到原空间中
    for (int i = 0; i < length; i++) {
        arr[start + i] = temp[i];
    }
}
// 归并排序
void mergeSort(int array[], int start, int end, int *temp) {
    if (start >= end) {
        return;
    }
    
    int mid = (start + end) / 2;
    // 分组
    mergeSort(array, start, mid, temp); // 左半边
    mergeSort(array, mid + 1, end, temp); // 右半边
    // 合并
    merge(array, start, end, mid, temp); //


}
int main() {

    srand((unsigned int)time(NULL));
    int *arr = createArray();
    // 申请辅助空间
    int *temp = new int[MAX];

    printArray(arr, MAX);
    mergeSort(arr, 0, MAX, temp);
    printArray(arr, MAX);

    // cout << "排序前：" << endl;
    // cout << "排序后：" << endl;
    // long tStart = getSystemTime();
    // mergeSort1(arr, 0, MAX, temp);
    // long tEnd = getSystemTime();
    // cout << "归并排序" << MAX << "个元素，所需时间: " << tEnd - tStart << "ms" << endl;


    delete[] temp;
    delete[] arr;
}