#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#define MAXN 105
using namespace std;

char rule[MAXN][MAXN];
char name[MAXN][MAXN];
int n, m;
vector<string> value;  //参数值

bool deal_str(char* str, char* rule) {
    value.clear();
    int i = 0, j = 0;
    while (i < strlen(str) && j < strlen(rule)) {
        if (rule[j] == '<') {
            string tmp;
            if (rule[j + 1] == 'i') {
                int flag = 0;  //判断前导0的标志
                while (str[i] != '\0' && str[i] != '/') {
                    if (str[i] < '0' || str[i] > '9')
                        return false;
                    if (flag == 0 && str[i] == '0') {
                        i++;
                        continue;
                    }
                    flag = 1;
                    tmp += str[i];
                    i++;
                }
            } else if (rule[j + 1] == 's') {
                while (str[i] != '\0' && str[i] != '/') {
                    tmp += str[i];
                    i++;
                }
            } else if (rule[j + 1] == 'p') {
                while (str[i] != '\0') {
                    tmp += str[i];
                    i++;
                }
                value.push_back(tmp);
                return true;
            }
            value.push_back(tmp);
            if (strchr(rule + j, '/') != NULL)
                j = strchr(rule + j, '/') - rule;
            else
                j = strlen(rule);
            continue;
        }
        if (str[i] == rule[j]) {
            i++;
            j++;
            continue;
        }
        return false;
    }
    if (i == strlen(str) && j == strlen(rule))
        return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s%s", rule[i], name[i]);
    }
    char str[MAXN];
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        int flag = 0;
        int j;
        for (j = 0; j < n; j++) {
            if (deal_str(str, rule[j]) == true) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("%s ", name[j]);
            for (int j = 0; j < value.size(); j++) {
                printf("%s ", value[j].c_str());
            }
            printf("\n");
        } else
            printf("404\n");
    }
    return 0;
}