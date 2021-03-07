#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
const int PLEN = 64;
const int SLEN = 8;
const int MAX_TOT_LINE = 10000;

struct ptable_type {
    int input_size, output_size;
    int element[PLEN];
};

struct sbox_type {
    int input_size, output_size;
    int element[1 << SLEN];
};

struct lex_type {
    string name;
    int type;
    unsigned long long value;
};

struct bs_var_type {
    string name;
    int len;
    unsigned long long value;
    vector<bs_var_type*> ch;
};

struct expr_type {
    int id;
    int type;
    unsigned long long value;
    vector<int> bs_varp;
    expr_type *expr1, *expr2;
};

struct gra_type {
    int type, var, value, jmp;
    vector<int> bs_varp;
    expr_type* expr;
    int st, ed;  // lex[st] .. lex[ed]
};

int n, m;
ptable_type ptable[MAXN];
sbox_type sbox[MAXN];

string task_id;
string code;  // store all characters of the code
int loop_var[26];
vector<bs_var_type> bs_var;
vector<lex_type> lex;
vector<gra_type> gra;
stack<int> loop_pos;
vector<expr_type*> expr_ptr;

void bs_to_num(const string& str, unsigned long long& num) {
    num = 0;
    for (int i = 0; i < str.length(); i++)
        num = (num << 1) + str[i] - '0';
}

void num_to_bs(const unsigned long long& num, string& str, int size = PLEN) {
    str.clear();
    unsigned long long tmp = 1ull << (size - 1);
    while (tmp) {
        if (num & tmp)
            str.push_back('1');
        else
            str.push_back('0');
        tmp = tmp >> 1;
    }
}

string int_to_str(int i) {
    string str;
    stack<char> s;
    char ch;
    if (i == 0) {
        str = "0";
        return str;
    }
    if (i < 0) {
        str.push_back('-');
        i = -i;
    }
    while (i > 0) {
        ch = '0' + (i % 10);
        s.push(ch);
        i /= 10;
    }
    while (!s.empty()) {
        str.push_back(s.top());
        s.pop();
    }
    return str;
}

void read_ptable() {
    for (int i = 0; i < n; i++) {
        int a, b, x;
        cin >> a >> b;
        ptable[i].input_size = a;
        ptable[i].output_size = b;
        for (int j = 0; j < b; j++) {
            cin >> x;
            ptable[i].element[j] = x;
        }
    }
}

void read_sbox() {
    for (int i = 0; i < m; i++) {
        int c, d, x;
        cin >> c >> d;
        sbox[i].input_size = c;
        sbox[i].output_size = d;
        for (int j = 0; j < (1 << c); j++) {
            cin >> x;
            sbox[i].element[j] = x;
        }
    }
}

void read_code() {
    char ch;
    while (ch != '\n')
        cin.get(ch);
    bool meet_end = false;
    while (true) {
        cin.get(ch);
        code.push_back(ch);
        if (ch == 'D')
            meet_end = true;
        if (ch == 'L')
            meet_end = false;
        if (ch == '\n' && meet_end)
            break;
    }
}

void get_bs_var(int l, int r, unsigned long long& value, vector<int>& bs_varp) {
    value = lex[l].value;
    int i = l + 1;
    while (i < r) {
        if (lex[i + 1].type == 1)
            bs_varp.push_back((int)(lex[i + 1].value) -
                              26);  // 0..25 -> -26..-1
        else
            bs_varp.push_back(lex[i + 1].value);  // 0..63
        i += 3;
    }
}

int find_bs(string& name) {
    for (int i = 0; i < bs_var.size(); i++)
        if (bs_var[i].name == name)
            return i;
    return -1;
}

