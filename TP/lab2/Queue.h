#pragma once

class Queue
{
private:
    int *array; // ��।�
    int rear = -1; // ����� ��।�
    int front = -1; // ��砫� ��न
public:
    Queue();
    ~Queue();
    void Print();
    Queue& operator++();
    Queue operator++(int);
};
