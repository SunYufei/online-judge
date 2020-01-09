#include "Fraction.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    Fraction f1(1, 2), f2(1, 2);
    f1 += f2;
    f1 += 1;
    f2 = f1 + 1;
    cout << f1 << " " << f2 << endl;
    return 0;
}
