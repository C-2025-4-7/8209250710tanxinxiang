#include <iostream>
#include <cstring>
using namespace std;

// 函数声明
int indexOf(const char s1[], const char s2[]);

int main() {
    const int MAX_LENGTH = 100;
    char s1[MAX_LENGTH], s2[MAX_LENGTH];

    cout << "Enter the first string: ";
    cin.getline(s1, MAX_LENGTH);

    cout << "Enter the second string: ";
    cin.getline(s2, MAX_LENGTH);

    int index = indexOf(s1, s2);

    cout << "indexOf(\"" << s1 << "\", \"" << s2 << "\") = " << index << endl;

    if (index != -1) {
        cout << "\"" << s1 << "\" 在 \"" << s2 << "\" 中的位置是: " << index << endl;
    }
    else {
        cout << "\"" << s1 << "\" 不是 \"" << s2 << "\" 的子串" << endl;
    }

    return 0;
}

// 判断s1是否是s2的子串
int indexOf(const char s1[], const char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // 如果s1比s2长，不可能成为子串
    if (len1 > len2) {
        return -1;
    }

    // 遍历s2的所有可能起始位置
    for (int i = 0; i <= len2 - len1; i++) {
        bool match = true;

        // 检查从位置i开始的子串是否与s1匹配
        for (int j = 0; j < len1; j++) {
            if (s2[i + j] != s1[j]) {
                match = false;
                break;
            }
        }

        // 如果匹配，返回起始位置
        if (match) {
            return i;
        }
    }

    // 没有找到匹配的子串
    return -1;
}