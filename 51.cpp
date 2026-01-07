#include<iostream>
using namespace std;
class Time {
private:
	int hour;
	int minute;
	int sec;
public:
	void setTime() {
		cin >> hour >> minute>> sec;
	}
	void showTime() {
		cout << hour << ":" << minute << ":" << sec << endl;
	}
};
int main() {
	Time t1;
	cout << "输入“时 分 秒”";
	t1.setTime();
	cout << "时间:";
	t1.showTime();
	return 0;
}