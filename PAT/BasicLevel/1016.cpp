#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    string::iterator it;
    int DA, DB, PA = 0, PB = 0, ca = 0, cb = 0;
    cin >> A >> DA >> B >> DB;
    for (it = A.begin(); it < A.end(); it++)
        if (*it - '0' == DA)
            ca++;
    while (ca--) {
        PA *= 10;
        PA += DA;
    }
    for (it = B.begin(); it < B.end(); it++)
        if (*it - '0' == DB)
            cb++;
    while (cb--) {
        PB *= 10;
        PB += DB;
    }
    cout << PA + PB;
    return 0;
}
