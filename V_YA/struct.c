
//Создать массив Игроков (ФИО, число забитых мячей). По фамилии изменить число. Вывести на экран.
#include <stdio.h>
#include <stdlib.h>

typedef struct player
{
    char * name;         //Создаём структуру
    int points;
} player;

int main(void)
{
    player players[4];

    players[0].name = "Korzhov Georgy Sergeevich";
    players[0].points = 1;

    players[1].name = "Zaitsev Nikita Sergeevich";
    players[1].points = 3;

    players[2].name = "Raysailov Roman Dmitrievich";
    players[2].points = 2;
    
    players[3].name = "Skakun Danil Dmitrievich";
    players[3].points = 2;

    printf("Enter your last name: ");
    char* surname = (char*) malloc (100 * sizeof(char));    //Запрашиваем Фамилию
    gets(surname);                                      
    printf("Enter the number of points: ");
    int point;                                              //Запрашиваем количество очков
    scanf("%d", &point);

    for (int i = 0; i < 4; ++i)
    {
        int flag = 1;
        char * pointer = players[i].name;  // Запоминаем Заведомо известную фамилию в pointer
        char * buffer = pointer;           // Засовываем значение pointer в buffer
        char * bufferS = surname;          // Засовываем значение surname в bufferS
        int counter = 0;

        while (*pointer != ' ')   //Двигаемся по строке до первого пробела
        {
            if (((*pointer >= 'a') && (*pointer <= 'z')) || ((*pointer >= 'A') && (*pointer <= 'Z')))
            {
                counter++;
            }
            pointer++;
        }

        for (int j = 0; j < counter; ++j)
        {
            if (*buffer != *bufferS) //Сверяем, совпадает ли фамилия с введённой фамилией с клавиатуры 
            {
                flag = 0;            //Если совпадений нет, то выходим
                break;
            }
            buffer++;                
            bufferS++;               
        }

        if (flag == 1)                   //Если совпадение найдено
        {
            players[i].points += point;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        printf("Player: %s\n", players[i].name);  //Выводим ФИО участников
        printf("Points: %d\n", players[i].points);      //Выводим конечное количество очков
    }
}