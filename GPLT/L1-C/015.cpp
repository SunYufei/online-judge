#include <iostream>
using namespace std;

int main() {
    int i, j, h;
    float n;
    char c;
    cin >> n >> c;
    if (n / 2 - int(n / 2) >= 0.5)
        h = int(n / 2) + 1;
    else
        h = int(n / 2);
    for (i = 0; i < h; i++) {
        for (j = 0; j < n; j++)
            cout << c;
        cout << endl;
    }
    return 0;
}
