#include <iostream>
using namespace std;

const int SIZE = 10;

// 函数声明
void printDistinctNumbers(int arr[], int size);

int main() {
    int numbers[SIZE];
    int distinct[SIZE] = { 0 };  // 存储不同数的数组，初始化为0
    int distinctCount = 0;     // 不同数的个数

    cout << "请输入10个整数: ";

    // 读取10个数
    for (int i = 0; i < SIZE; i++) {
        cin >> numbers[i];

        // 检查当前数是否已经在distinct数组中
        bool isDuplicate = false;
        for (int j = 0; j < distinctCount; j++) {
            if (distinct[j] == numbers[i]) {
                isDuplicate = true;
                break;
            }
        }

        // 如果不是重复的数，则添加到distinct数组中
        if (!isDuplicate) {
            distinct[distinctCount] = numbers[i];
            distinctCount++;
        }
    }

    // 输出不同的数
    cout << "不同的数有: ";
    for (int i = 0; i < distinctCount; i++) {
        cout << distinct[i] << " ";
    }
    cout << endl;

    return 0;
}

