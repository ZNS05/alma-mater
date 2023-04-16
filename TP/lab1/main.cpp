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
        std::cout << "1. Добавление элемента очереди." << std::endl;
        std::cout << "2. Удаление элемента очереди." << std::endl;
        std::cout << "3. Вывод очереди на экран." << std::endl;
        std::cout << "4. Нахождение последнего элемента, меньшего среднего арифметического." << std::endl;
        std::cout << "5. Создание копии очереди." << std::endl;
        std::cout << "6. Слияние оригинальной очереди с копией и вывод результата на экран." << std::endl;
        std::cout << "7. Выход из программы." << std::endl;

        int number;
        std::cin >> number;
        

        switch (number) 
        {
            case 1:
                //cout << "\033[2J\033[1;1H";
                cout << "Введите значение элемента: "; 
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
                cout << "Последний элемент, который меньше среднего арифметического: ";
                cout << q1.findNumber() << std::endl;
                break;
            case 5:
                //cout << "\033[2J\033[1;1H";
                q_copy = q.copy();
                cout << "Копия очереди успешно создана." << std::endl;
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
