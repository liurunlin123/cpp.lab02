#include <limits>
#include <sstream>
#include <stdexcept>
#include "card_operations.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const double WARNING_BALANCE = 10.0;

// 充值：扣除手续费后增加余额，并记录一次交易
void deposit(Card& c, double amount, double fee) {
    c.balance += amount * (1.0 - fee);
    ++c.transactions;
}

// 消费：金额不合法时抛出异常，余额不足返回 false
bool spend(Card& c, double cost) {
    if (!isfinite(cost) || cost < 0.0) {
        throw invalid_argument("Invalid payment amount.");
    }
    if (cost > c.balance) {
        return false;
    }

    c.balance -= cost;
    ++c.transactions;
    return true;
}

// 消费重载：先显示消费项目，再调用上面的版本扣款
bool spend(Card& c, double cost, const string& item) {
    cout << "Item: " << item << '\n';
    return spend(c, cost);
}

// 创建 n 个账户，返回数组首元素的地址
Card* createCards(int n) {
    return new Card[n];
}

// 依次录入每张卡的信息
void inputCards(Card* arr, int n) {
    for (int i = 0; i < n; ) {
        string line;
        if (!getline(cin, line)) {
            throw runtime_error(
                "Input ended before all cards were entered.");
        }

        try {
            istringstream row(line);  // 从这一行文字里读取数据
            Card current = {};       // 交易次数初始化为 0
            string extra;

            if (!(row >> current.id >> current.name >> current.balance) ||
                (row >> extra)) {
                throw invalid_argument("Enter ID, name and balance again.");
            }

            if (!isfinite(current.balance) || current.balance < 0.0) {
                throw invalid_argument(
                    "Enter a non-negative balance. Retry this card.");
            }

            arr[i] = current;
            ++i;  // 这一张录入成功，才开始录下一张
        }
        catch (const invalid_argument& e) {
            cout << e.what() << '\n';
        }
    }
}

// 释放动态创建的数组
void destroyCards(Card* arr) {
    delete[] arr;
}
namespace card {
    // 默认打印 60 个短横线
    void printLine(char c, int len) {
        for (int i = 0; i < len; ++i) {
            cout << c;
        }
        cout << '\n';
    }

    void title(const string& s) {
        printLine();
        cout << s << '\n';
        printLine();
    }
}

// 用常引用读取余额
void showBalance(const Card& c) {
    cout << "Current balance: " << fixed << setprecision(2)
        << c.balance << " yuan\n";

    if (c.balance < WARNING_BALANCE) {
        cout << "Warning: low balance.\n";
    }
}

// 用指向常量的指针读取学号
void viewStudentID(const Card* p) {
    cout << "Student ID: " << p->id << '\n';
}

// 把元换算成分，四舍五入到整数
int toCent(double amount) {
    double cents = round(amount * 100.0);

    if (!isfinite(cents) || cents < numeric_limits<int>::min() ||
        cents > numeric_limits<int>::max()) {
        throw out_of_range("Balance in cents is out of range.");
    }

    return static_cast<int>(cents);
}

void printReport(const Card* arr, int n) {
    card::title("Account Report");

    cout << left << setw(12) << "ID"
        << setw(18) << "Name"
        << right << setw(14) << "Balance"
        << setw(16) << "Transactions" << '\n';

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; ++i) {
        cout << left << setw(12) << arr[i].id
            << setw(18) << arr[i].name
            << right << setw(14) << arr[i].balance
            << setw(16) << arr[i].transactions << '\n';
    }

    card::printLine();
}
