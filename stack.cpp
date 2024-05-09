#include "stack.h"
#include <iostream>

// TODO: Stack 클래스 구현 작성
void Stack::push(int data) {
    insert(0, data);
}

int Stack::pop() {
    if (size_ == 0) { 
        std::cerr << "Stack is empty!" << std::endl;
        return -1;
    }

    int data = get(0);
    remove(0);
    return data;
}

int Stack::peek() {
    if (size_ == 0) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1;
    }

    return get(0);
}

Stack& Stack::operator+=(int data) {
    push(data);
    return *this;
}