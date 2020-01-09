#include <stdio.h>

int daysofmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_run(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 1;
    return 0;
}

int whatday(int year, int month, int day) {
    long long days = 0;
    for (int y = 1850; y < year; y++) {
        if (is_run(y) == 1)
            days += 366;
        else
            days += 365;
    }
    if (is_run(year) == 1)
        daysofmonth[1] = 29;
    else
        daysofmonth[1] = 28;
    for (int m = 1; m < month; m++) {
        days += daysofmonth[m - 1];
    }
    days += day;
    return days % 7 + 1;
}

int main() {
    int a, b, c, y1, y2;
    scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2);
    for (int y = y1; y <= y2; y++) {
        int day = 1;
        int wd = whatday(y, a, day); //计算y年a月1日是星期几
        if (wd <= c)
            day += c - wd; // day为y年a月第一个星期c的日期
        else
            day += c + 7 - wd;
        if (a == 2 && is_run(y) == 1)
            daysofmonth[1] = 29;
        else if (a == 2 && is_run(y) == 0)
            daysofmonth[1] = 28;
        day += (b - 1) * 7;
        if (day <= daysofmonth[a - 1])
            printf("%d/%02d/%02d\n", y, a, day);
        else
            printf("none\n");
    }
    return 0;
}