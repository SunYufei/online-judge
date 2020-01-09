#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

struct Mes {
    char flag;
    int target;
};

struct Pro {
    queue<Mes> task;
};

Pro pro[MAXN];
int wait[MAXN];

int exe(int no);
int receiveM(int from, int to);
int sendM(int from, int to);

int exe(int no) {
    if (wait[no] == 1)
        return -1;
    if (pro[no].task.empty())
        return 0;
    Mes cur = pro[no].task.front();
    if (cur.flag == 'R') {
        wait[no] = 1;
        if (receiveM(no, cur.target) == -1)
            return -1;

        pro[no].task.pop();
        wait[no] = 0;
        if (exe(no) == -1)
            return -1;
        return 0;
    } else if (cur.flag == 'S') {
        wait[no] = 1;
        if (sendM(no, cur.target) == -1)
            return -1;

        pro[no].task.pop();
        wait[no] = 0;
        if (exe(no) == -1)
            return -1;
        return 0;
    }
}

int receiveM(int from, int to) {
    if (wait[to] == 1)
        return -1;
    if (pro[to].task.empty())
        return -1;
    Mes cur = pro[to].task.front();
    if (cur.flag == 'R') {
        wait[to] = 1;
        if (receiveM(to, cur.target) == -1)
            return -1;

        wait[to] = 0;
        pro[to].task.pop();
        if (receiveM(from, to) == 0)
            return 0;
        return -1;
    } else if (cur.flag == 'S') {
        if (cur.target == from) {
            pro[to].task.pop();
            return 0;
        }

        wait[to] = 1;
        if (sendM(to, cur.target) == -1)
            return -1;

        wait[to] = 0;
        pro[to].task.pop();
        if (receiveM(from, to) == 0)
            return 0;
        return -1;
    }
    return -1;
}

int sendM(int from, int to) {
    if (wait[to] == 1)
        return -1;
    if (pro[to].task.empty())
        return -1;
    Mes cur = pro[to].task.front();
    if (cur.flag == 'R') {
        if (cur.target == from) {
            pro[to].task.pop();
            return 0;
        }

        wait[to] = 1;
        if (receiveM(to, cur.target) == -1)
            return -1;

        wait[to] = 0;
        pro[to].task.pop();
        if (sendM(from, to) == 0)
            return 0;
        return -1;
    } else if (cur.flag == 'S') {
        wait[to] = 1;
        if (sendM(to, cur.target) == -1)
            return -1;

        wait[to] = 0;
        pro[to].task.pop();
        if (sendM(from, to) == 0)
            return 0;
        return -1;
    }
    return -1;
}

int T, n;

int main() {
    scanf("%d%d", &T, &n);
    getchar();
    for (int i = 0; i < T; i++) {

        memset(wait, 0, sizeof(wait));

        for (int j = 0; j < n; j++) {
            while (!pro[j].task.empty())
                pro[j].task.pop();
        }

        for (int j = 0; j < n; j++) {
            string line;
            getline(cin, line);
            istringstream ss(line);
            string tmp;
            while (ss >> tmp) {
                Mes mes;
                mes.flag = tmp[0];
                mes.target = atoi(tmp.c_str() + 1);
                pro[j].task.push(mes);
            }
        }

        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (!pro[j].task.empty()) {
                if (exe(j) == -1) {
                    flag = 1;
                    break;
                }
            }
        }

        printf("%d\n", flag);
    }
    return 0;
}