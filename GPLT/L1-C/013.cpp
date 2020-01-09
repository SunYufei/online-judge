#include <iostream>
using namespace std;
int main() {
    int s = 0, n, i, fact = 1;
    cin >> n;
    for (i = 1; i <= n; i++) {
        fact *= i;
        s += fact;
    }
    cout << s;
    return 0;
}
