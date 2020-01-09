/*
本题给定一个庞大家族的家谱，要请你给出最小一辈的名单。

输入格式：
输入在第一行给出家族人口总数 N（不超过 100 000 的正整数） —— 简单起见，我们把家族成员从 1 到 N 编号。随后第二行给出 N 个编号，其中第 i 个编号对应第 i 位成员的父/母。家谱中辈分最高的老祖宗对应的父/母编号为 -1。一行中的数字间以空格分隔。

输出格式：
首先输出最小的辈分（老祖宗的辈分为 1，以下逐级递增）。然后在第二行按递增顺序输出辈分最小的成员的编号。编号间以一个空格分隔，行首尾不得有多余空格。

输入样例：
9
2 6 5 5 -1 5 6 4 7
输出样例：
4
1 9
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100010;

int generation[MAXN] = {0};
int ans;
vector<int> child[MAXN];

void dfs(int a, int depth) {
    ans = max(ans, depth);
    generation[a] = depth;
    for (int i = 0; i < child[a].size(); ++i)
        dfs(child[a][i], depth + 1);
}

int main() {
    int n, ancestor, t;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        if (t == -1)
            ancestor = i;
        else
            child[t].push_back(i);
    }

    dfs(ancestor, 1);

    cout << ans << endl;

    bool flag = false;
    for (int i = 1; i <= n; ++i)
        if (generation[i] == ans) {
            if (flag)
                cout << ' ' << i;
            else {
                cout << i;
                flag = true;
            }
        }

    return 0;
}