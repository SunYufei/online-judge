#include <iostream>
#include <string>
using namespace std;

int main() {
    string num[10] = {"ling", "yi",  "er", "san", "si",
                      "wu",   "liu", "qi", "ba",  "jiu"};
    string n;
    cin >> n;
    int sum = 0, i, base = 1;
    for (i = 0; i < n.length(); i++)
        sum += n[i] - '0';
    while (sum / base > 10)
        base *= 10;
    while (base >= 10) {
        cout << num[sum / base] << " ";
        sum %= base;
        base /= 10;
    }
    cout << num[sum];
    return 0;
}
