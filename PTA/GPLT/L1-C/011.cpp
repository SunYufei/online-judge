#include <iostream>
using namespace std;

char hashTable[256] = {0};

void initHash(const char *b) {
    while (*b != '\0')
        hashTable[*b++] = 1; //下标对应字符的ascii码。
}

void ProcessTheString(char *a) {
    char *pFast;
    char *pSlow;

    pFast = pSlow = a; // 实在是太nb了.
    while (*pFast != '\0') {
        if (!hashTable[*pFast])
            *pSlow++ = *pFast++;
        else
            pFast++;
    }
    *pSlow = '\0';
}

int main() {
    char a[10010], b[10010];

    gets(a);
    gets(b);

    initHash(b);
    ProcessTheString(a);

    cout << a;
    return 0;
}