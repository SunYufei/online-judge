#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_space() {
    static int flag = 0;
    if (flag++)
        putchar(' ');
}

int main() {
    char stack[50];
    int top = 0;

    char str[50];
    scanf("%s", str);
    int length = strlen(str);

    int i;
    for (i = 0; i < length; i++) {
        // 运算数，此处 + - 为正负
        if ((str[i] == '+' || str[i] == '-') && (!i || str[i - 1] == '(') ||
            isdigit(str[i])) {
            print_space();
            if (str[i] != '+')
                putchar(str[i]);
            while (str[i + 1] == '.' || isdigit(str[i + 1]))
                putchar(str[++i]);
        } else {
            // 运算符
            if (str[i] == ')') {
                // 右括号，将左括号前所有运算符弹出
                while (top && stack[top - 1] != '(') {
                    print_space();
                    putchar(stack[--top]);
                }
                // 栈不空，弹出左括号
                if (top)
                    --top;
            } else {
                // 其他运算符
                if (!top) {
                    // 栈为空，不比较，压栈
                    stack[top++] = str[i];
                    continue;
                }
                // 根据优先级顺序，压栈 或 弹栈后压栈
                while (top && stack[top - 1] != '(') {
                    // 比较优先级
                    if (str[i] == '(' ||
                        ((str[i] == '*' || str[i] == '/') &&
                         (stack[top - 1] == '-' || stack[top - 1] == '+')))
                        break;
                    print_space();
                    // 若 str[i] 优先级小于栈顶优先级，弹栈后压栈
                    putchar(stack[--top]);
                }
                stack[top++] = str[i];
            }
        }
    }

    // 运算数操作完毕，输出剩余运算符
    while (top) {
        print_space();
        // 左括号不输出
        if (stack[top - 1] != '(')
            putchar(stack[top - 1]);
        --top;
    }

    return 0;
}