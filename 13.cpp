#include<iostream>
using namespace std;
int main()
{ 
	double x,y;
	cout << "x=";
	cin >> x;
	if (0 < x < 10) 
		if (x < 1) {
			y = 3 - 2 * x;
		}
		else if (x < 5) {
			int y = 2 / (4 * x) + 1;
		}
		else if (x < 10) {
			y = x * x;
		}
		else {
			y = 0;
		}
		cout << "y=" << y << endl;
		return 0;
	}