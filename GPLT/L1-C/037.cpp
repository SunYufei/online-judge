#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (b == 0)
        printf("%d/0=Error", a);
    else if (b < 0)
        printf("%d/(%d)=%.2f", a, b, a * 1.0 / b);
    else
        printf("%d/%d=%.2f", a, b, a * 1.0 / b);
    return 0;
}