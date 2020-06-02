#include <algorithm>
#include <ctype.h>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const char *month = "janfebmaraprmayjunjulaugsepoctnovdec";
const char *weekday = "sunmontuewedthufrisat";
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Command {
    int no;         //编号
    long long time; //时间
    char name[105]; //名称
    bool operator<(const Command &rhs) const {
        if (time == rhs.time)
            return no < rhs.no;
        return time < rhs.time;
    }
    bool operator==(const Command &rhs) const {
        return strcmp(name, rhs.name) == 0 && time == rhs.time;
    }
} command[10005];
int tot; //对执行命令计数

int n;                           //输入命令个数
long long startTime, finishTime; //开始时间和结束时间
char input[6][105]; //每条命令含有6个参数，type依次是【Minutes】【Hours】【day
                    // of month】【month】【day of week】【name】
set<int> timeRange[5]; //时间值范围集合，type依次是【Minutes】【Hours】【day of
                       // month】【month】【day of week】
set<int>::iterator M, H, dm, m; //对应上一行的前4个迭代器

void getTimeRange(int type, char *str); //对input[type]获取时间值范围
int addTimeRange(int type, int start,
                 int finish); //对timeRange[type]增加时间值范围
void addCommand();            //对获取到的时间值范围添加命令
//工具类函数
int getValue(int &i, char *str);         //从str[i]起得到一个时间值
long long getToday(int y, int m, int d); //计算今天的日期
int getDayofWeek(int y, int m, int d);   //计算今天是星期几

int main() {
    scanf("%d%lld%lld", &n, &startTime, &finishTime);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++)
            timeRange[j].clear();
        for (int j = 0; j < 6; j++) { //读入每条命令的6个参数，并对前5个参数处理
            scanf("%s", input[j]);
            if (j != 5)
                getTimeRange(j, input[j]);
        }
        addCommand();
    }
    sort(command, command + tot);
    tot = unique(command, command + tot) - command; //忽略重复的
    for (int i = 0; i < tot; i++)
        printf("%lld %s\n", command[i].time, command[i].name);
    return 0;
}

void getTimeRange(int type, char *str) {
    int start = 0, finish = 0;
    //处理星号表示的时间值范围
    if (str[0] == '*') {
        if (type == 0)
            start = 0, finish = 59;
        else if (type == 1)
            start = 0, finish = 23;
        else if (type == 2)
            start = 1, finish = 31;
        else if (type == 3)
            start = 1, finish = 12;
        else if (type == 4)
            start = 0, finish = 6;
        addTimeRange(type, start, finish);
        return;
    }
    //处理横杠和逗号表示的时间值范围
    int i = 0;
    int len = strlen(str);
    while (i < len) {
        start = getValue(i, str); //获取一个值，如果后接'-'，继续获取下一个值
        if (str[i] == '-')
            finish = getValue(++i, str);
        else
            finish = start;
        addTimeRange(type, start, finish);
    }
}

void addCommand() {
    long long today, time;
    int dayofWeek;
    int y1 = startTime / 1e8, y2 = finishTime / 1e8;
    int startDay = startTime / 1e4;
    for (int y = y1; y <= y2; y++)                                   // year
        for (m = timeRange[3].begin(); m != timeRange[3].end(); m++) // month
            for (dm = timeRange[2].begin(); dm != timeRange[2].end();
                 dm++) {                      // day of month
                today = getToday(y, *m, *dm); //得到今天的日期
                if (today >= startDay &&
                    timeRange[4].count(getDayofWeek(
                        y, *m, *dm))) { //今天是星期几，是否在day of week中
                    for (H = timeRange[1].begin(); H != timeRange[1].end();
                         H++) // Hours
                        for (M = timeRange[0].begin(); M != timeRange[0].end();
                             M++) { // Minutes
                            time = today * 1e4 + (*H) * 1e2 + (*M);
                            if (time >= startTime && time < finishTime) {
                                strcpy(command[tot].name, input[5]);
                                command[tot].time = time;
                                command[tot].no = tot;
                                tot++;
                            } else if (time >= finishTime)
                                return;
                        }
                }
            }
}

int getValue(int &i, char *str) {
    char value[105];
    int cnt = 0;
    int len = strlen(str);
    while (i < len) {
        //如果是数值
        if (isdigit(str[i])) {
            while (i < len && isdigit(str[i])) {
                value[cnt++] = str[i++];
            }
            value[cnt] = '\0';
            return atoi(value);
        }
        //如果是字母
        else if (isalpha(str[i])) {
            while (i < len && isalpha(str[i])) {
                value[cnt++] = tolower(str[i++]);
            }
            value[cnt] = '\0';
            char *p = strstr(month, value);
            if (p)
                return (p - month) / 3 + 1;
            else if (p = strstr(weekday, value))
                return (p - weekday) / 3;
        } else
            i++;
    }
    return -1;
}

int addTimeRange(int type, int start, int finish) {
    for (int i = start; i <= finish; i++) {
        timeRange[type].insert(i);
    }
}

long long getToday(int y, int m, int d) {
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        days[1] = 29;
    else
        days[1] = 28;
    if (d > days[m - 1])
        return -1;
    return y * 1e4 + m * 1e2 + d;
}

int getDayofWeek(int y, int m, int d) {
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) %
           7;
}