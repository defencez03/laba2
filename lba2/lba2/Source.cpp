// Выполнили студенты группы 21ВВ3: Тюкалов В.Е. и Чинов Д.Д.
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setlocale(LC_ALL, "rus");

	int i = 0, j = 0, r = 0, elem_c = 0, N = 0;

	printf("Введите размер матрицы: ");
	scanf_s("%d", &N);

	int** a = (int**)malloc(sizeof(int*) * N);
	int** b = (int**)malloc(sizeof(int*) * N);
	int** c = (int**)malloc(sizeof(int*) * N);

	for (int k = 0; k < N; k++) {
		a[k] = (int*)malloc(sizeof(int) * N);
		b[k] = (int*)malloc(sizeof(int) * N);
		c[k] = (int*)malloc(sizeof(int) * N);
	}

	time_t start = clock();

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < N)
	{
		while (j < N)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
		j = 0;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < N)
	{
		while (j < N)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
		j = 0;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (r = 0; r < N; r++)
			{
				elem_c = elem_c + c[i][r] * c[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	time_t end = clock();
	float res = end - start;
	printf("Время работы алгоритма: %f c", res / CLOCKS_PER_SEC);
	
	for (int k = N-1; k > 0; k--) {
		free(a[k]);
		free(b[k]);
		free(c[k]);
	}
	free(a);
	free(b);
	free(c);

	return(0);
}
