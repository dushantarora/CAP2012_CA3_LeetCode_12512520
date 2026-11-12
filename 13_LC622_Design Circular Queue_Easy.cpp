#include <vector>

class MyCircularQueue {
private:
    std::vector<int> data;
    int capacity;
    int head;
    int count;

public:
    MyCircularQueue(int k) : data(k), capacity(k), head(0), count(0) {}

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        int tail = (head + count) % capacity;
        data[tail] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        int tail = (head + count - 1) % capacity;
        return data[tail];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
