#include <cstdio>
#include <iostream>
using namespace std;

// 注意PI的精度
const double PI = 3.14159265358979323846;

int main() {
    int r;
    double s;
    cin >> r;
    s = PI * r * r;
    printf("%.7lf", s);
    return 0;
}