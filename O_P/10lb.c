//Скопировать текстовый файл, отсортировав строки по алфавиту.
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h> 
#include <malloc.h> 
#include <stdlib.h> 
#define MAXLINE 1024 
#define NLINES 3 
void sort();
int nlines1;
char** lines_ptr = NULL;//динами массив 
int main(void)
{
    FILE* fpin;
    FILE* fpout;
    char line[MAXLINE];
    char* ptr;
    int npointers; //сколько можно считать строк
    int len; // длина строки 
    int i;
    fpin = fopen("test.txt", "r");
    if (fpin == NULL)
        return;
    fpout = fopen("result.txt", "w");
    if (fpout == NULL)
        return;
    lines_ptr = (char**)calloc(NLINES, sizeof(char*)); //выделяю память для динамич массива
    npointers = NLINES;
    nlines1 = 0; // количество счит строки
    while (!feof(fpin))
    {
        ptr = fgets(line, MAXLINE, fpin);
        if (ptr == NULL)
            break;
        len = strlen(line);// поиск длины строки
        if (nlines1 == npointers) // на случай переполнения памяти
        {
            npointers += NLINES;
            lines_ptr = (char**)realloc(lines_ptr, npointers * sizeof(char*));// добавление памяти
            memset(&lines_ptr[nlines1], 0, NLINES * sizeof(char*));
        }
        lines_ptr[nlines1] = (char*)malloc(len + 1); //выделяю память для конкретной строки массива
        strcpy(lines_ptr[nlines1], line);
        nlines1++;
    }
    sort();
    for (i = 0; i < nlines1; i++)
    {
        fputs(lines_ptr[i], fpout); // вывод отсортир строк в массив
    }
    for (i = 0; i < nlines1; i++)
    {
        if (lines_ptr[i] != NULL) // освобождение памяти строк
            free(lines_ptr[i]);
    }
    if (lines_ptr != NULL)
    {
        free(lines_ptr); // освобождение памяти массива
    }
    fclose(fpin);
    fclose(fpout);
    return 0;
}
void sort() // сорт вставками
{
    int len;
    int len1;
    int j;
    for (int i = 0; i < nlines1 - 1; i++)
    {
        j = i;//?????? -1
        while ((j >= 0) && (lines_ptr[j][0] > lines_ptr[j + 1][0]))
        {
        a:
            len = strlen(lines_ptr[j]);
            len1 = strlen(lines_ptr[j + 1]);
            char* line = (char*)malloc(len1 + 1); // выделение памяти для буф строчки
            strcpy(line, lines_ptr[j + 1]); // копирование второй строчки в буф
            lines_ptr[j + 1] = (char*)malloc(len + 1); // выделение памяти размером первой стр для второй
            strcpy(lines_ptr[j + 1], lines_ptr[j]);
            lines_ptr[j] = (char*)malloc(len1 + 1);
            strcpy(lines_ptr[j], line);
            free(line);
        b:
            j--;
        }
        if ((j >= 0) && (lines_ptr[j][0] == lines_ptr[j + 1][0]))
        {
            len = strlen(lines_ptr[j]);
            len1 = strlen(lines_ptr[j + 1]);
            if (len > len1)
            {
                for (int g = 0; g < len1; g++)
                {
                    if (lines_ptr[j][g] > lines_ptr[j + 1][g])
                    {
                        goto a;
                    }
                    if (lines_ptr[j][g] < lines_ptr[j + 1][g])
                    {
                        goto b;
                    }
                }
            }
            else
            {
                for (int g = 0; g < len; g++)
                {
                    if (lines_ptr[j][g] < lines_ptr[j + 1][g])
                    {
                        goto b;
                    }
                    if (lines_ptr[j][g] > lines_ptr[j + 1][g])
                    {
                        goto a;
                    }

                }
            }
        }
    }
}