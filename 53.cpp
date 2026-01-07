#include<iostream>
using namespace std;
class V {
private:
		double length, hight, width;
public:
	void X(){
		cin >> length >> hight >> width;
	}
		double volume() {
		return length * hight * width;
	}
};
int main() {
	V c1, c2, c3;
	cout << "输入3个长方柱的长、宽、高" << endl;
		c1.X();
	c2.X();
	c3.X();
	cout << "体积为:" << endl;
	cout << c1.volume() << endl;
	cout << c2.volume()<< endl;
	cout << c3.volume() << endl;
	return 0;
}