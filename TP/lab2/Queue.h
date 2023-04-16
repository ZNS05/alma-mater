#pragma once

class Queue
{
private:
    int *array; // очередь
    int rear = -1; // конец очереди
    int front = -1; // начало очерди
public:
    Queue();
    ~Queue();
    void Print();
    Queue& operator++();
    Queue operator++(int);
};
