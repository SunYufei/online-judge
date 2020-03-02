#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(int t) {
    // t == 1 重点
    if (t == 1)
        return false;
    for (int i = 2; i < sqrt(t); i++)
        if (t % i == 0)
            return false;
    return true;
}

int main() {
    int n, t;

    cin >> n;
    while (n--) {
        cin >> t;
        if (is_prime(t))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}