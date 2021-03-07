#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Role {
    int health;
    int attack;
    Role* next;
};

int n;                         //操作数
char op[10];                   //操作类型
int position, attack, health;  //位置编号1-7，攻击力，生命值
int attacker, defender;        //攻击者编号1-7，防守者编号0-7

Role *A, *B;  //游戏双方
Role* role;

void insert(Role*& r,
            int p,
            int a,
            int h) {  //在选手r的战场p位置插入攻击力为a、生命值为h的角色
    Role* l = r;
    role = (Role*)malloc(sizeof(Role));
    role->attack = a;
    role->health = h;
    role->next = NULL;

    if (r == NULL) {
        r = role;
        return;
    }

    while (--p > 0)
        l = l->next;
    role->next = l->next;
    l->next = role;
}

void update(int p1, int p2) {  //更新角色生命值
    Role *l1 = A, *l2 = B;
    Role *pre1 = A, *pre2 = B;

    while (p1-- > 0) {
        pre1 = l1;
        l1 = l1->next;
    }
    while (p2-- > 0) {
        pre2 = l2;
        l2 = l2->next;
    }
    l1->health -= l2->attack;
    l2->health -= l1->attack;

    if (l1->health <= 0 && l1 != A)
        pre1->next = l1->next;  //删除随从。注意英雄不会从战场消失
    if (l2->health <= 0 && l2 != B)
        pre2->next = l2->next;
}

int size(Role* r) {  //返回选手的r角色数
    Role* l = r;
    int cnt = 0;
    while (l != NULL) {
        l = l->next;
        cnt++;
    }
    return cnt;
}

void output(Role* r) {  //输出选手r的每个随从的生命值
    Role* l = r->next;
    while (l != NULL) {
        printf("%d ", l->health);
        l = l->next;
    }
}

int main() {
    //插入英雄
    A = B = NULL;
    insert(A, 0, 0, 30);
    insert(B, 0, 0, 30);

    bool first = true;  //先手标志
    scanf("%d", &n);
    while (n--) {
        scanf("%s", op);
        if (op[0] == 'e')
            first = !first;
        else if (op[0] == 's') {
            scanf("%d%d%d", &position, &attack, &health);
            insert(first ? A : B, position, attack, health);
        } else if (op[0] == 'a') {
            scanf("%d%d", &attacker, &defender);
            first ? update(attacker, defender) : update(defender, attacker);
        }
    }
    if (A->health > 0 && B->health > 0)
        printf("0\n");
    else if (A->health > 0)
        printf("1\n");
    else
        printf("-1\n");

    printf("%d\n", A->health);
    printf("%d ", size(A) - 1);
    output(A);
    printf("\n");

    printf("%d\n", B->health);
    printf("%d ", size(B) - 1);
    output(B);
    printf("\n");

    return 0;
}