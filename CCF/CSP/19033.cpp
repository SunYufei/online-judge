#include <bits/stdc++.h>
using namespace std;

#define N 1005
#define MAXL 81925

int n; // 阵列中的硬盘数目
int s; // 条带大小（单位：块，1块是4字节）
int l; // 现存的硬盘数目
int m; // 读操作个数
int b; // 块编号（从0计数）
char disk[N][MAXL];
int len; // 磁盘内容字符串长度

int char2digit(char c) { // 十六进制字符转数字
    if (isdigit(c))
        return c - '0';
    return c - 'A' + 10;
}

char digit2char(int d) { //数字转十六进制字符
    if (d < 10)
        return '0' + d;
    return 'A' + d - 10;
}

void calXor(char *a, char *b) { //计算a^b
    for (int i = 0; i < 8; i++)
        a[i] = digit2char(char2digit(a[i]) ^ char2digit(b[i]));
}

char *substr(char *s, int n) { //返回从s起长度为n的字符串
    char *sp = (char *)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; ++i)
        sp[i] = s[i];
    sp[n] = 0;
    return sp;
}

int main() {
    scanf("%d%d%d", &n, &s, &l);
    //读入磁盘信息
    int index = 0; //硬盘顺序号
    for (int i = 0; i < l; ++i) {
        scanf("%d%*c", &index);
        fgets(disk[index], MAXL, stdin);
    }
    len = strlen(disk[index]);

    //处理请求
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b);
        int diskId = b % (n * s) / s;               //盘号
        int lineId = b / ((n - 1) * s) * s + b % s; //行号
        // 块号超过磁盘大小或丢失的盘多于1
        if ((lineId + 1) * 8 > len || (disk[diskId][0] == '\0' && l < n - 1)) {
            printf("-\n");
        } else if (disk[diskId][0] != '\0') { // b块所在盘存在
            printf("%s\n", substr(disk[diskId] + lineId * 8, 8));
        } else { // b块所在盘丢失，但可以还原
            char ans[10] = "00000000";
            for (int j = 0; j < n; ++j) 
                if (j != diskId)
                    calXor(ans, substr(disk[j] + lineId * 8, 8));
            printf("%s\n", ans);
        }
    }
    return 0;
}