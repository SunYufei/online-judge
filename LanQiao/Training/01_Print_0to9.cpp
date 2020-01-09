#include <iostream>
using namespace std;

void f(int n) {
    if (n > 0)
        f(n - 1);
    cout << n << " ";
}

void f2(int begin, int end) {
    if (begin > end)
        return;
    cout << begin << " ";
    f2(begin + 1, end);
}

int main() {
    f(10);
    cout << endl;
    f2(0, 10);
    return 0;
}