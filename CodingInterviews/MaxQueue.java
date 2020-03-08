import java.util.List;
import java.util.ArrayList;

class MaxQueue {

    private List<Integer> queue;
    private int i, curr, max;

    public MaxQueue() {
        i = 0;
        curr = -1;
        queue = new ArrayList<>();
        max = -1;
    }

    public int max_value() {
        if (max == -1 || max >= queue.size())
            return -1;
        return queue.get(max);
    }

    public void push_back(int value) {
        ++curr;
        queue.add(value);
        if (max == -1)
            max = curr;
        if (queue.get(max) <= value)
            max = curr;
    }

    public int pop_front() {
        if (queue.isEmpty() || i >= queue.size())
            return -1;
        int first = queue.get(i);
        if (i == max) {
            int j = ++i;
            ++max;
            while (j < queue.size()) {
                max = queue.get(max) <= queue.get(j) ? j : max;
                ++j;
            }
        } else
            ++i;
        return first;
    }
}