#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

struct Cmd {
    string op;
    string arg;
    bool operator<(const Cmd& rhs) const { return op < rhs.op; }
};

Cmd cmd;
set<Cmd> cs;
string allop;
int N;

int main() {
    cin >> allop >> N;
    string str;
    for (int i = 1; i <= N; i++) {
        cs.clear();

        cin >> str;  //读入命令，不做任何处理
        getline(cin, str);
        stringstream ss(str);
        while (ss >> str) {
            int pos = 0;
            if (str.length() == 2 && str[0] == '-' &&
                (pos = allop.find(str[1])) !=
                    string::npos) {  //判断为给定的合法选项
                cmd.op = str;
                if (pos + 1 < allop.length() &&
                    allop[pos + 1] == ':') {  //判断为带参数选项
                    ss >> cmd.arg;            //读入参数

                    if (cmd.arg == "")
                        break;
                    set<Cmd>::iterator it =
                        cs.find(Cmd{cmd.op, cmd.arg});  //判断为存在该带参数选项
                    if (it != cs.end())
                        cs.erase(it);  //删除它
                } else
                    cmd.arg = "";

                cs.insert(cmd);
            } else
                break;
        }

        cout << "Case " << i << ": ";
        for (set<Cmd>::iterator it = cs.begin(); it != cs.end(); it++) {
            cout << (*it).op << ((*it).arg == "" ? "" : " ") << (*it).arg
                 << " ";
        }
        cout << endl;
    }
    return 0;
}