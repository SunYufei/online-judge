#include <string.h>

int is_date(char *date) {
    if (strlen(date) != 8) // 是否为8位
        return 0;
    for (int i = 0; i < 8; i++) { // 判断输入是否为数字
        if (date[i] <= '9' && date[i] >= '0')
            continue;
        else
            return 0;
    }
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y = (date[0] - '0') * 1000 + (date[1] - '0') * 100 +
            (date[2] - '0') * 10 + (date[3] - '0');
    int m = (date[4] - '0') * 10 + (date[5] - '0');
    int d = (date[6] - '0') * 10 + (date[7] - '0');
    if (y < 1000 || y > 9999)
        return 0;
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        day[1] = 29;
    if (m == 0 || m > 12)
        return 0;
    if (d == 0 || d > day[m - 1])
        return 0;
    return 1;
}