void lex_ana() {
    char type5[7] = {'=', '+', '(', ')', '[', ']', '\n'};
    string type0[8] = {"BEGIN", "END",     "P",     "S",
                       "LOOP",  "ENDLOOP", "SPLIT", "MERGE"};
    int i = 0, j;
    string str;
    lex_type tmp;
    while (i < code.length()) {
        while (code[i] == ',' || code[i] == ' ' || code[i] == '\t')
            ++i;
        str.push_back(code[i]);
        ++i;
        if (str[0] >= 'A' && str[0] <= 'Z') {  // type 0
            while (i < code.length() && code[i] >= 'A' && code[i] <= 'Z') {
                str.push_back(code[i]);
                ++i;
            }
            for (j = 0; j < 8; j++)
                if (str == type0[j])
                    break;
            tmp.name = str;
            tmp.type = 0;
            tmp.value = j;
            lex.push_back(tmp);
        } else if (str[0] >= 'a' && str[0] <= 'z') {  // type 1 or 2
            while (i < code.length() && code[i] >= 'a' && code[i] <= 'z') {
                str.push_back(code[i]);
                i++;
            }
            if (str.length() == 1) {  // type 1
                tmp.name = str;
                tmp.type = 1;
                tmp.value = str[0] - 'a';
                lex.push_back(tmp);
            } else {  // type 2
                j = find_bs(str);
                if (j == -1) {
                    j = bs_var.size();
                    bs_var_type beta;
                    beta.name = str;
                    beta.len = 0;
                    beta.value = 0;
                    bs_var.push_back(beta);
                }
                tmp.name = str;
                tmp.type = 2;
                tmp.value = j;
                lex.push_back(tmp);
            }
        } else if (str[0] >= '0' && str[0] <= '9') {  // type 3
            while (i < code.length() && code[i] >= '0' && code[i] <= '9') {
                str.push_back(code[i]);
                ++i;
            }
            tmp.name = str;
            tmp.type = 3;
            tmp.value = str[0] - '0';
            for (j = 1; j < str.length(); j++)
                tmp.value = tmp.value * 10 + str[j] - '0';
            lex.push_back(tmp);
        } else if (str[0] == '\"') {  // type 4
            while (code[i] >= '0' && code[i] <= '1') {
                str.push_back(code[i]);
                ++i;
            }
            str.push_back(code[i]);
            ++i;
            int k = str.length();
            tmp.name = str;
            tmp.type = 4;
            tmp.value = 0;
            for (j = 1; j < k - 1; ++j)
                tmp.value = (tmp.value << 1) + str[j] - '0';
            lex.push_back(tmp);
        } else {  // type 5
            for (j = 0; j < 7; j++)
                if (str[0] == type5[j])
                    break;
            tmp.name = str;
            tmp.type = 5;
            tmp.value = j;
            lex.push_back(tmp);
        }
        str.clear();
    }
}

void init_bs_var() {
    int i = 0;
    while (lex[i].name != "BEGIN") {
        int tmp = lex[i].value;
        int beta = lex[i + 2].value;
        bs_var[tmp].len = beta;
        bs_var[tmp].value = 0;
        i += 5;
    }
}

expr_type* generate_expr(int l, int r) {
    expr_type* ptr = new expr_type;
    ptr->id = expr_ptr.size();
    expr_ptr.push_back(ptr);
    ptr->expr1 = NULL;
    ptr->expr2 = NULL;
    ptr->value = 0;
    int num = 0;
    int i = l;
    while (i <= r) {
        if (lex[i].name == "(")
            num++;
        if (lex[i].name == ")")
            num--;
        if (lex[i].name == "+" && num == 0)
            break;
        i++;
    }
    if (i <= r) {
        ptr->type = 2;
        ptr->expr1 = generate_expr(l, i - 1);
        ptr->expr2 = generate_expr(i + 1, r);
        return ptr;
    }
    if (lex[l].name == "P" || lex[l].name == "S") {
        if (lex[l].name == "P")
            ptr->type = 3;
        else
            ptr->type = 4;
        if (lex[l + 2].type == 1)
            ptr->value = lex[l + 2].value - 26;
        else if (lex[l + 2].type == 3)
            ptr->value = lex[l + 2].value;
        ptr->expr1 = generate_expr(l + 5, r - 1);
        return ptr;
    }
    if (lex[l].type == 4) {
        ptr->type = 1;
        ptr->value = lex[l].value;
        return ptr;
    }
    if (lex[l].type == 2) {
        ptr->type = 0;
        get_bs_var(l, r, ptr->value, ptr->bs_varp);
        return ptr;
    }
}

