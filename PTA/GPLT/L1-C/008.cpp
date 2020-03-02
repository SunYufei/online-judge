#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    long sum = 0;
    int a, b, i, n;

    cin >> a >> b;
    for (i = a, n = 1; i <= b; i++, n++) {
        sum += i;
        if (n % 5 != 0)
            printf("%5d", i);
        else {
            printf("%5d\n", i);
            n = 0;
        }
    }
    if (n != 1)
        cout << endl;
    cout << "Sum = " << sum;
    return 0;
}
