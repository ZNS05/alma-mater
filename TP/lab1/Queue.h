#pragma once
#include <iostream>
#include "node.h"
using std::cout;

class Queue
{
	node* head; //Первый элемент очереди
	bool rem(node*&); //удаление элемента по указателю

public:
	Queue();
	node* get_head() { return head; };
	void pop();
	void add(int v);
	bool remByPos(int position); //удаление по номеру в очереди
	Queue* copy(); //копирует себя
	Queue* merge(Queue* q1, Queue* q2); //q1 потом q2
	void print(); //выводит очередь на экраны
};