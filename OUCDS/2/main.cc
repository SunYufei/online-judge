#include <stdio.h>
#include "stack.h"

const int M = 10, N = 10;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

char maze[M][N + 1] = {"1111111111", "1001000101", "1001000101", "1000011001",
                       "1011100001", "1000100001", "1010001001", "1011101101",
                       "1100000001", "1111111111"};

bool mark[M][N] = {false};

bool Pass(PosType pos) {
    int x = pos.x;
    int y = pos.y;
    return x >= 0 && x < 10 && y >= 0 && y < 10 && maze[x][y] == '0' &&
           mark[x][y] == false;
}

PosType NextPos(PosType cur, int step) {}

bool MazePath(Stack s, PosType start, PosType end) {
    PosType curpos = start;
    int curstep = 1;
    do {
        if (Pass(curpos)) {
            mark[curpos.x][curpos.y] = true;
            ElemType e = {curstep, curpos, 1};
            Push(s, e);
            if (curpos.x == end.x && curpos.y == end.y)
                return true;
            curpos = NextPos(curpos, 1);
            curstep++;
        } else {
            if (StackEmpty(s) == false) {
                ElemType e;
                Pop(s, &e);
                while (e.dir == 4 && StackEmpty(s) == false) {
                    mark[curpos.x][curpos.y] = true;
                    Pop(s, &e);
                }
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
    if (StackEmpty(s))
        return;
    PrintPath(s->next->next);
    printf("->");
    ElemType data = s->next->data;
    printf("(%d, %d)", data.seat.x, data.seat.y);
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