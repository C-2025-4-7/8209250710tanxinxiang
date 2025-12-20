#include<iostream>
using namespace std;
int main()
{
	double x = 3.14;
	double r, h, v;
	cout << "°ë¾¶:";
	cin >> r;
	cout << "¸ß:";
	cin >> h;
	v =   x * r * r * h/3;
	cout << "Ìå»ý" <<v<<endl;
	return 0;
}