// Выполнили студенты группы 21ВВ3: Тюкалов В.Е. и Чинов Д.Д.
// Приоритетная очередь
#include<iostream>


struct node
{
	int pri;
	char inf[256];  // полезная информация
	struct node* next = NULL; // ссылка на следующий элемент 
};

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;
char find_el[256];
int prioritet = 0;
struct node* priority(node* el);

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	puts("Введите название объекта: ");   // вводим данные
	std::cin >> s;
	puts("Введите приоритет: ");   
	std::cin >> p->pri;
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy_s(p->inf, s);

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
void push(void)
{
	struct node* p = NULL;
	p = get_struct();
	priority(p);
}

void pop(void)
{
	struct node* sw = NULL;
	sw = head;
	head = head->next;
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

struct node* priority(node* el)
{
	struct node* sw = NULL;
	if (head == NULL)
	{
		head = el;
		last = el;
		return NULL;
	}
	if (head->pri > el->pri)
	{
		el->next = head;
		head = el;
		return NULL;
	}
	struct node* struc = head;
	while (struc)
	{
		if (el->pri < struc->pri)
		{
			el->next = struc;
			sw->next = el;
			break;
		}
		sw = struc;
		struc = struc->next;
	}
	return NULL;
}

int main() 
{
	setlocale(LC_ALL, "RUS");

	int var = 0;

	printf("Кол-во данных: ");
	std::cin >> var;
	for (int i = 0; i < var; i++) {
		push();
	}
	review();
	pop();
	review();
	return 0;
}
