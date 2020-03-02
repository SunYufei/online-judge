#include <cstdio>
#include <vector>
using namespace std;

void format(int n) {
    if (n >= 10000)
        printf("%d", n);
    else if (n >= 1000)
        printf("0%d", n);
    else if (n >= 100)
        printf("00%d", n);
    else if (n >= 10)
        printf("000%d", n);
    else
        printf("0000%d", n);
}

int main() {
    bool a[100000] = {false};
    int N, K, M, i, j, t;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &K);
        for (j = 0; j < K; j++) {
            scanf("%d", &t);
            if (K != 1)
                a[t] = true;
        }
    }
    scanf("%d", &M);
    vector<int> ans;
    for (i = 0; i < M; i++) {
        scanf("%d", &t);
        if (a[t] == false) {
            ans.push_back(t);
            a[t] = true;
        }
    }
    if (ans.empty()) {
        printf("No one is handsome");
    } else {
        vector<int>::iterator it;
        for (it = ans.begin(); it < ans.end() - 1; it++) {
            format(*it);
            putchar(' ');
        }
        format(*it);
    }
    return 0;
} // main
