//Алоритмы: Очередь и Стек
#include<iostream>
#include<string>

struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
	struct node* prev; // ссылка на предыдущий элемент 
};

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	std::cin >> s;
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy_s(p->inf, s);

	p->next = NULL;
	p->prev = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

void push(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
	{
		last->next = p;
		p->prev = last;
		last = p;
	}
	return;
}

void pop_stack(void)
{
	struct node* sw = NULL;
	sw = last;
	last = last->prev;
	last->next = NULL;
	free(sw);
}

void pop_queue(void)
{
	struct node* sw = NULL;
	sw = head;
	head = head->next;
	head->prev = NULL;
	free(sw);
}

/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s, \n", struc->inf);
		struc = struc->next;
	}
	printf("\n");

}

int main(void) 
{
	setlocale(LC_ALL, "rus");

	push();
	push();
	push();
	review();
	pop_queue();
	review();
	push();
	review();
	pop_stack();
	review();
}