#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

// TODO: Queue 클래스 정의 작성
class Queue : public LinkedList {
    public:
        void push(int data);

        int pop();

        int peek();

        Queue& operator+=(int data);
};

#endif