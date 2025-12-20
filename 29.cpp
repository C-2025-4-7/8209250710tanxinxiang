#include <iostream>
using namespace std;

const int NUM_LOCKERS = 100;
const int NUM_STUDENTS = 100;

int main() {
    bool lockers[NUM_LOCKERS] = { false };  // false表示关闭，true表示打开

    // 模拟学生操作
    for (int student = 1; student <= NUM_STUDENTS; student++) {
        for (int locker = student - 1; locker < NUM_LOCKERS; locker += student) {
            lockers[locker] = !lockers[locker];  // 改变状态
        }
    }

    // 找出所有打开的柜子
    cout << "打开的存物柜号码: ";
    int count = 0;
    for (int i = 0; i < NUM_LOCKERS; i++) {
        if (lockers[i]) {
            cout << (i + 1) << " ";
            count++;
        }
    }
    cout << endl;

    cout << "总共打开了 " << count << " 个存物柜" << endl;

   

    return 0;
}