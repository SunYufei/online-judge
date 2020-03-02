#include <iostream>
#include <string>
using namespace std;

typedef struct {
    int sex;
    string name;
} node;

int main() {
    node list[50];
    int i, j, k, n;

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> list[i].sex >> list[i].name;
    j = k = n - 1;
    for (i = 0; i < n / 2; i++) {
        if (list[i].sex == 1) {
            while (list[j].sex == list[i].sex)
                j--;
            cout << list[i].name << " " << list[j].name << endl;
            j--;
        } else {
            while (list[k].sex == list[i].sex)
                k--;
            cout << list[i].name << " " << list[k].name << endl;
            k--;
        }
    }

    return 0;
} // main