void generate_gra(int l, int r) {
    gra_type tmp;
    tmp.st = l;
    tmp.ed = r;
    tmp.var = tmp.value = tmp.jmp = 0;
    tmp.expr = NULL;
    if (lex[l].name == "BEGIN") {
        tmp.type = 0;
        tmp.value = 0;
    } else if (lex[l].name == "END") {
        tmp.type = 0;
        tmp.value = 1;
    } else if (lex[l].name == "LOOP") {
        tmp.type = 2;
        tmp.var = lex[l + 1].value;
        tmp.value = lex[l + 2].value;
        tmp.jmp = lex[l + 3].value;
        loop_pos.push(gra.size());
    } else if (lex[l].name == "ENDLOOP") {
        int pos = loop_pos.top();
        loop_pos.pop();
        tmp.type = 3;
        tmp.var = gra[pos].var;
        tmp.value = gra[pos].jmp;
        gra[pos].jmp = 0;
        tmp.jmp = pos + 1;
    } else if (lex[l].name == "SPLIT") {
        tmp.type = 4;
        tmp.value = lex[r - 2].value;
        unsigned long long beta;
        get_bs_var(l + 2, r - 3, beta, tmp.bs_varp);
        tmp.var = beta;
    } else if (lex[l].name == "MERGE") {
        tmp.type = 5;
        unsigned long long beta;
        get_bs_var(l + 2, r - 2, beta, tmp.bs_varp);
        tmp.var = beta;
    } else if (lex[l].type == 2) {  // assignment statement
        int i = l;
        while (i <= r && lex[i].name != "=")
            ++i;
        tmp.type = 1;
        unsigned long long beta;
        get_bs_var(l, i - 1, beta, tmp.bs_varp);
        tmp.var = beta;
        tmp.expr = generate_expr(i + 1, r - 1);
    }
    gra.push_back(tmp);
}

void gra_ana() {
    int i = 0, j;
    for (i = 0; lex[i].name != "BEGIN"; i++)
        ;
    while (i < lex.size()) {
        for (j = i; lex[j].name != "\n"; j++)
            ;
        generate_gra(i, j);
        i = j + 1;
    }
}

bs_var_type* find_bs_varp(long long pos, const vector<int>& bs_varp) {
    bs_var_type* ptr = &bs_var[pos];
    for (int i = 0; i < bs_varp.size(); i++) {
        int j = bs_varp[i];
        if (j < 0)
            j = loop_var[j + 26];
        ptr = ptr->ch[j];
    }
    return ptr;
}

unsigned long long cal_expr(expr_type* ptr) {
    if (ptr->type == 0)
        return find_bs_varp(ptr->value, ptr->bs_varp)->value;
    else if (ptr->type == 1)
        return ptr->value;
    else if (ptr->type == 2)
        return cal_expr(ptr->expr1) ^ cal_expr(ptr->expr2);
    else if (ptr->type == 3) {
        unsigned long long tmp = cal_expr(ptr->expr1);
        long long j = ptr->value;
        if (j < 0)
            j = loop_var[j + 26];
        string sin, sout;
        num_to_bs(tmp, sin, ptable[j].input_size);
        for (int i = 0; i < ptable[j].output_size; i++)
            sout.push_back(sin[ptable[j].element[i]]);
        bs_to_num(sout, tmp);
        return tmp;
    } else if (ptr->type == 4) {
        unsigned long long tmp = cal_expr(ptr->expr1);
        long long j = ptr->value;
        if (j < 0)
            j = loop_var[j + 26];
        return sbox[j].element[tmp];
    }
}

unsigned long long encrypt(unsigned long long state, unsigned long long key) {
    int now = 0;
    while (true) {
        if (gra[now].type == 0) {
            if (gra[now].value == 0) {  // BEGIN
                bs_var[0].value = state;
                bs_var[1].value = key;
                for (int i = 2; i < bs_var.size(); i++)
                    bs_var[i].value = 0;
                now++;
            } else
                return bs_var[0].value;  // END
        } else if (gra[now].type == 1) {
            bs_var_type* ptr = find_bs_varp(gra[now].var, gra[now].bs_varp);
            ptr->value = cal_expr(gra[now].expr);
            now++;
        } else if (gra[now].type == 2) {
            loop_var[gra[now].var] = gra[now].value;
            now++;
        } else if (gra[now].type == 3) {
            loop_var[gra[now].var]++;
            if (loop_var[gra[now].var] > gra[now].value)
                ++now;
            else
                now = gra[now].jmp;
        } else if (gra[now].type == 4) {
            bs_var_type* ptr = find_bs_varp(gra[now].var, gra[now].bs_varp);
            int tmp = gra[now].value;
            int chlen = ptr->len / tmp;
            for (int i = 0; i < tmp; i++) {
                bs_var_type* chptr = new bs_var_type;
                chptr->len = chlen;
                chptr->name = ptr->name + "[" + int_to_str(i) + "]";
                chptr->value = 0;
                ptr->ch.push_back(chptr);
            }
            unsigned long long beta = (1ull << chlen) - 1;
            for (int i = tmp - 1; i >= 0; i--) {
                ptr->ch[i]->value = ptr->value & beta;
                ptr->value = ptr->value >> chlen;
            }
            ++now;
        } else if (gra[now].type == 5) {
            bs_var_type* ptr = find_bs_varp(gra[now].var, gra[now].bs_varp);
            int tmp = ptr->ch.size();
            int chlen = ptr->len / tmp;
            ptr->value = 0;
            for (int i = 0; i < tmp; i++) {
                bs_var_type* chptr = ptr->ch[i];
                ptr->value = (ptr->value << chlen) | chptr->value;
                delete chptr;
            }
            ptr->ch.clear();
            ++now;
        }
    }
}

