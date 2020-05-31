package LeetCode;

import java.util.Stack;

class CQueue {
    Stack<Integer> stack, temp;

    public CQueue() {
        stack = new Stack<>();
        temp = new Stack<>();
    }

    public void appendTail(int value) {
        stack.push(value);
    }

    public int deleteHead() {
        if (stack.empty())
            return -1;
        while (!stack.empty())
            temp.push(stack.pop());
        int t = temp.pop();
        while (!temp.empty())
            stack.push(temp.pop());
        return t;
    }
}