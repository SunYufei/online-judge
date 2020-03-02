#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    int i, a[10] = {0};

    cin >> n;
    for (i = 0; i < n.length(); i++)
        a[n[i] - '0']++;

    for (i = 0; i < 10; i++)
        if (a[i] != 0)
            cout << i << ":" << a[i] << endl;

    return 0;
}
