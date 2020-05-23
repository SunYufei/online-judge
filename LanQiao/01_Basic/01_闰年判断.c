#include <stdbool.h>
#include <stdio.h>

bool isLeap(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }

int main() {
    int y;
    scanf("%d", &y);
    printf(isLeap(y) ? "yes" : "no");
    return 0;
}