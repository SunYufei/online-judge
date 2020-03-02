/*
图着色问题是一个著名的NP完全问题。给定无向图G=(V,E)，问可否用K种颜色为V中的每一个顶点分配一种颜色，使得不会有两个相邻顶点具有同一种颜色？

但本题并不是要你解决这个着色问题，而是对给定的一种颜色分配，请你判断这是否是图着色问题的一个解。

输入格式：
输入在第一行给出3个整数V（0<V≤500）、E（≥0）和K（0<K≤V），分别是无向图的顶点数、边数、以及颜色数。顶点和颜色都从1到V编号。随后E行，每行给出一条边的两个端点的编号。在图的信息给出之后，给出了一个正整数N（≤20），是待检查的颜色分配方案的个数。随后N行，每行顺次给出V个顶点的颜色（第i个数字表示第i个顶点的颜色），数字间以空格分隔。题目保证给定的无向图是合法的（即不存在自回路和重边）。

输出格式：
对每种颜色分配方案，如果是图着色问题的一个解则输出Yes，否则输出No，每句占一行。

输入样例：
6 8 3
2 1
1 3
4 6
2 5
2 4
5 4
5 6
3 6
4
1 2 3 3 1 2
4 5 6 6 4 5
1 2 3 4 5 6
2 3 4 2 3 4
输出样例：
Yes
Yes
No
No
*/
#include <iostream>
#include <set>
#include <string.h>
using namespace std;

bool edge[510][510] = {false};
bool vis[510] = {false};
int color[510] = {0};

int v, e, k, n;

bool flag = true;

void dfs(int x) {
    if (vis[x] || flag == false)
        return;

    vis[x] = true;

    for (int i = 1; i <= v; ++i) {
        if (color[x] == color[i] && edge[x][i]) {
            flag = false;
            return;
        } else if (edge[x][i] && vis[i] == false)
            dfs(i);
    }
}

int main() {
    cin >> v >> e >> k;
    for (int i = 0, x, y; i < e; ++i) {
        cin >> x >> y;
        edge[x][y] = edge[y][x] = true;
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        set<int> s;
        for (int j = 1, c; j <= v; ++j) {
            cin >> c;
            s.insert(c);
            color[j] = c;
        }

        if (s.size() != k)
            flag = false;
        else {
            memset(vis, false, sizeof(vis));
            flag = true;
            for (int j = 1; j <= v; ++j) {
                dfs(j);
                if (flag == false)
                    break;
            }
        }

        printf(flag ? "Yes\n" : "No\n");
    }

    return 0;
}