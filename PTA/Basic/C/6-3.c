#include <stdio.h>

#define MAXN 10

int Sum(int List[], int N);

int main() {
    int List[MAXN], N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &List[i]);
    printf("%d\n", Sum(List, N));

    return 0;
}

int Sum(int List[], int N) {
    int i, sum = 0;
    for (i = 0; i < N; i++)
        sum += List[i];
    return sum;
}