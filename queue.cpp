#include "queue.h"
#include <iostream>

// TODO: Queue 클래스 구현 작성
void Queue::push(int data) {
    insert(size_, data);
}

int Queue::pop() {
    if (size_ == 0) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }

    int data = get(0);
    remove(0);
    return data;
}

int Queue::peek() {
    if (size_ == 0) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }

    return get(0);
}

Queue& Queue::operator+=(int data) {
    push(data);
    return *this;
}