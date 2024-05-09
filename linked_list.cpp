#include "linked_list.h"
#include <iostream>

// TODO: LinkedList 클래스 구현 작성

LinkedList::LinkedList() : head_(nullptr), size_(0) {}

LinkedList::~LinkedList() {
    Node* cur = head_;
    while (cur != nullptr) {
        Node* next = cur -> getNext();
        delete cur;
        cur = next;
    }
}

void LinkedList::print() {
    Node* cur = head_;
    while (cur != nullptr) {
        std::cout << cur -> getVal() << " ";
        cur = cur -> getNext();
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
        newNode -> setNext(head_);
        head_ = newNode;
    }
    else {
        Node* cur = head_;
        for (int i = 0; i < index - 1; ++i) {
            cur = cur->getNext();
        }
        newNode->setNext(cur->getNext());
        cur->setNext(newNode);
    }
    ++size_;
}

int LinkedList::get(int index) {
    if (index < 0 || index >= size_) {
        std::cerr << "Invalid\n";
        return -1;
    }

    Node* cur = head_;
    for (int i = 0; i < index; ++i) {
        cur = cur -> getNext();
    }

    return cur -> getVal();
}

void LinkedList::remove(int index) {
    if (index < 0 || index >= size_) {
        std::cerr << "Invalid index\n";
        return;
    }

    Node* delete_;
    if (index == 0) {
        delete_ = head_;
        head_ = head_->getNext();
    }
    else {
        Node* cur = head_;
        for (int i = 0; i < index - 1; ++i) {
            cur = cur -> getNext();
        }
        delete_ = cur -> getNext();
        cur -> setNext(delete_ -> getNext());
    }
    delete delete_;
    --size_;
}

