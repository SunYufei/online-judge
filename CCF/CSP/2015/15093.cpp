#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

const int MAXN = 105;
const int MAXL = 85;
int m, n;
char tpl[MAXN][MAXL];
map<string, string> var;

int main() {
    scanf("%d%d", &m, &n);
    getchar();
    for (int i = 0; i < m; i++) {
        gets(tpl[i]);
    }
    char key[MAXL], value[MAXL];
    for (int i = 0; i < n; i++) {
        scanf("%s ", key);
        gets(value);
        value[0] = value[strlen(value) - 1] = 0;
        var[key] = value + 1;
    }

    for (int i = 0; i < m; i++) {
        char *p1 = tpl[i];
        char *p2;
        p2 = strstr(p1, "{{");
        while (p2 != NULL) {
            *p2 = '\0'; //做特殊处理，方便输出
            cout << p1;
            stringstream ss(p2 + 2);
            string key;
            ss >> key;
            cout << var[key];
            p2 = strstr(p2 + 2, "}}");
            p1 = p2 + 2;
            p2 = strstr(p1, "{{");
        }
        if (p2 == NULL)
            cout << p1 << endl;
    }
    return 0;
}