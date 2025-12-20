'#include <iostream>
using namespace std;

int main() {
    int a, b, temp, gcd, lcm;
    int x, y;

    cout << "请输入两个正整数: ";
    cin >> a >> b;

    x = a;
    y = b;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;

    lcm = x * y / gcd;

    cout << "最大公约数: " << gcd << endl;
    cout << "最小公倍数: " << lcm << endl;

    return 0;
}