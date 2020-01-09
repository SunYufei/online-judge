#include <iostream>
using namespace std;

int f(int m, int n) {
    if (n == 0 || m == n || m == 0)
        return 1;
    return f(m - 1, n) + f(m - 1, n - 1);
}

int main() {
    int level = 5;
    for (int i = 0; i <= level; i++)
        cout << f(level, i) << " ";
    cout << endl;
    return 0;
}