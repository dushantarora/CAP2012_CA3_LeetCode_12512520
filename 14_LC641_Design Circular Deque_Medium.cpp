#include <vector>

class MyCircularDeque {
private:
    std::vector<int> data;
    int capacity;
    int head;
    int count;

public:
    MyCircularDeque(int k) : data(k), capacity(k), head(0), count(0) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + capacity) % capacity;
        data[head] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        int tail = (head + count) % capacity;
        data[tail] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return data[head];
    }

    int getRear() {
        if (isEmpty()) return -1;
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
