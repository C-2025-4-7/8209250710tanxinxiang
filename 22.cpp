
	//   **** * 不会不会不会不会不会不会
//	*	    不会不会不会不会不会不会
 ///     *      不会不会不会不会不会不会
  //    *     		          不会不会不会不会不会不会不会不会不会不会不会不会
	//	 *              不会不会不会不会不会不会不会不会不会不会不会不会
	//	   *                           不会不会不会不会不会不会
	//		*      不会不会不会不会不会不会
	//		8 *           不会不会不会不会不会不会
	//		8           不会不会不会不会不会不会
//		*	不会不会不会不会不会不会
	//		            不会不会不会不会不会不会
	
			
          // AI真好用 AI真好用 AI真好用 AI真好用 AI真好用 AI真好用 AI真好用 AI真好用 AI真好用 AI真好用 AI真好用 AI真好用//
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
              using namespace std;

          // 函数声明
          int indexof(const char* s1, const char* s2);
          int parseHex(const char* const hexString);
          void sortArray(int* arr, int size);
          void printArray(const int* arr, int size);

          int main() {
              cout << "=== 程序设计实验 ===" << endl << endl;

              // (1) 检查子串
              cout << "1. 检查子串" << endl;
              cout << "----------------------------------" << endl;
              {
                  char s1[100], s2[100];
                  cout << "请输入字符串 s1: ";
                  cin.ignore();  // 清除缓冲区
                  cin.getline(s1, 100);

                  cout << "请输入字符串 s2: ";
                  cin.getline(s2, 100);

                  int result = indexof(s1, s2);
                  if (result != -1) {
                      cout << "\"" << s1 << "\" 是 \"" << s2 << "\" 的子串，第一次出现的位置是: " << result << endl;

                      // 可视化显示匹配位置
                      cout << "s2: " << s2 << endl;
                      cout << "    ";
                      for (int i = 0; i < result; i++) cout << " ";
                      cout << "^ (起始位置)" << endl;
                      cout << "    ";
                      for (int i = 0; i < result; i++) cout << " ";
                      for (int i = 0; i < strlen(s1); i++) cout << "~";
                      cout << endl;
                  }
                  else {
                      cout << "\"" << s1 << "\" 不是 \"" << s2 << "\" 的子串" << endl;
                  }
              }
              cout << endl;

              // (2) 十六进制转十进制
              cout << "2. 十六进制转十进制" << endl;
              cout << "----------------------------------" << endl;
              {
                  char hexStr[100];
                  cout << "请输入一个十六进制数: ";
                  cin.getline(hexStr, 100);

                  int decimal = parseHex(hexStr);
                  if (decimal != -1) {
                      cout << "十六进制 " << hexStr << " 转换为十进制是: " << decimal << endl;
                      cout << "验证: 0x" << hexStr << " = " << decimal << endl;
                  }
                  else {
                      cout << "输入的不是有效的十六进制数!" << endl;
                  }

                  // 测试用例
                  cout << "\n测试用例:" << endl;
                  cout << "parseHex(\"A5\") = " << parseHex("A5") << " (预期: 165)" << endl;
                  cout << "parseHex(\"FF\") = " << parseHex("FF") << " (预期: 255)" << endl;
                  cout << "parseHex(\"1A3\") = " << parseHex("1A3") << " (预期: 419)" << endl;
                  cout << "parseHex(\"100\") = " << parseHex("100") << " (预期: 256)" << endl;
              }
              cout << endl;

              // (3) 动态数组排序
              cout << "3. 动态数组排序" << endl;
              cout << "----------------------------------" << endl;
              {
                  int size;
                  cout << "请输入数组元素个数: ";
                  cin >> size;

                  if (size <= 0) {
                      cout << "数组大小必须为正数!" << endl;
                      return 1;
                  }

                  // 动态分配数组
                  int* arr = new int[size];

                  cout << "请输入 " << size << " 个整数:" << endl;
                  for (int i = 0; i < size; i++) {
                      cout << "元素[" << i << "]: ";
                      cin >> arr[i];
                  }

                  cout << "\n原始数组（指针方式输出）: ";
                  printArray(arr, size);

                  // 显示指针和内容信息
                  cout << "\n指针信息:" << endl;
                  cout << "数组首地址: " << arr << endl;
                  cout << "指针大小: " << sizeof(arr) << " 字节" << endl;
                  cout << "元素大小: " << sizeof(*arr) << " 字节/元素" << endl;

                  // 排序
                  sortArray(arr, size);

                  cout << "\n排序后数组（指针方式输出）: ";
                  printArray(arr, size);

                  // 释放内存
                  delete[] arr;
                  arr = nullptr;  // 避免悬空指针
                  cout << "动态数组内存已释放" << endl;
              }

              return 0;
          }

          // (1) 检查子串函数
          int indexof(const char* s1, const char* s2) {
              // 如果s1为空字符串，约定返回0
              if (s1 == nullptr || strlen(s1) == 0) {
                  return 0;
              }

              // 如果s2为空字符串或比s1短
              if (s2 == nullptr || strlen(s2) < strlen(s1)) {
                  return -1;
              }

              int len1 = strlen(s1);
              int len2 = strlen(s2);

              // 遍历s2的所有可能起始位置
              for (int i = 0; i <= len2 - len1; i++) {
                  bool match = true;

                  // 比较s1和s2从位置i开始的子串
                  for (int j = 0; j < len1; j++) {
                      if (s2[i + j] != s1[j]) {
                          match = false;
                          break;
                      }
                  }

                  // 如果匹配成功，返回起始位置
                  if (match) {
                      return i;
                  }
              }

              return -1;  // 未找到匹配
          }

          // (2) 十六进制转十进制函数
          int parseHex(const char* const hexString) {
              if (hexString == nullptr || strlen(hexString) == 0) {
                  return -1;  // 无效输入
              }

              int result = 0;
              int len = strlen(hexString);

              // 从最高位开始处理
              for (int i = 0; i < len; i++) {
                  char c = hexString[i];
                  int digit;

                  // 转换为大写便于处理
                  c = toupper(c);

                  // 转换字符为对应的数值
                  if (c >= '0' && c <= '9') {
                      digit = c - '0';
                  }
                  else if (c >= 'A' && c <= 'F') {
                      digit = 10 + (c - 'A');
                  }
                  else {
                      return -1;  // 非法字符
                  }

                  // 计算十进制值
                  result = result * 16 + digit;
              }

              return result;
          }

          // (3) 数组排序函数（使用指针）
          void sortArray(int* arr, int size) {
              // 使用冒泡排序算法
              for (int i = 0; i < size - 1; i++) {
                  for (int j = 0; j < size - 1 - i; j++) {
                      // 使用指针比较相邻元素
                      if (*(arr + j) > *(arr + j + 1)) {
                          // 交换元素
                          int temp = *(arr + j);
                          *(arr + j) = *(arr + j + 1);
                          *(arr + j + 1) = temp;
                      }
                  }
              }
          }

          // 使用指针方式输出数组
          void printArray(const int* arr, int size) {
              if (arr == nullptr || size <= 0) {
                  cout << "[]" << endl;
                  return;
              }

              cout << "[";
              for (int i = 0; i < size; i++) {
                  cout << *(arr + i);  // 使用指针访问
                  if (i < size - 1) {
                      cout << ", ";
                  }
              }
              cout << "]" << endl;
          }

          // 附加功能：使用标准库排序（可选）
          void sortArraySTL(int* arr, int size) {
              sort(arr, arr + size);
          }