#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

void shell(int* items, int count)
{
    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void shell_minus(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x > items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;

    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int compare(const int* a, const int* b) {
	return *a - *b;
}


int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	clock_t start, end;
	int count;
	float res_qs[4], res_shell[4], res_qsort[4];

	printf("Введите размерность массива: ");
	scanf_s("%d", &count);

	int* items = (int*)malloc(count * sizeof(items));
	for (int i = 0; i < count; i++)
	{
		items[i] = rand() % 100;
	}

	//Пункт 1
	start = clock();
	shell(items, count);
	end = clock();
	res_shell[0] = (end - start);
	start = clock();
	qs(items, 0, count - 1);
	end = clock();
	res_qs[0] = (end - start);

	//Пункт 2
	qs(items, 0, count - 1);
	start = clock();
	shell(items, count);
	end = clock();
	res_shell[1] = (end - start);
	start = clock();
	qs(items, 0, count - 1);
	end = clock();
	res_qs[1] = (end - start);

	//Пункт 3
	shell_minus(items, count);
	start = clock();
	shell(items, count);
	end = clock();
	res_shell[2] = (end - start);
	start = clock();
	qs(items, 0, count - 1);
	end = clock();
	res_qs[2] = (end - start);

	//Пункт 4
	qs(items, count / 2, count - 1);
	shell_minus(items, count / 2);
	start = clock();
	shell(items, count);
	end = clock();
	res_shell[3] = (end - start);
	start = clock();
	qs(items, 0, count - 1);
	end = clock();
	res_qs[3] = (end - start);

	//Пункт 5
	start = clock();
	qsort(items, count, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	res_qsort[0] = end - start;

	shell(items, count);
	start = clock();
	qsort(items, count, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	res_qsort[1] = end - start;

	shell_minus(items, count);
	start = clock();
	qsort(items, count, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	res_qsort[2] = end - start;

	qs(items, count / 2, count - 1);
	shell_minus(items, count / 2);
	start = clock();
	qsort(items, count, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	res_qsort[3] = end - start;

	printf(" \n        |rand       |up         |down       |up-down\n");
	printf(" ----------------------------------------------------\n");
	printf(" shell  |%5f   |%5f   |%5f   |%5f\n", res_shell[0] / 1000, res_shell[1] / 1000, res_shell[2] / 1000, res_shell[3] / 1000);
	printf(" qs     |%5f   |%5f   |%5f   |%5f\n", res_qs[0] / 1000, res_qs[1] / 1000, res_qs[2] / 1000, res_qs[3] / 1000);
	printf(" qsort  |%5f   |%5f   |%5f   |%5f\n", res_qsort[0] / 1000, res_qsort[1] / 1000, res_qsort[2] / 1000, res_qsort[3] / 1000);

	return 0;
}