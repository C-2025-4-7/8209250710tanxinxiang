#include <iostream>
using namespace std;

const int MAX_SIZE = 80;

// 函数声明
void merge(const int list1[], int size1, const int list2[], int size2, int list3[]);
void printArray(const int arr[], int size);

int main() {
    int list1[MAX_SIZE], list2[MAX_SIZE];
    int size1, size2;

    // 输入第一个数组
    cout << "Enter list1: ";
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        cin >> list1[i];
    }

    // 输入第二个数组
    cout << "Enter list2: ";
    cin >> size2;
    for (int i = 0; i < size2; i++) {
        cin >> list2[i];
    }

    // 合并后的数组
    int list3[size1 + size2];

    // 合并两个数组
    merge(list1, size1, list2, size2, list3);

    // 输出结果
    cout << "The merged list is ";
    printArray(list3, size1 + size2);

    return 0;
}

// 合并两个已排序数组
void merge(const int list1[], int size1, const int list2[], int size2, int list3[]) {
    int i = 0, j = 0, k = 0;
    int comparisons = 0;  // 记录比较次数

    // 比较两个数组的元素，将较小的放入list3
    while (i < size1 && j < size2) {
        comparisons++;
        if (list1[i] <= list2[j]) {
            list3[k++] = list1[i++];
        }
        else {
            list3[k++] = list2[j++];
        }
    }

    // 如果list1还有剩余元素
    while (i < size1) {
        list3[k++] = list1[i++];
    }

    // 如果list2还有剩余元素
    while (j < size2) {
        list3[k++] = list2[j++];
    }

    cout << "总共进行了 " << comparisons << " 次比较" << endl;
    cout << "比较次数小于等于 " << (size1 + size2) << " 次" << endl;
}

// 打印数组
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << endl;
}