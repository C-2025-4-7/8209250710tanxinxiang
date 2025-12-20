#include<iostream>
using namespace std;
int peach_count(int day) {
	if (day == 10) {
		return 1;
	}
	else {
		return(peach_count(day + 1) + 1) * 2;
	}
}
int main() {
	int total = peach_count(1);
	cout << "猴子第一天摘" << total << "个桃" << endl;
}