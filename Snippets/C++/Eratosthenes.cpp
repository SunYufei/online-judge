#include <vector>
using namespace std;

// Eratosthenes筛选法求解质数

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
