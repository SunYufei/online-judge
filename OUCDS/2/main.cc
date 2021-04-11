#include "stack.hpp"
#include <stdio.h>

#define M 10
#define N 10
// 通行
#define PASS 0
// 不可通行
#define DENY -1

int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int maze[M + 2][N + 2] = {0};

bool Pass(PosType pos) { return maze[pos.x][pos.y] == PASS; }

void FootPrint(PosType pos) { maze[pos.x][pos.y] = 2; }

PosType NextPos(PosType cur, int step) {
    PosType res;
    res.x = cur.x + dirs[step][0];
    res.y = cur.y + dirs[step][1];
    return res;
}

bool MazePath(Stack s, PosType start, PosType end) {
    // 设置入口位置
    PosType curpos = start;
    // 当前步数
    int curstep = 1;
    do {
        // 当前位置可通
        if (Pass(curpos)) {
            // 留下足迹
            maze[curpos.x][curpos.y] = 2;
            ElemType e = {curstep, curpos, 1};
            Push(s, e);
            // 到达终点，退出
            if (curpos.x == end.x && curpos.y == end.y)
                return true;
            // 记录当前路径
            maze[curpos.x][curpos.y] = curstep;
            // 获取下一步位置
            curpos = NextPos(curpos, 1);
            // 探索下一步
            curstep++;
        } else {
            // 当前位置不能通过
            if (StackEmpty(s) == false) {
                // 取出栈顶元素
                ElemType e;
                Pop(s, &e);

                while (e.dir == 4 && StackEmpty(s) == false) {
                    curstep--;
                    // 标记当前位置不可走
                    maze[e.seat.x][e.seat.y] = DENY;
                    // 回退一步
                    Pop(s, &e);
                }
                // 其他方向没有探索
                if (e.dir < 4) {
                    e.dir++;
                    Push(s, e);
                    curpos = NextPos(e.seat, e.dir);
                }
            }
        }
    } while (StackEmpty(s) == false);
    return false;
}

void PrintPath(Stack s) {
    if (s == NULL)
        return;
    PrintPath(s->next);
    ElemType data = s->data;
    printf("(%d, %d) ", data.seat.x, data.seat.y);
}

int main() {
    PosType start, end;
    start.x = 1, start.y = 1;
    end.x = 8, end.y = 8;
    Stack s;
    InitStack(&s);
    if (MazePath(s, start, end))
        PrintPath(s);
    return 0;
}