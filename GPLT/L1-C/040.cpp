#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    char c;
    float h;
    while (n--) {
        cin >> c >> h;
        printf("%.2f\n", c == 'M' ? h / 1.09 : h * 1.09);
    }
    return 0;
}