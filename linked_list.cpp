#include "linked_list.h"
#include <iostream>

// LinkedList 클래스의 멤버 함수 구현

LinkedList::LinkedList() : head_(nullptr), size_(0) {}

LinkedList::~LinkedList() {
    Node* cur = head_;
    while (cur != nullptr) {
        Node* next = cur->next_;
        delete cur;
        cur = next;
    }
}

void LinkedList::print() {
    Node* cur = head_;
    while (cur != nullptr) {
        std::cout << cur->value_ << " ";
        cur = cur->next_;
    }
    std::cout << std::endl;
}

void LinkedList::insert(int index, int value) {
    if (index < 0 || index > size_) {
        std::cerr << "Invalid index\n";
        return;
    }

    Node* newNode = new Node(value);
    if (index == 0) {
        newNode->next_ = head_;
        head_ = newNode;
    }
    else {
        Node* cur = head_;
        for (int i = 0; i < index - 1; ++i) {
            cur = cur->next_;
        }
        newNode->next_ = cur->next_;
        cur->next_ = newNode;
    }
    ++size_;
}

int LinkedList::get(int index) {
    if (index < 0 || index >= size_) {
        std::cerr << "Invalid index\n";
        return -1;
    }

    Node* cur = head_;
    for (int i = 0; i < index; ++i) {
        cur = cur->next_;
    }

    return cur->value_;
}

void LinkedList::remove(int index) {
    if (index < 0 || index >= size_) {
        std::cerr << "Invalid index\n";
        return;
    }

    Node* deleteNode;
    if (index == 0) {
        deleteNode = head_;
        head_ = head_->next_;
    }
    else {
        Node* cur = head_;
        for (int i = 0; i < index - 1; ++i) {
            cur = cur->next_;
        }
        deleteNode = cur->next_;
        cur->next_ = deleteNode->next_;
    }
    delete deleteNode;
    --size_;
}