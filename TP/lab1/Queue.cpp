#include "Queue.h"

Queue::Queue()
{
	head = nullptr;
}
/*удаление элемента по указателю*/
bool Queue::rem(node*& nTDel)
{ //ссылка на указатель, чтобы можно было 
	//работать, как с указателем и при этом изменять знач. указателя
	node* viewPtr(head); //указатель для просмотра очереди
	node* oldHead(nullptr);
	if (!head || !nTDel) //очередь пуста или передали пустой указатель
		return false;
	/*Удаляем голову*/
	if (nTDel == head)
	{
		oldHead = nTDel;
		head = head->prev;
		delete nTDel;
		nTDel = nullptr; //чтобы метка удаления не висела
		return true;
	}
	else
	{
		while (viewPtr->prev != nTDel) //ищем элем. след. за удаляемым
			viewPtr = viewPtr->prev;
		viewPtr->prev = nTDel->prev; //выкидываем из очереди
		delete nTDel;	//удаляем
		nTDel = nullptr;
	}
}

void Queue::pop()
{
	node* tmp = head;
	head = head->prev;
	delete tmp;
}
/*Добавление элементе*/
void Queue::add(int v)
{
	node* newElem(nullptr);
	node* viewPtr(head);//Временный указатель для перебора очереди
	/*добавляем первый элемент*/
	if (!head)
		head = new node(v);
	/*добавляем НЕ первый элемент*/
	else
	{
		while (viewPtr->prev) //находим последний элемент
			viewPtr = viewPtr->prev;
		newElem = new node(v); //создаём новый элемент
		viewPtr->prev = newElem; //присоединяем к хвосту
	}
}
/*Удаление по номеру*/
bool Queue::remByPos(int posTDel)
{
	int curPos(0);
	node* viewPtr(head); //указатель для просмотра очереди
	if (!head || posTDel < 0) //очередь пуста или введ.поз.некорректн.
		return false;

	while (viewPtr->prev && curPos != posTDel) //находим последний
		//или подходящий элемент.
	{ //////выйдет, если дойдёт до конца
		viewPtr = viewPtr->prev;
		curPos++;
	}
	if (curPos != posTDel) //Элемент не найден
		return false;
	if (rem(viewPtr))
		return true; //удалилось
	return false; //не прошла внутренняя проверка, при удалении
}
/*Копирование очереди*/
Queue* Queue::copy()
{
	Queue* newQueue(nullptr);
	node* viewPtr(head); //временный указатель для просмотра очереди
	int tmpValue(0);
	if (!head) //очередь пуста
		return new Queue; //вернуть экземпляр очереди с пустой очередью
	newQueue = new Queue;
	while (viewPtr)
	{
		tmpValue = viewPtr->value;
		newQueue->add(tmpValue);
        viewPtr = viewPtr->prev;
	}
	return newQueue;
}
/*слияние двух очередей*/
Queue* Queue::merge(Queue* q1, Queue* q2)
{//Сначала идут элементы первой очереди, затем второй
	Queue* newQueue(nullptr);
	node* viewPtr(nullptr);
	if (!q1 || !q2) //если хотя бы одна из очередей не суествует
					//ничего не мёрджим
		return nullptr;
	newQueue = q1->copy();
	viewPtr = q2->get_head(); //берём значение головы второй очереди
								//для её перебора
	while (viewPtr)//проходим вторую очередь,
					//беря оттуда значения для вставки
	{
		newQueue->add(viewPtr->value);
		viewPtr = viewPtr->prev;
	}
	return newQueue;
}
/*Вывод элементов на экран*/
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