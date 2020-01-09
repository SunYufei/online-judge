#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int M, N, ti;
    string ts;
    string a[1001];
    int b[1001];
    cin >> N;
    while (N--) {
        cin >> ts;
        cin >> ti;
        a[ti] = ts;
        cin >> b[ti];
    }
    cin >> M;
    vector<int> va;
    vector<int>::iterator it;
    while (M--) {
        cin >> ti;
        va.push_back(ti);
    }
    for (it = va.begin(); it < va.end(); it++)
        cout << a[*it] << " " << b[*it] << endl;
    return 0;
}