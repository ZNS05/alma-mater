/*   Product: Наименование, Производитель, Цена, Срок хранения, Количество. Создать массив объектов. Вывести: 
        а) список товаров для заданного наименования; 
        б) список товаров для заданного наименования, цена которых не превышает указанной; 
        в) список товаров, срок хранения которых больше заданного. 
        Разработать классы для описанных ниже объектов. Включить в класс методы set (?), get (?), show (?). Определить другие необходимые методы.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#define N 9

using namespace std; 

class Product
{
private:
    string name;           
    string producer;
    int price;
    int day;
    int amount;
public:
    void SetName(string valueName)   
    {
        name = valueName;
    }

    void SetProducer(string valueProducer) 
    {
        producer = valueProducer;
    }

    void SetPrice(int valuePrice) 
    {
        price = valuePrice;
    }

    void SetDay(int valueDay) 
    {
        day = valueDay;
    }

    void SetAmount(int valueAmount) 
    {
        amount = valueAmount;
    }

    string GetName() 
    {
        return name;
    }

    string GetProducer()
    {
        return producer;
    }

    int GetPrice()
    {
        return price;
    }

    int GetDay()
    {
        return day;
    }

    int GetAmount()
    {
        return amount;
    }

    void ShowName()
    {
        cout << name << endl;
    }

    void ShowProducer()
    {
        cout << producer << endl;
    }

    void ShowPrice()
    {
        cout << price << endl;
    }

    void ShowDay()
    {
        cout << day << endl;
    }

    void ShowAmount()
    {
        cout << amount << endl;
    }

};

int main()
{
    Product array[N];

    array[0].SetName("Молоко");
    array[0].SetProducer("Простоквашено");
    array[0].SetPrice(76);
    array[0].SetDay(5);
    array[0].SetAmount(90);

    array[1].SetName("Творог");
    array[1].SetProducer("Простоквашено");
    array[1].SetPrice(121);
    array[1].SetDay(5);
    array[1].SetAmount(71);

    array[2].SetName("Пряники");
    array[2].SetProducer("Яшкино");
    array[2].SetPrice(300);
    array[2].SetDay(7);
    array[2].SetAmount(147);

    array[3].SetName("Яйца");
    array[3].SetProducer("Селяночка");
    array[3].SetPrice(72);
    array[3].SetDay(30);
    array[3].SetAmount(88);

    array[4].SetName("Варенье 'Вишневое'");
    array[4].SetProducer("Варенька");
    array[4].SetPrice(66);
    array[4].SetDay(9);
    array[4].SetAmount(170);

    array[5].SetName("Варенье 'Малиновое'");
    array[5].SetProducer("Варенька");
    array[5].SetPrice(66);
    array[5].SetDay(9);
    array[5].SetAmount(167);

    array[6].SetName("Вафли");
    array[6].SetProducer("Красный-Октябрь");
    array[6].SetPrice(75);
    array[6].SetDay(1825);
    array[6].SetAmount(427);

    array[7].SetName("Кола");
    array[7].SetProducer("Добрый");
    array[7].SetPrice(82);
    array[7].SetDay(180);
    array[7].SetAmount(500);

    array[8].SetName("шоколад Алёнка");
    array[8].SetProducer("Красный-Октябрь");
    array[8].SetPrice(76);
    array[8].SetDay(365);
    array[8].SetAmount(291);
    
    int a;
    // system("chcp 1251");
    printf("Выберите способ вывода продуктов:\n"
            "1 - список товаров для заданного наименования;\n"
            "2 - список товаров для заданного производителя, цена которых не превышает указанной;\n"
            "3 - список товаров, срок хранения которых больше заданного;\n");
    scanf_s("%d", &a);

    if (a == 1)
    {
        printf("Введите наимнование производителя: ");
        string producer;
        cin >> producer;

        for (int i = 0; i < N; i++) 
        {
            if (producer == array[i].GetProducer())
            {
                printf("Ваш товар: ");
                // cout << array[i].GetName();
                array[i].ShowName();
            }   
        }    
    } 

    if (a == 2)
    {
        printf("Введите наименование производителя: ");
        string producer;
        cin >> producer;
        printf("Введите потолок цен: ");
        int price;
        cin >> price;

        for (int i = 0; i < N; i++) 
        {
            if ((producer == array[i].GetProducer()) && (price >= array[i].GetPrice()))
            {
                printf("Ваш товар: ");
                // cout << array[i].GetName();
                array[i].ShowName();
            }
        }
    }

    if (a == 3)
    {
        printf("Введите минимало нужный срок хранения товара (в днях): ");
        int day;
        cin >> day;

        for (int i = 0; i < N; i++) 
        {
            if (day <= array[i].GetDay())
            {
                printf("Ваш товар: ");
                // cout << array[i].GetName();
                array[i].ShowName();

            } 
        }
    }
return 0;
}
