#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    vector<int> v;
    vector<int>::iterator it;
    cin >> s;
    size_t i;
    for (i = 0; i < s.length(); i++)
        v.push_back(s[i] - '0');
    sort(v.begin(), v.end(), greater<int>());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "int[] arr = new int[]{";
    for (it = v.begin(); it < v.end() - 1; it++)
        cout << *it << ",";
    cout << *it << "};\n";
    cout << "int[] index = new int[]{";
    for (i = 0; i < s.length() - 1; i++)
        cout << find(v.begin(), v.end(), s[i] - '0') - v.begin() << ",";
    cout << find(v.begin(), v.end(), s[i] - '0') - v.begin() << "};";
    return 0;
}