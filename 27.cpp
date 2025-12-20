#include<iostream>
#include<iomanip>
#include"mytriangle.h"
using namespace std;
int main() {
	double a, b, c;
	cout << "三角形三边:";
	cin >> a >> b >> c;
	if (is_valid(a, b, c)) {
		double area = triangle_area(a, b, c);
		cout << fixed << setprecision(2);
		cout << "面积：" << area << endl;
	}
	else {
		cout << "不是三角形" << endl;
	}
	return 0;
}