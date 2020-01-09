#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

typedef unsigned int UI;

struct IP {
    UI a[5];
    UI val;
};

int n;
IP ip[MAXN];

bool cmp(const IP &ip1, const IP &ip2) {
    for (int i = 0; i < 5; i++) {
        if (ip1.a[i] != ip2.a[i])
            return ip1.a[i] < ip2.a[i];
    }
    return false;
}

void deal_str(int no, char *str) {
    int pn = 0, xn = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.')
            pn++;
        else if (str[i] == '/')
            xn++;
    }

    for (int i = 0; i < 5; i++) {
        ip[no].a[i] = 0;
    }

    int cnt = 0;
    char *p1 = str, *p2;
    char tmp[5];
    for (int i = 0; i < pn; i++) {
        p2 = strchr(p1, '.');
        strncpy(tmp, p1, p2 - p1);
        tmp[p2 - p1] = 0;
        ip[no].a[cnt++] = atoi(tmp);
        p1 = p2 + 1;
    }

    if (xn > 0) {
        p2 = strchr(p1, '/');
        strncpy(tmp, p1, p2 - p1);
        tmp[p2 - p1] = 0;
        ip[no].a[cnt++] = atoi(tmp);
        p1 = p2 + 1;
        strcpy(tmp, p1);
        ip[no].a[4] = atoi(tmp);
    } else {
        strcpy(tmp, p1);
        ip[no].a[cnt++] = atoi(tmp);
        ip[no].a[4] = cnt * 8;
    }
}

void countVal(int no) {
    ip[no].val = 0;
    for (int i = 0; i < 4; i++) {
        ip[no].val += ip[no].a[i] << 8 * (3 - i);
    }
}

void range(IP &ip, UI &l, UI &r) {
    l = ip.val >> (32 - ip.a[4]) << (32 - ip.a[4]);
    r = ip.val | ((1ull << (32 - ip.a[4])) - 1);
}

void union1() {
    int p = 0;
    UI la, ra, lb, rb;
    for (int i = 1; i < n; i++) {
        range(ip[p], la, ra);
        range(ip[i], lb, rb);
        if (!(la <= lb && rb <= ra))
            ip[++p] = ip[i];
    }
    n = p + 1;
}

bool judge_union(IP &ip1, IP &ip2, IP &res) {
    if (ip1.a[4] != ip2.a[4])
        return false;
    res = ip1;
    res.a[4] -= 1;
    if (res.a[4] < 0)
        return false;
    UI la, ra, lb, rb, laa, raa;
    range(ip1, la, ra);
    range(ip2, lb, rb);
    range(res, laa, raa);
    if (la == laa && rb == raa && lb <= ra + 1)
        return true;
    return false;
}

void union2() {
    int p = 0;
    IP res;
    for (int i = 1; i < n; i++) {
        if (judge_union(ip[p], ip[i], res)) {
            ip[p] = res;
            while (p > 0 && judge_union(ip[p - 1], ip[p], res))
                ip[--p] = res;
        } else
            ip[++p] = ip[i];
    }
    n = p + 1;
}

int main() {
    char str[25];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        deal_str(i, str);
        countVal(i);
    }
    sort(ip, ip + n, cmp);
    union1();
    union2();
    for (int i = 0; i < n; i++) {
        printf("%u.%u.%u.%u/%u\n", ip[i].a[0], ip[i].a[1], ip[i].a[2],
               ip[i].a[3], ip[i].a[4]);
    }
    return 0;
}