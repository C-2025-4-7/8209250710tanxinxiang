#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    void setPoint(int i, int j) {
        x = 60 + i;
        y = 80 + j;
    }
    void display() {
        cout << "坐标：(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p(60, 80);
    cout << "初始坐标：";
    p.display();

    int m, n;
    cin >> m >> n;

    p.setPoint(m, n);
    cout << "修改后坐标：";
    p.display();

    return 0;
}