#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, map<string, int>> map_role_pri;  //角色权限表
map<string, map<string, int>> map_user_pri;  //用户权限表

int p;  //权限数
int r;  //角色数
int u;  //用户数
int q;  //查询数

void getPri(char* str, char* cat, int& level) {  //得到权限的种类和等级
    memset(cat, 0, sizeof(cat));
    level = -1;  //如果没有等级，默认为-1
    int i;
    for (i = 0; str[i] != '\0' && str[i] != ':'; i++) {
        cat[i] = str[i];
    }
    if (str[i] == ':') {
        level = atoi(str + i + 1);
    }
}

int main() {
    char cat[40], role[40], user[40];  //权限类别
    int level;                         //权限等级，无等级则level为-1
    char str[40];

    //只是简单地读取 P 段内容，不做任何处理
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%s", str);
    }

    //读取 R 段内容
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {  //为每个角色建立一张权限表
        int n;
        map<string, int> map_pri;  //权限表
        scanf("%s%d", role, &n);
        while (n--) {
            scanf("%s", str);
            getPri(str, cat, level);
            if (level == -1)
                map_pri[cat] = -1;
            else
                map_pri[cat] =
                    map_pri[cat] > level ? map_pri[cat] : level;  //得到最大权限
        }
        map_role_pri[role] = map_pri;  //将生成的权限表映射到角色role
    }

    //读取 U 段内容
    scanf("%d", &u);
    for (int i = 0; i < u; i++) {  //为每个用户建立一张权限表
        int n;
        map<string, int> map_pri;  //权限表
        map<string, int>::iterator it;
        scanf("%s%d", user, &n);
        while (n--) {
            scanf("%s", role);
            for (it = map_role_pri[role].begin();
                 it != map_role_pri[role].end();
                 it++) {  //遍历角色role的每个权限，将要存入用户权限表
                if (it->second == -1)
                    map_pri[it->first] = -1;
                else
                    map_pri[it->first] = map_pri[it->first] > it->second
                                             ? map_pri[it->first]
                                             : it->second;  //得到最大权限
            }
        }
        map_user_pri[user] = map_pri;  //将生成的权限表映射到用户user
    }

    //读取 Q 段内容
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%s%s", user, str);
        getPri(str, cat, level);
        if (map_user_pri.count(user) == 0 ||
            map_user_pri[user].count(cat) == 0 ||
            level > map_user_pri[user][cat]) {
            printf("false\n");
            continue;
        }
        //拥有角色user和权限cat，且查询的权限小于等于拥有的权限
        if (map_user_pri[user][cat] == -1 ||
            level != -1 && level <= map_user_pri[user][cat]) {
            printf("true\n");
            continue;
        }
        if (level == -1) {
            printf("%d\n", map_user_pri[user][cat]);
        }
    }

    return 0;
}