#include "Queue.h"
#include "Queue1.h"
#include <iostream>

int main (int argc, char *argv[])
{
    int end = 0;
    Queue q;
    Queue* q_copy;
    Queue* q_merge;
    Queue1 q1;
    while (end == 0) {
        std::cout << "1. ���������� ����� ��।�." << std::endl;
        std::cout << "2. �������� ����� ��।�." << std::endl;
        std::cout << "3. �뢮� ��।� �� �࠭." << std::endl;
        std::cout << "4. ��宦����� ��᫥����� �����, ����襣� �।���� ��䬥��᪮��." << std::endl;
        std::cout << "5. �������� ����� ��।�." << std::endl;
        std::cout << "6. ���ﭨ� �ਣ����쭮� ��।� � ������ � �뢮� १���� �� �࠭." << std::endl;
        std::cout << "7. ��室 �� �ணࠬ��." << std::endl;

        int number;
        std::cin >> number;
        

        switch (number) 
        {
            case 1:
                //cout << "\033[2J\033[1;1H";
                cout << "������ ���祭�� �����: "; 
                int x;
                std::cin >> x;
                q.add(x);
                break;
            case 2:
                cout << "\033[2J\033[1;1H";
                q.pop();
                cout << "\033[2J\033[1;1H";
                break;
            case 3:
                //cout << "\033[2J\033[1;1H";
                q.print();
                break;
            case 4:
                cout << "\033[2J\033[1;1H";
                cout << "��᫥���� �����, ����� ����� �।���� ��䬥��᪮��: ";
                cout << q1.findNumber() << std::endl;
                break;
            case 5:
                //cout << "\033[2J\033[1;1H";
                q_copy = q.copy();
                cout << "����� ��।� �ᯥ譮 ᮧ����." << std::endl;
                break;
            case 6:
                //cout << "\033[2J\033[1;1H";
                q_merge = q.merge(&q, q_copy);
                q_merge->print();
                break;
            case 7:
                end = 1;
                break;
            default:
                return 0;
        }
    }
    
    return 0;
} 