void solve_task1() {
    int k;
    unsigned long long state, key;
    string str1, str2;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> str1 >> str2;
        bs_to_num(str1, state);
        bs_to_num(str2, key);
        num_to_bs(encrypt(state, key), str1, bs_var[0].len);
        cout << str1 << endl;
    }
}

void task2_init() {
    code = "state(32)\n";
    code += "key(12)\n";
    code += "dkey(16)\n";
    code += "tmp(32)\n";
    code += "BEGIN\n";
    code += "SPLIT(dkey,4)\n";
    code += "SPLIT(key,3)\n";
    code += "dkey[0] = key[0]\n";
    code += "dkey[1] = key[1]\n";
    code += "dkey[2] = key[2]\n";
    code += "dkey[3] = key[0] + key[1] + key[2]\n";
    code += "MERGE(key)\n";
    code += "MERGE(dkey)\n";
    code += "LOOP i 1 16\n";
    code += "dkey = P[2](dkey)\n";
    code += "tmp = state\n";
    code += "SPLIT(state,2)\n";
    code += "SPLIT(tmp,2)\n";
    code += "state[0] = tmp[1]\n";
    code += "tmp[1] = tmp[1] + dkey\n";
    code += "SPLIT(tmp[1],4)\n";
    code += "LOOP j 0 3\n";
    code += "tmp[1][j] = S[0](tmp[1][j])\n";
    code += "ENDLOOP\n";
    code += "MERGE(tmp[1])\n";
    code += "state[1] = tmp[0] + P[0](tmp[1])\n";
    code += "MERGE(state)\n";
    code += "MERGE(tmp)\n";
    code += "dkey = P[1](dkey)\n";
    code += "ENDLOOP\n";
    code += "tmp = state\n";
    code += "SPLIT(state,2)\n";
    code += "SPLIT(tmp,2)\n";
    code += "state[0] = tmp[1]\n";
    code += "state[1] = tmp[0]\n";
    code += "MERGE(state)\n";
    code += "MERGE(tmp)\n";
    code += "END\n";
    n = 3;
    m = 1;
    ptable[0].input_size = 16;
    ptable[0].output_size = 16;
    ptable[1].input_size = 16;
    ptable[1].output_size = 16;
    ptable[2].input_size = 16;
    ptable[2].output_size = 16;
    sbox[0].input_size = 4;
    sbox[0].output_size = 4;
    int p0[16] = {12, 1, 9, 2, 0, 11, 7, 3, 4, 15, 8, 5, 14, 13, 10, 6};
    int p1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    int p2[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int s0[16] = {12, 5, 6, 11, 9, 0, 10, 13, 3, 14, 15, 8, 4, 7, 1, 2};
    for (int i = 0; i < 16; i++) {
        ptable[0].element[i] = p0[i];
        ptable[1].element[i] = p1[i];
        ptable[2].element[i] = p2[i];
        sbox[0].element[i] = s0[i];
    }
}

void solve_task2() {
    unsigned long long state, ans, tmp;
    string str1, str2;
    int key1, key2;
    map<unsigned long long, int> h;
    cin >> str1 >> str2;
    bs_to_num(str1, state);
    bs_to_num(str2, ans);
    for (int i = 0; i < 4096; i++) {
        tmp = encrypt(state, i);
        h[tmp] = i;
    }
    int p1[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int p2[16] = {15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    for (int i = 0; i < 16; i++) {
        ptable[1].element[i] = p1[i];
        ptable[2].element[i] = p2[i];
    }
    for (int i = 0; i < 4096; i++) {
        tmp = encrypt(ans, i);
        if (h.find(tmp) == h.end())
            continue;
        key1 = h[tmp];
        key2 = i;
        num_to_bs(key1, str1, 12);
        num_to_bs(key2, str2, 12);
        cout << "YES" << endl;
        cout << str1 << endl;
        cout << str2 << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    cin >> task_id;
    if (task_id == "TASKA") {
        cin >> n >> m;
        read_ptable();
        read_sbox();
        read_code();
        lex_ana();
        init_bs_var();
        gra_ana();
        solve_task1();
    } else if (task_id == "TASKB") {
        task2_init();
        lex_ana();
        init_bs_var();
        gra_ana();
        solve_task2();
    }
    return 0;
}