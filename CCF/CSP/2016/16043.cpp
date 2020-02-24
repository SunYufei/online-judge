#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> cur_path;  //顺序当前路径的每一级
vector<string> norm_path; //顺序存储目录的每一级
int p;

void split(vector<string> &vec, string path) {
    stringstream ss(path);
    string child;
    vec = cur_path;    //默认从当前路径开始
    bool start = true; //初始标志
    while (getline(ss, child, '/')) {
        if (child.empty()) {
            if (start)
                vec.clear();
        } else if (child == ".") {
            ;
        } else if (child == "..") {
            if (!vec.empty())
                vec.pop_back();
        } else
            vec.push_back(child);
        start = false;
    }
}

void output(vector<string> &vec) {
    vector<string>::iterator it;
    if (vec.empty()) {
        printf("/");
    }
    for (it = vec.begin(); it != vec.end(); it++) {
        printf("/%s", (*it).c_str());
    }
    printf("\n");
}

int main() {
    string path;
    cin >> p >> path;
    cin.ignore();
    split(cur_path, path);
    while (p--) {
        getline(cin, path);
        split(norm_path, path);
        output(norm_path);
    }
    return 0;
}