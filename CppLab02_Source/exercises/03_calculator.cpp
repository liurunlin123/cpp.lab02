#include <cmath>      // pow
#include <iomanip>    // fixed、setprecision
#include <iostream>   // cin、cout
#include <stdexcept>  // domain_error、invalid_argument

using namespace std;

// 内联函数，计算平方
inline double square(double x) {
    return x * x;
}

// 默认指数为 2，调用时也可以指定其他指数
double power(double base, int exponent = 2) {
    return pow(base, exponent);
}

// 重载一，处理两个小数类型的操作数
double calc(double a, double b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0.0) {
            throw domain_error("Error: divide by zero");
        }
        return a / b;
    default:
        throw invalid_argument("Error: invalid operator");
    }
}

// 重载二，将两个整数转换为 double，复用上面的计算逻辑
double calc(int a, int b, char op) {
    return calc(static_cast<double>(a), static_cast<double>(b), op);
}

int main() {
    double a, b;
    char op;

    if (!(cin >> a >> b >> op)) {
        return 0;
    }

    cout << "square(" << a << ") = "
        << fixed << setprecision(2) << square(a) << '\n';

    // 操作数按普通格式显示，计算结果保留两位小数
    cout << defaultfloat << setprecision(6)
        << "power(" << a << ",3) = "
        << fixed << setprecision(2) << power(a, 3) << '\n';

    try {
        double result = calc(a, b, op);

        cout << defaultfloat << setprecision(6)
            << a << ' ' << op << ' ' << b << " = "
            << fixed << setprecision(2) << result << '\n';
    }
    catch (const logic_error& e) {
        cout << e.what() << '\n';
    }

    return 0;
}
