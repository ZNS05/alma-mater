#pragma once
struct node
{
	int value; //значение элемента очереди
	node* prev; // указатель на предыдущий элемент
	node(int v) {	//конструктор элем. очереди
		value = v;
		prev = nullptr;
	};
};

