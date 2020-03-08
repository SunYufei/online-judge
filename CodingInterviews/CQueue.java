import java.util.Stack;

class CQueue {
    private Stack<Integer> mainStack;
    private Stack<Integer> tempStack;

    public CQueue() {
        mainStack = new Stack<>();
        tempStack = new Stack<>();
    }

    public void appendTail(int value) {
        mainStack.add(value);
    }

    public int deleteHead() {
        if (mainStack.empty())
            return -1;
        while (!mainStack.empty())
            tempStack.add(mainStack.pop());
        int res = tempStack.pop();
        while (!tempStack.empty())
            mainStack.add(tempStack.pop());
        return res;
    }
}