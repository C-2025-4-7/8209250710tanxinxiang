#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double price_per_apple = 0.8;  // 每个苹果0.8元
    int total_apples = 0;          // 总苹果数
    double total_cost = 0.0;       // 总花费
    int day = 1;                   // 天数
    int apples_today = 2;          // 第一天买2个

    cout << "苹果购买记录:" << endl;
    cout << "天数\t当天苹果数\t当天花费\t累计苹果数\t累计花费" << endl;
    cout << fixed << setprecision(2);

    // 循环直到购买的苹果数不超过100的最大值
    while (total_apples + apples_today <= 100) {
        double cost_today = apples_today * price_per_apple;
        total_apples += apples_today;
        total_cost += cost_today;

        cout << day << "\t" << apples_today << "\t\t" << cost_today
            << "\t\t" << total_apples << "\t\t" << total_cost << endl;

        // 第二天开始，每天买前一天的2倍
        apples_today *= 2;
        day++;
    }

    // 计算平均值
    double average_cost = total_cost / (day - 1);

    cout << "\n统计结果:" << endl;
    cout << "总天数: " << (day - 1) << " 天" << endl;
    cout << "总苹果数: " << total_apples << " 个" << endl;
    cout << "总花费: " << total_cost << " 元" << endl;
    cout << "每天平均花费: " << average_cost << " 元" << endl;

    return 0;
}
