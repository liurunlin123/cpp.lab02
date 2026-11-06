#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct student {
    string name;
    double chinese;
    double math;
    double english;
    double average;
};
int main() {
    int n;  // 学生数
    if (!(cin >> n)) return 0;

    const int MAX_N = 1000;
    if (n < 1 || n > MAX_N) return 0;

    student students[MAX_N];
    for (int i = 0; i < n; i++) {
        cin >> students[i].name
            >> students[i].chinese
            >> students[i].math
            >> students[i].english;
        students[i].average =
            (students[i].chinese + students[i].math +
             students[i].english) / 3.0;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << left << setw(16) << students[i].name
            << right << setw(10) << students[i].chinese
            << setw(10) << students[i].math
            << setw(10) << students[i].english
            << setw(10) << students[i].average;
        if (students[i].average >= 90) {
            cout << " Excellent";
        }
        cout << endl;
    }
    return 0;
}
