#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 105;

struct Selector {
    int row;
    int rank;
    string label;
    string id;
};

int n, m;
Selector sel[MAXN];
string html, css;

int main() {
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 1; i <= n; i++) {
        getline(cin, html);
        sel[i].row = i;

        istringstream ss(html);
        string str;

        ss >> str;
        int cd;
        for (cd = 0; str[cd] == '.'; cd++)
            ;
        sel[i].rank = cd / 2;          //计算层级
        sel[i].label = str.substr(cd); //获取标签
        transform(sel[i].label.begin(), sel[i].label.end(),
                  sel[i].label.begin(), ::tolower); //转换小写

        while (ss >> str) { //获取id属性
            if (str[0] == '#')
                sel[i].id = str;
        }
    }

    for (int i = 0; i < m; i++) {
        getline(cin, css);
        istringstream ss(css);
        vector<string> query;
        string str;
        while (ss >> str) { //存储查询条件
            if (str[0] != '#') {
                transform(str.begin(), str.end(), str.begin(), ::tolower);
            }
            query.push_back(str);
        }

        //查询条件的最后一个标签或属性是关键字

        int ans[MAXN]; //存储满足条件的行数
        int cnt = 0;   //计数
        int num;       //实际满足条件的个数
        vector<string>::reverse_iterator it = query.rbegin();
        for (int j = 1; j <= n; j++) {
            if (sel[j].id == *it || sel[j].label == *it) {
                ans[cnt++] = j;
            }
        }
        num = cnt;

        for (int c = 0; c < cnt; c++) { //遍历每个关键字，判断是否满足条件
            it = query.rbegin() + 1;
            int mrank = sel[ans[c]].rank;
            for (int j = ans[c] - 1; it != query.rend() && j > 0; j--) {
                if (sel[j].rank < mrank &&
                    (*it == sel[j].label || *it == sel[j].id)) {
                    it++;
                    mrank = sel[j].rank;
                }
            }
            if (it != query.rend()) {
                ans[c] = 0;
                num--;
            }
        }

        cout << num;
        for (int j = 0; j < cnt; j++) {
            if (ans[j]) {
                cout << " " << ans[j];
            }
        }
        cout << endl;
    }
    return 0;
}