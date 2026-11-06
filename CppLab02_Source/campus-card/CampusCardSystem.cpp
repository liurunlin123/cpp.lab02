#include "card_operations.h"
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <new>
#include <stdexcept>

using namespace std;

int main() {
    card::title("Campus Card System");

    int n;
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid student count.\n";
        return 1;
    }

    // 读完人数后，跳过本行剩余内容，再用 getline 读第一张卡
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Card* cards = nullptr;
    int exitCode = 0;

    try {
        cards = createCards(n);
        inputCards(cards, n);

        cout << fixed << setprecision(2);
        deposit(cards[0], 100.0);
        cout << "Balance after deposit: " << cards[0].balance << '\n';

        if (!spend(cards[0], 8.5, "食堂午餐")) {
            throw runtime_error("Insufficient balance.");
        }

        showBalance(cards[0]);
        viewStudentID(&cards[0]);
        int cents = toCent(cards[0].balance);
        cout << "Balance in cents: " << cents << '\n';
        printReport(cards, n);
    }
    catch (const bad_alloc&) {
        cout << "Memory allocation failed.\n";
        exitCode = 1;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
        exitCode = 1;
    }

    destroyCards(cards);
    return exitCode;
}
