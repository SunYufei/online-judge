#include <iostream>
using namespace std;

int main() {
    int a, b, c, n;
    bool flag = false;
    cin >> n;
    for (a = 1; a <= 9; a++)
        for (b = 0; b <= 9; b++)
            for (c = 0; c <= 9; c++)
                if (a + a + b + b + c == n) {
                    flag = true;
                    cout << a << b << c << b << a << endl;
                }
    for (a = 1; a <= 9; a++)
        for (b = 0; b <= 9; b++)
            for (c = 0; c <= 9; c++)
                if (a + a + b + b + c + c == n) {
                    flag = true;
                    cout << a << b << c << c << b << a << endl;
                }
    if (flag == false)
        cout << "-1" << endl;
    return 0;
}