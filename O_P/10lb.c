//�����஢��� ⥪�⮢� 䠩�, �����஢�� ��ப� �� ��䠢���.
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h> 
#include <malloc.h> 
#include <stdlib.h> 
#define MAXLINE 1024 
#define NLINES 3 
void sort();
int nlines1;
char** lines_ptr = NULL;//������ ���ᨢ 
int main(void)
{
    FILE* fpin;
    FILE* fpout;
    char line[MAXLINE];
    char* ptr;
    int npointers; //᪮�쪮 ����� ����� ��ப
    int len; // ����� ��ப� 
    int i;
    fpin = fopen("test.txt", "r");
    if (fpin == NULL)
        return;
    fpout = fopen("result.txt", "w");
    if (fpout == NULL)
        return;
    lines_ptr = (char**)calloc(NLINES, sizeof(char*)); //�뤥��� ������ ��� ������� ���ᨢ�
    npointers = NLINES;
    nlines1 = 0; // ������⢮ ��� ��ப�
    while (!feof(fpin))
    {
        ptr = fgets(line, MAXLINE, fpin);
        if (ptr == NULL)
            break;
        len = strlen(line);// ���� ����� ��ப�
        if (nlines1 == npointers) // �� ��砩 ��९������� �����
        {
            npointers += NLINES;
            lines_ptr = (char**)realloc(lines_ptr, npointers * sizeof(char*));// ���������� �����
            memset(&lines_ptr[nlines1], 0, NLINES * sizeof(char*));
        }
        lines_ptr[nlines1] = (char*)malloc(len + 1); //�뤥��� ������ ��� �����⭮� ��ப� ���ᨢ�
        strcpy(lines_ptr[nlines1], line);
        nlines1++;
    }
    sort();
    for (i = 0; i < nlines1; i++)
    {
        fputs(lines_ptr[i], fpout); // �뢮� ������ ��ப � ���ᨢ
    }
    for (i = 0; i < nlines1; i++)
    {
        if (lines_ptr[i] != NULL) // �᢮�������� ����� ��ப
            free(lines_ptr[i]);
    }
    if (lines_ptr != NULL)
    {
        free(lines_ptr); // �᢮�������� ����� ���ᨢ�
    }
    fclose(fpin);
    fclose(fpout);
    return 0;
}
void sort() // ��� ��⠢����
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
            char* line = (char*)malloc(len1 + 1); // �뤥����� ����� ��� ��� ���窨
            strcpy(line, lines_ptr[j + 1]); // ����஢���� ��ன ���窨 � ���
            lines_ptr[j + 1] = (char*)malloc(len + 1); // �뤥����� ����� ࠧ��஬ ��ࢮ� ��� ��� ��ன
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