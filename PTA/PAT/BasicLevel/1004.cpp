#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string name;
    string num;
    int score;
} stu;

int main() {
    int n, i;
    int min = 101, max = -1;
    int minn = -1, maxn = -1;
    cin >> n;
    stu s[n];
    for (i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].num >> s[i].score;
        if (s[i].score < min) {
            min = s[i].score;
            minn = i;
        }
        if (s[i].score > max) {
            max = s[i].score;
            maxn = i;
        }
    }
    cout << s[maxn].name << " " << s[maxn].num << endl;
    cout << s[minn].name << " " << s[minn].num << endl;
    return 0;
}
