#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int columnMin(int row, int column, int** array);

int main(void)
{
    srand(time(NULL));

    int row;
    printf("Row: ");
    scanf("%d", &row);

    int column;
    printf("Column: ");
    scanf("%d", &column);

    int** array = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) 
	{
		array[i] = (int*)malloc(column * sizeof(int)); 
		for (int j = 0; j < column; j++)
		{
			array[i][j] = rand() % 100;
		}
	}
    
    int sum = columnMin(row, column, array);

    FILE* file = fopen("answer.txt", "a");
	fprintf(file, "Результат работы програмы:\n");
    fprintf(file, "Исходный массив\n");
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < column; j++)
		{
			fprintf(file, "%d ", array[i][j]);
		}
		fprintf(file, "\n");
	}
	fprintf(file, "Минимальная сумма в столбце: %d\n\n", sum);

    fprintf(file, "Добрый день \n");
	fclose(file);

	return 0;
}

int columnMin(int row, int column, int** array)
{
    int sum = 0;
    int min = 32767;
    for (int j = 0; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            sum += array[i][j];
        }
        if (sum < min)
        {
            min = sum;
        }
        sum = 0;
    }
    return min;
}

