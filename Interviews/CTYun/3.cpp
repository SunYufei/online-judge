#include <bits/stdc++.h>
using namespace std;

class MinStack {
   public:
    MinStack() {}

    void push(int x) {}

    void pop() {}

    int top() {}

    int getMin() {}
};

int main() {
    MinStack stack;
    int n;
    scanf("%d", &n);
    string op;
    while (n--) {
        cin >> op;
        if (op == "push") {
            int x;
            scanf("%d", &x);
            stack.push(x);
        } else if (op == "pop") {
            stack.pop();
        } else if (op == "top") {
            printf("%d", stack.top());
        } else if (op == "getMin") {
            printf("%d", stack.getMin());
        }
    }
    return 0;
}