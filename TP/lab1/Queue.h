#pragma once
#include <iostream>
#include "node.h"
using std::cout;

class Queue
{
	node* head; //������ ������� �������
	bool rem(node*&); //�������� �������� �� ���������

public:
	Queue();
	node* get_head() { return head; };
	void pop();
	void add(int v);
	bool remByPos(int position); //�������� �� ������ � �������
	Queue* copy(); //�������� ����
	Queue* merge(Queue* q1, Queue* q2); //q1 ����� q2
	void print(); //������� ������� �� ������
};