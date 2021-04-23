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


void shellSort(int arr[], int length) {
    int increment = length;
    int i, j, k;
    do
    {
        // 确定分组的增量
        increment = increment / 3 + 1;
        for (i = 0; i < increment; i++) {
            for (j = i + increment; j < length; j += increment) {
                if (arr[j] < arr[j - increment]) {
                    int temp = arr[j];
                    for (k = j - increment; k >= 0 && temp < arr[k]; k -= increment) {
                        arr[k + increment] = arr[k];
                    }
                    arr[k + increment] = temp;
                }
            }
        }
    } while (increment > 1);
}
void shellSort1(int array[], int length) {
    int increment = length;
    int i,j,k;
    do {
        increment = increment / 3 + 1;
        for (i = 0; i < increment; i++) {
            for (j = i + increment; j < length; j += increment) {
                if (array[j] < array[j - increment]) {
                    int temp = array[j];
                    for (k = j - increment; k >= 0 && temp < array[k]; k -= increment) {
                        array[k + increment] = array[k];
                    }
                    array[k + increment] = temp;
                }
            }
        }
    } while (increment > 1);
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
    shellSort1(arr, MAX);
    long tEnd = getSystemTime();
    cout << "插入排序" << MAX << "个元素，所需时间: " << tEnd - tStart << "ms" << endl;
    printArray(arr, MAX);
}