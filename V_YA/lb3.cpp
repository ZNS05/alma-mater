/*   Product: ������������, �ந�����⥫�, ����, �ப �࠭����, ������⢮. ������� ���ᨢ ��ꥪ⮢. �뢥��: 
        �) ᯨ᮪ ⮢�஢ ��� ��������� ������������; 
        �) ᯨ᮪ ⮢�஢ ��� ��������� ������������, 業� ������ �� �ॢ�蠥� 㪠������; 
        �) ᯨ᮪ ⮢�஢, �ப �࠭���� ������ ����� ���������. 
        ���ࠡ���� ������ ��� ���ᠭ��� ���� ��ꥪ⮢. ������� � ����� ��⮤� set (?), get (?), show (?). ��।����� ��㣨� ����室��� ��⮤�.
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

    array[0].SetName("������");
    array[0].SetProducer("���⮪��襭�");
    array[0].SetPrice(76);
    array[0].SetDay(5);
    array[0].SetAmount(90);

    array[1].SetName("���ண");
    array[1].SetProducer("���⮪��襭�");
    array[1].SetPrice(121);
    array[1].SetDay(5);
    array[1].SetAmount(71);

    array[2].SetName("��ﭨ��");
    array[2].SetProducer("�誨��");
    array[2].SetPrice(300);
    array[2].SetDay(7);
    array[2].SetAmount(147);

    array[3].SetName("���");
    array[3].SetProducer("���ﭮ窠");
    array[3].SetPrice(72);
    array[3].SetDay(30);
    array[3].SetAmount(88);

    array[4].SetName("��७� '��譥���'");
    array[4].SetProducer("��७쪠");
    array[4].SetPrice(66);
    array[4].SetDay(9);
    array[4].SetAmount(170);

    array[5].SetName("��७� '���������'");
    array[5].SetProducer("��७쪠");
    array[5].SetPrice(66);
    array[5].SetDay(9);
    array[5].SetAmount(167);

    array[6].SetName("��䫨");
    array[6].SetProducer("����-������");
    array[6].SetPrice(75);
    array[6].SetDay(1825);
    array[6].SetAmount(427);

    array[7].SetName("����");
    array[7].SetProducer("�����");
    array[7].SetPrice(82);
    array[7].SetDay(180);
    array[7].SetAmount(500);

    array[8].SetName("讪���� ��񭪠");
    array[8].SetProducer("����-������");
    array[8].SetPrice(76);
    array[8].SetDay(365);
    array[8].SetAmount(291);
    
    int a;
    // system("chcp 1251");
    printf("�롥�� ᯮᮡ �뢮�� �த�⮢:\n"
            "1 - ᯨ᮪ ⮢�஢ ��� ��������� ������������;\n"
            "2 - ᯨ᮪ ⮢�஢ ��� ��������� �ந�����⥫�, 業� ������ �� �ॢ�蠥� 㪠������;\n"
            "3 - ᯨ᮪ ⮢�஢, �ப �࠭���� ������ ����� ���������;\n");
    scanf_s("%d", &a);

    if (a == 1)
    {
        printf("������ ����������� �ந�����⥫�: ");
        string producer;
        cin >> producer;

        for (int i = 0; i < N; i++) 
        {
            if (producer == array[i].GetProducer())
            {
                printf("��� ⮢��: ");
                // cout << array[i].GetName();
                array[i].ShowName();
            }   
        }    
    } 

    if (a == 2)
    {
        printf("������ ������������ �ந�����⥫�: ");
        string producer;
        cin >> producer;
        printf("������ ��⮫�� 業: ");
        int price;
        cin >> price;

        for (int i = 0; i < N; i++) 
        {
            if ((producer == array[i].GetProducer()) && (price >= array[i].GetPrice()))
            {
                printf("��� ⮢��: ");
                // cout << array[i].GetName();
                array[i].ShowName();
            }
        }
    }

    if (a == 3)
    {
        printf("������ �������� �㦭� �ப �࠭���� ⮢�� (� ����): ");
        int day;
        cin >> day;

        for (int i = 0; i < N; i++) 
        {
            if (day <= array[i].GetDay())
            {
                printf("��� ⮢��: ");
                // cout << array[i].GetName();
                array[i].ShowName();

            } 
        }
    }
return 0;
}
