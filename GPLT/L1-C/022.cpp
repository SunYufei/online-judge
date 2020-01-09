#include <stdio.h>

int main() {
    int N, t, ji = 0, ou = 0;

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &t);
        if (t % 2 == 0)
            ou++;
        else
            ji++;
    }
    printf("%d %d", ji, ou);
    return 0;
}
