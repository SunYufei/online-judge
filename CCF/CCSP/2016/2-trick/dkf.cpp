#include <bits/stdc++.h>
#define clr(a) memset(a, 0, sizeof(a))
using namespace std;

typedef unsigned short data_t;
const int MaxC = 1 << 16, MaxM = 1 << 16, MemL = 0x3000, MemR = 0xb000,
          MaxN = 110 << 2;
const int LIMIT = 1000000, BIT_MASK = (1 << 8) - 1;
const int MaxI = 1 << 5;

char str[MaxN][MaxI];
int strtot;
int ins_pos[MaxN], instot;

void data_error() {
    puts("data error");
    exit(0);
}

bool strequ(const char* s, const char* t) {
    if (strlen(s) != strlen(t))
        return 0;
    for (int i = 0; s[i]; ++i)
        if (s[i] != t[i])
            return 0;
    return 1;
}

int value_type(const char* s) {
    if (s[1] == 'X') {
        if (s[1] == 'X' && s[0] >= 'A' && s[0] <= 'D' && s[2] == 0)
            return 2;
        data_error();
    } else if (s[0] == 'T') {
        if (s[2] == 'X' && s[1] >= 'A' && s[1] <= 'D' && s[3] == 0)
            return 1;
        for (int i = 1; i <= 4; ++i)
            if (!(s[i] <= 'F' && s[i] >= '0'))
                data_error();
        if (s[5] != 0)
            data_error();
        return 1;
    } else {
        for (int i = 0; i <= 3; ++i)
            if (!(s[i] <= 'F' && s[i] >= '0'))
                data_error();
        if (s[4] != 0)
            data_error();
        return 0;
    }
    return -1;
}

void data_checker() {
    for (int i = 2; i < instot; ++i) {
        int ins_len = 0;
        int now = ins_pos[i];
        if (strequ(str[now], "ECHO")) {
            ins_len = 2;
            value_type(str[now + 1]);
        } else if (strequ(str[now], "ADD")) {
            ins_len = 3;
            if (value_type(str[now + 1]) == 0)
                data_error();
            if (value_type(str[now + 2]) == 1 && value_type(str[now + 1]) == 1)
                data_error();  // <-
        } else if (strequ(str[now], "INC")) {
            ins_len = 2;
            if (value_type(str[now + 1]) == 0)
                data_error();
        } else if (strequ(str[now], "MOV")) {
            ins_len = 3;
            if (value_type(str[now + 1]) == 0)
                data_error();
            if (value_type(str[now + 2]) == 1 && value_type(str[now + 1]) == 1)
                data_error();  // <-
        } else if (strequ(str[now], "CMP")) {
            ins_len = 3;
            if (value_type(str[now + 2]) == 1 && value_type(str[now + 1]) == 1)
                data_error();  // <-
        } else {
            if (strequ(str[now], "JMP") || strequ(str[now], "JG") ||
                strequ(str[now], "JL") || strequ(str[now], "JE") ||
                strequ(str[now], "JNG") || strequ(str[now], "JNL") ||
                strequ(str[now], "JNE")) {
                ins_len = 2;
                value_type(str[now + 1]);
            } else
                data_error();
        }
        if (ins_pos[i + 1] - ins_pos[i] != ins_len)
            data_error();
    }
    if (!strequ(str[ins_pos[1]], "RUN") ||
        !strequ(str[ins_pos[instot]], "STOP") || ins_pos[2] - ins_pos[1] != 1 ||
        strtot - ins_pos[instot] != 1)
        data_error();
}

void decode(char* s) {
    int total = 0;
    while (sscanf(s + total, "%s", str[strtot]) == 1) {
        total += strlen(str[strtot]);
        if (s[total] == ' ')
            ++total;
        ++strtot;
    }
}

void input() {
    char s[1 << 8];
    while (cin.getline(s, 1 << 8)) {
        ++instot;
        ins_pos[instot] = strtot;
        decode(s);
    }
    data_checker();
}

