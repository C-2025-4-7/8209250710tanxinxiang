#include<iostream>
using namespace std;
int main()
{
	double a, b, c,C;
	cout << "三角形三边;" <<endl;
	cout << "a=" << endl;
	cin >> a >> endl;
	cout << "b=" << endl;
	cin >> b >> endl;
	cout << "c=" << endl;
	cin >> c >> endl;
	if (a + b > c && a + c > b && b + c > a) 
	{
		C = a + b + c;
		cout << "周长" << C << endl;
		if (a == b || a == c || b == c) {
			cout << "等腰三角形" << endl;
		}
		else {
			cout << "不是等腰三角形" << endl;
		}
	else {
		cout << "不是三角形" << endl;
	}
	
	return 0;
}