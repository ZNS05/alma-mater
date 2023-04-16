#include "Queue.h"

Queue::Queue()
{
	head = nullptr;
}
/*�������� �������� �� ���������*/
bool Queue::rem(node*& nTDel)
{ //������ �� ���������, ����� ����� ���� 
	//��������, ��� � ���������� � ��� ���� �������� ����. ���������
	node* viewPtr(head); //��������� ��� ��������� �������
	node* oldHead(nullptr);
	if (!head || !nTDel) //������� ����� ��� �������� ������ ���������
		return false;
	/*������� ������*/
	if (nTDel == head)
	{
		oldHead = nTDel;
		head = head->prev;
		delete nTDel;
		nTDel = nullptr; //����� ����� �������� �� ������
		return true;
	}
	else
	{
		while (viewPtr->prev != nTDel) //���� ����. ����. �� ���������
			viewPtr = viewPtr->prev;
		viewPtr->prev = nTDel->prev; //���������� �� �������
		delete nTDel;	//�������
		nTDel = nullptr;
	}
}

void Queue::pop()
{
	node* tmp = head;
	head = head->prev;
	delete tmp;
}
/*���������� ��������*/
void Queue::add(int v)
{
	node* newElem(nullptr);
	node* viewPtr(head);//��������� ��������� ��� �������� �������
	/*��������� ������ �������*/
	if (!head)
		head = new node(v);
	/*��������� �� ������ �������*/
	else
	{
		while (viewPtr->prev) //������� ��������� �������
			viewPtr = viewPtr->prev;
		newElem = new node(v); //������ ����� �������
		viewPtr->prev = newElem; //������������ � ������
	}
}
/*�������� �� ������*/
bool Queue::remByPos(int posTDel)
{
	int curPos(0);
	node* viewPtr(head); //��������� ��� ��������� �������
	if (!head || posTDel < 0) //������� ����� ��� ����.���.����������.
		return false;

	while (viewPtr->prev && curPos != posTDel) //������� ���������
		//��� ���������� �������.
	{ //////������, ���� ����� �� �����
		viewPtr = viewPtr->prev;
		curPos++;
	}
	if (curPos != posTDel) //������� �� ������
		return false;
	if (rem(viewPtr))
		return true; //���������
	return false; //�� ������ ���������� ��������, ��� ��������
}
/*����������� �������*/
Queue* Queue::copy()
{
	Queue* newQueue(nullptr);
	node* viewPtr(head); //��������� ��������� ��� ��������� �������
	int tmpValue(0);
	if (!head) //������� �����
		return new Queue; //������� ��������� ������� � ������ ��������
	newQueue = new Queue;
	while (viewPtr)
	{
		tmpValue = viewPtr->value;
		newQueue->add(tmpValue);
        viewPtr = viewPtr->prev;
	}
	return newQueue;
}
/*������� ���� ��������*/
Queue* Queue::merge(Queue* q1, Queue* q2)
{//������� ���� �������� ������ �������, ����� ������
	Queue* newQueue(nullptr);
	node* viewPtr(nullptr);
	if (!q1 || !q2) //���� ���� �� ���� �� �������� �� ���������
					//������ �� ������
		return nullptr;
	newQueue = q1->copy();
	viewPtr = q2->get_head(); //���� �������� ������ ������ �������
								//��� � ��������
	while (viewPtr)//�������� ������ �������,
					//���� ������ �������� ��� �������
	{
		newQueue->add(viewPtr->value);
		viewPtr = viewPtr->prev;
	}
	return newQueue;
}
/*����� ��������� �� �����*/
void Queue::print()
{
	node* viewPtr(head);
	cout << '{';
	while (viewPtr)
	{
		cout << viewPtr->value;
		if (viewPtr->prev)
			cout << "<-";
        viewPtr = viewPtr->prev;    
	}
	cout << '}';
    cout << std::endl << std::endl;
}