void CMP() {
    puts("CMP_MISSING");
    exit(0);
}

void ACC() {
    puts("ACCESS_VIOLATION");
    exit(0);
}

void RE() {
    puts("RUNTIME_ERROR");
    exit(0);
}

void TLE() {
    puts("TLE");
    exit(0);
}

data_t reg[4], mem[MaxM];
int ins, cmpx, cmpy;
int step;

char chr[16];

int inv_chr(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return c - 'A' + 10;
}
int read_4_digit(const char* s) {
    int ret = 0;
    for (int i = 0; i < 4; ++i)
        ret = ret << 4 | inv_chr(s[i]);
    return ret;
}

int get_val(const char* s) {
    if (s[0] == 'T') {
        int pos = get_val(s + 1);
        if (pos + 1 >= MemR || pos < MemL)
            ACC();
        return mem[pos + 1] << 8 | mem[pos];
    } else if (s[1] == 'X') {
        int pos = s[0] - 'A';
        return reg[pos];
    } else {
        int pos = read_4_digit(s);
        return pos;
    }
}

void write(const char* s, int val) {
    if (s[0] == 'T') {
        int pos = get_val(s + 1);
        if (pos + 1 >= MemR || pos < MemL)
            ACC();
        mem[pos + 1] = (val >> 8) & BIT_MASK;
        mem[pos] = val & BIT_MASK;
    } else {
        int pos = s[0] - 'A';
        reg[pos] = val;
    }
}

void output(int val) {
    static char buf[5];
    for (int i = 0; i < 4; ++i, val >>= 4)
        buf[3 - i] = chr[val & 15];
    printf("%s\n", buf);
}

void execuit(int id) {
    ++step;
    if (str[id][0] == 'R')
        return;
    else if (str[id][0] == 'S')
        exit(0);
    else if (str[id][0] == 'E') {
        data_t val = get_val(str[id + 1]);
        output(val);
    } else if (str[id][0] == 'A') {
        data_t x = get_val(str[id + 1]), v = get_val(str[id + 2]);
        x += v;
        write(str[id + 1], x);
    } else if (str[id][0] == 'I') {
        data_t x = get_val(str[id + 1]);
        ++x;
        write(str[id + 1], x);
    } else if (str[id][0] == 'M') {
        data_t y = get_val(str[id + 2]);
        write(str[id + 1], y);
    } else if (str[id][0] == 'C') {
        data_t x = get_val(str[id + 1]), y = get_val(str[id + 2]);
        cmpx = x, cmpy = y;
    } else if (str[id][0] == 'J') {
        bool flag = 0;
        if (str[id][1] == 'M')
            flag = 1;
        else {
            if (cmpx == -1)
                CMP();
            if (str[id][1] == 'G')
                flag = (cmpx > cmpy);
            else if (str[id][1] == 'L')
                flag = (cmpx < cmpy);
            else if (str[id][1] == 'E')
                flag = (cmpx == cmpy);
            else if (str[id][1] == 'N' && str[id][2] == 'G')
                flag = !(cmpx > cmpy);
            else if (str[id][1] == 'N' && str[id][2] == 'L')
                flag = !(cmpx < cmpy);
            else if (str[id][1] == 'N' && str[id][2] == 'E')
                flag = !(cmpx == cmpy);
        }

        if (flag) {
            ins = get_val(str[id + 1]);
            if (ins < 2 || ins > instot)
                RE();
        }
    }
}

void run() {
    cmpx = cmpy = -1;
    ins = 1;

    while (ins != instot) {
        ++ins;
        execuit(ins_pos[ins - 1]);
        if (step == LIMIT)
            TLE();
    }
}

void init() {
    clr(reg);
    clr(mem);
    memset(str, 0, sizeof(str));
    strtot = instot = 0;
    for (int i = 0; i <= 9; ++i)
        chr[i] = '0' + i;
    for (int i = 0; i <= 5; ++i)
        chr[i + 10] = 'A' + i;
}

int main() {
    init();
    input();
    run();
    return 0;
}
