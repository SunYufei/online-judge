#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, m, t;
    unordered_map<int, int> mp;
    unordered_map<int, int>::iterator it;
    cin >> n;
    while (n--) {
        scanf("%d", &t);
        mp[t] = 1;
    }
    cin >> m;
    while (m--) {
        scanf("%d", &t);
        mp[t] += 2;
    }
    for (it = mp.begin(); it != mp.end(); ++it)
        if (it->second == 3)
            printf("%d ", it->first);
    printf("\n");
    for (it = mp.begin(); it != mp.end(); ++it)
        printf("%d ", it->first);
    printf("\n");
    for (it = mp.begin(); it != mp.end(); ++it)
        if (it->second == 1)
            printf("%d ", it->first);
    printf("\n");
    return 0;
}