#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// 函数声明
void countLetters(const char str[], int counts[]);
void printCounts(const int counts[]);

int main() {
    const int MAX_LENGTH = 100;
    const int ALPHABET_SIZE = 26;
    char str[MAX_LENGTH];
    int counts[ALPHABET_SIZE] = { 0 };  // 初始化所有计数为0

    cout << "请输入一个字符串: ";
    cin.getline(str, MAX_LENGTH);

    // 统计字母出现次数
    countLetters(str, counts);

    // 输出统计结果
    cout << "\n字母出现次数统计:" << endl;
    printCounts(counts);

    return 0;
}

// 统计字符串中每个字母出现的次数
void countLetters(const char str[], int counts[]) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        // 只统计字母，忽略大小写
        if (isalpha(str[i])) {
            char lowerChar = tolower(str[i]);
            int index = lowerChar - 'a';  // 计算索引：'a'->0, 'b'->1, ..., 'z'->25
            if (index >= 0 && index < 26) {
                counts[index]++;
            }
        }
    }
}

// 打印统计结果
void printCounts(const int counts[]) {
    cout << "字母\t次数\t直方图" << endl;
    cout << "------------------------" << endl;

    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            char letter = 'a' + i;
            cout << letter << "\t" << counts[i] << "\t";

            // 打印直方图
            for (int j = 0; j < counts[i]; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // 另一种显示方式：所有字母（包括出现0次的）
    cout << "\n完整统计（所有字母）:" << endl;
    for (int i = 0; i < 26; i++) {
        char letter = 'a' + i;
        cout << letter << ": " << counts[i];

        if (i < 25 && (i + 1) % 5 == 0) {
            cout << endl;
        }
        else if (i < 25) {
            cout << "\t";
        }
    }
    cout << endl;
}

// 扩展版本：统计所有字符（包括非字母）
void countAllCharacters(const char str[], int ascii_counts[]) {
    // 初始化ASCII字符计数数组
    for (int i = 0; i < 128; i++) {
        ascii_counts[i] = 0;
    }

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 0 && str[i] < 128) {
            ascii_counts[static_cast<int>(str[i])]++;
        }
    }

    cout << "\n所有字符出现次数（ASCII 0-127）:" << endl;
    cout << "字符\tASCII\t次数" << endl;
    cout << "------------------------" << endl;

    for (int i = 0; i < 128; i++) {
        if (ascii_counts[i] > 0) {
            if (i >= 32 && i <= 126) {  // 可打印字符
                cout << static_cast<char>(i) << "\t" << i << "\t" << ascii_counts[i] << endl;
            }
            else {  // 控制字符等
                cout << "\\" << i << "\t" << i << "\t" << ascii_counts[i] << endl;
            }
        }
    }
}