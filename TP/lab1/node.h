#pragma once
struct node
{
	int value; //�������� �������� �������
	node* prev; // ��������� �� ���������� �������
	node(int v) {	//����������� ����. �������
		value = v;
		prev = nullptr;
	};
};

