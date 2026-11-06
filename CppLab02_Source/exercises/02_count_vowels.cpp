#include <iostream>
#include <string>
using namespace std;
int countVowels(const char* p) {
    int count = 0;

    while (*p != '\0') {
        char ch = *p;

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            ++count;
        }

        ++p;  // 移到下一个字符
    }

    return count;  // 返回统计结果
}

int main() {
    string line;
    getline(cin, line);
    int count = countVowels(line.c_str());
    cout << "Number of vowels: " << count << endl;

    return 0;
}
