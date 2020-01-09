#include <bits/stdc++.h>
using namespace std;

int main() {
    int pa, pb, va = 0, vb = 0, i;
    cin >> pa >> pb;

    int vote[3];
    cin >> vote[0] >> vote[1] >> vote[2];

    for (i = 0; i < 3; i++)
        if (vote[i])
            vb++;
        else
            va++;

    if (va == 3 || (va >= 1 && pa + va > pb + vb))
        printf("The winner is a: %d + %d", pa, va);
    else
        printf("The winner is b: %d + %d", pb, vb);

    return 0;
}