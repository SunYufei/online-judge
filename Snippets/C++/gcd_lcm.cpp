#include <vector>
using namespace std;

// 欧几里得算法非递归
int gcd(int m, int n) {
    if (m == 0 || n == 0)
        return m > n ? m : n;
    int t;
    if (m < n) {
        t = m;
        m = n;
        n = t;
    }
    while (n != 0) {
        t = n;
        n = m % n;
        m = t;
    }
    return m;
}

// 欧几里得算法递归版本
int gcd_R(int m, int n) {
    int t;
    if (m < n) {
        t = m;
        m = n;
        n = t;
    }
    if (n == 0)
        return m;
    else
        return gcd_R(n, m % n);
}

// 埃拉托色尼筛选法生成素数集合
vector<long> Eratosthenes(long num) {
    vector<long> v;
    vector<long>::iterator it1, it2;
    for (long i = 2; i <= num; i++)
        v.push_back(i);
    for (it1 = v.begin(); it1 < v.end(); it1++)
        for (it2 = it1 + 1; it2 < v.end(); it2++)
            if ((*it2) % (*it1) == 0)
                v.erase(it2);
            else
                it2++;
    return v;
}

// 根据埃拉托色尼筛生成的集合求最大公约数
long gcd_E(long m, long n) {
    long g = 1;
    vector<long> v = Eratosthenes(m > n ? n : m);
    vector<long>::iterator it = v.begin();
    while (it < v.end()) {
        if ((m % *it == 0) && (n % *it == 0)) {
            m /= *it;
            n /= *it;
            g *= *it;
        } else if (m < *it || n < *it)
            break;
        else
            it++;
    }
    return g;
}

// 最小公倍数
int lcm(int m, int n) { return m * n / gcd(m, n); }