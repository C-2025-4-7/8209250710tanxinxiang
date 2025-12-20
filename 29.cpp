#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// 函数声明
void bubbleSort(int arr[], int size);
void printArray(int arr[], int size);
void generateRandomArray(int arr[], int size, int min, int max);
void swap(int& a, int& b);

int main() {
    const int SIZE = 10;
    int numbers[SIZE];

    // 生成随机数组
    srand(time(0));  // 设置随机种子
    generateRandomArray(numbers, SIZE, 1, 100);

    cout << "排序前的数组: ";
    printArray(numbers, SIZE);

    // 执行冒泡排序
    bubbleSort(numbers, SIZE);

    cout << "排序后的数组: ";
    printArray(numbers, SIZE);

    return 0;
}

// 交换两个数的值
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 冒泡排序函数
void bubbleSort(int arr[], int size) {
    bool changed = true;

    // 外层循环控制排序趟数
    for (int i = 0; i < size - 1 && changed; i++) {
        changed = false;

        // 内层循环进行相邻元素比较
        // 注意：j < size - 1 - i，因为每一趟都会把最大的数"沉"到最后
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                changed = true;
            }
        }

        // 显示每一趟排序后的结果
        cout << "第" << i + 1 << "趟排序后: ";
        printArray(arr, size);
    }
}

// 使用do-while循环的冒泡排序版本
void bubbleSortDoWhile(int arr[], int size) {
    bool changed;

    do {
        changed = false;

        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                changed = true;
            }
        }
    } while (changed);
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// 生成随机数组
void generateRandomArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}