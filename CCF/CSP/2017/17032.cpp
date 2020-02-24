#include <stdio.h>
#include <vector>
using namespace std;
vector<int> stu;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        stu.push_back(i);
    }
    int no, pos;
    vector<int>::iterator it;
    while (m--) {
        scanf("%d%d", &no, &pos);
        for (it = stu.begin(); it != stu.end(); it++) {
            if (*it == no) {
                it = stu.erase(it);
                stu.insert(it + pos, no);
                break;
            }
        }
    }
    for (it = stu.begin(); it != stu.end(); it++) {
        printf("%d ", *it);
    }
    return 0;
}