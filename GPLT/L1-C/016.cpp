#include <iostream>
#include <string>
using namespace std;

int main() {
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char m[15] = "10X98765432";
    int n, i, j, wrong = 0, sum = 0;
    bool flag = true;
    cin >> n;
    string s[n];
    for (i = 0; i < n; i++)
        cin >> s[i];
    for (i = 0; i < n; i++) {
        for (j = 0; j < 17; j++) {
            if (s[i][j] > '9' || s[i][j] < '0') {
                cout << s[i] << endl;
                wrong++;
                flag = false;
                break;
            }
            flag = true;
        }
        for (j = 0; j < 17 && flag; j++) {
            sum += weight[j] * (s[i][j] - '0');
        }
        if (sum != 0) {
            sum = sum % 11;
            if (s[i][17] != m[sum]) {
                cout << s[i] << endl;
                wrong++;
            }
            sum = 0;
        }
    }
    if (wrong == 0)
        cout << "All passed" << endl;
    return 0;
}
