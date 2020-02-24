#include <algorithm>
#include <queue>
#include <stdio.h>
#define MAXN 1005
using namespace std;

struct Tea {
    int key;
    int sta;
    int fin;
    bool operator<(const Tea &a) const { //用于优先队列从小到大排序
        if (fin == a.fin)
            return key > a.key;
        return fin > a.fin;
    }
} tea[MAXN];

int pos[MAXN];    // pos[i]: 挂钩i上的钥匙编号
int keypos[MAXN]; // keypos[i]: 钥匙i所在的位置
priority_queue<int, vector<int>, greater<int>> sparepos; //挂钩的空位置编号
priority_queue<Tea> backtea;                             //待返还的钥匙

bool teacmp(Tea a, Tea b) { return a.sta < b.sta; }

void takeKey(Tea tea) {
    sparepos.push(keypos[tea.key]);
    backtea.push(tea);
    keypos[tea.key] = 0;
}

void backKey(Tea tea) {
    keypos[tea.key] = sparepos.top();
    sparepos.pop();
    backtea.pop();
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);

    for (int i = 1; i <= N; i++)
        keypos[i] = i;

    for (int i = 0; i < K; i++) {
        scanf("%d%d%d", &tea[i].key, &tea[i].sta, &tea[i].fin);
        tea[i].fin += tea[i].sta;
    }

    sort(tea, tea + K, teacmp);

    for (int i = 0; i < K; i++) {
        while (!backtea.empty() && tea[i].sta >= backtea.top().fin)
            backKey(backtea.top());
        takeKey(tea[i]);
    }

    while (!backtea.empty())
        backKey(backtea.top());

    for (int i = 1; i <= N; i++)
        pos[keypos[i]] = i;

    for (int i = 1; i <= N; i++)
        printf("%d ", pos[i]);

    return 0;
}