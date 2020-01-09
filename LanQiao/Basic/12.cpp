#include <bits/stdc++.h>
using namespace std;


int main() {
    string hex;
    string bin;
    string bins[16] = {"0000", "0001", "0010", "0011", "0100", "0101",
                       "0110", "0111", "1000", "1001", "1010", "1011",
                       "1100", "1101", "1110", "1111"};
    string::iterator its;
    vector<int>::iterator itv;
    int n;
    cin >> n;
    while (n--) {
        cin >> hex;
        // hex -> bin
        for (its = hex.begin(); its < hex.end(); its++) {
            if (*its >= 'A')
                bin.append(bins[10 + (*its) - 'A']);
            else
                bin.append(bins[(*its) - '0']);
        }
        // bin -> oct
        
    }
    return 0;
}