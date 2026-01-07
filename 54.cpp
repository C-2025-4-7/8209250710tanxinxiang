#include <iostream>
using namespace std;

class Student {
private:
    int id;
    float score;
public:
    void setData(int i, float s) {
        id = i;
        score = s;
    }
    int getId() { return id; }
    float getScore() { return score; }
};

void max(Student* arr, int n) {
    float maxScore = arr[0].getScore();
    int maxId = arr[0].getId();
    for (int i = 1; i < n; i++) {
        if (arr[i].getScore() > maxScore) {
            maxScore = arr[i].getScore();
            maxId = arr[i].getId();
        }
    }
    cout << "最高分学生学号：" << maxId << "，成绩：" << maxScore << endl;
}

int main() {
    Student stu[5];
    stu[0].setData(1001,97.5);
    stu[1].setData(1002,66 );
    stu[2].setData(1003, 86.5);
    stu[3].setData(1004, 89.5);
    stu[4].setData(1005, 98);

    max(stu, 5);
    return 0;
}