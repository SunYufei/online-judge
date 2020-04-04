/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */
#include <vector>
using namespace std;

// @lc code=start
class MyCircularDeque {
  private:
    vector<int> q;
    int front;
    int rear;
    int size;
    int capacity;

  public:
    MyCircularDeque(int k) {
        q.resize(k);
        front = 0;
        rear = 0;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        else {
            front = (front + capacity - 1) % capacity;
            q[front] = value;
            ++size;
            return true;
        }
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        else {
            q[rear] = value;
            rear = (rear + 1) % capacity;
            ++size;
            return true;
        }
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        else {
            front = (front + 1) % capacity;
            --size;
            return true;
        }
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        else {
            rear = (rear - 1 + capacity) % capacity;
            --size;
            return true;
        }
    }

    int getFront() {
        if (isEmpty())
            return -1;
        else
            return q[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        else
            return q[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() { return rear == front && size == 0; }

    bool isFull() { return rear == front && size == capacity; }
};

// @lc code=end
