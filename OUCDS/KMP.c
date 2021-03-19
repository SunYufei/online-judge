#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BuildNext(char* pattern, int* next) {
    int m = strlen(pattern);  // O(m)
    next[0] = -1;
    int i, j;
    for (j = 1; j < m; j++) {  // O(m)
        i = next[j - 1];
        while (i >= 0 && pattern[i + 1] != pattern[j])
            i = next[i];
        if (pattern[i + 1] == pattern[j])
            next[j] = i + 1;
        else
            next[j] = -1;
    }
}

int KMP(char* string, char* pattern) {
    int n = strlen(string);   // O(n)
    int m = strlen(pattern);  // O(m)
    if (n < m)
        return -1;
    // build match
    int* next = (int*)malloc(m * sizeof(int));
    BuildNext(pattern, next);  // O(m)
    int s = 0, p = 0;
    // search
    while (s < n && p < m) {  // O(n + m)
        if (string[s] == pattern[p]) {
            ++s;
            ++p;
        } else if (p > 0)
            p = next[p - 1] + 1;
        else
            ++s;
    }
    free(next);
    return p == m ? s - m : -1;
}

int main() {
    char* string = "This is a simple example.";
    char* pattern = "simple";
    int p = KMP(string, pattern);
    if (p == -1)
        printf("Not Found");
    else
        printf("%s\n", string + p);
    return 0;
}