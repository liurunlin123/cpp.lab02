#include <iostream>

using namespace std;

// 引用版：x 和 y 分别是传入变量的别名
void swap(int& x, int& y) {
    int temp = x;  // 保存 x 原来的值
    x = y;         // 把 y 的值赋给 x
    y = temp;      // 把 x 原来的值赋给 y
}

// 指针版：接收两个变量的地址
void swap(int* x, int* y) {
    swap(*x, *y);  // 取出指针指向的变量，调用引用版
}

int main() {
    int x, y;
    if (!(cin >> x >> y)) {
        return 0;
    }

    cout << "Before swap: x=" << x << ", y=" << y << '\n';

    swap(x, y);  // 传入两个整数变量，调用引用版

    cout << "After  swap: x=" << x << ", y=" << y << '\n';

    return 0;
}
