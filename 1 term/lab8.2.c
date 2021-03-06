#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/* Лабораторная работа 8.2.
13. Дано целое положительное число. Определить количество
четных цифр, стоящих на нечетной позиции.
_________________________________________________________
Взяв за основу свою программу, написанную для решения
Задачи 2 лабораторной работы №7, доработать её, организовав
проверку корректности введенного значения с помощью цикла
с постусловием.
*/

void sp() {
	printf("------------------------------------------------\n");
}

int main() {
	setlocale(LC_ALL, "Russian");

	int a = 0, b, digits = 0, x, y, count = 0;

	sp();
	
	do
	{
		printf_s("Введите целое положительное число: "); scanf_s("%d", &a);
		sp();
	} while (a < 1);
	
	b = a;

	while (b != 0)
	{
		x = b / 10;
		y = b % 10;

		b /= 10;
		digits++;

		if (digits % 2 != 0)
		{
			if (y % 2 == 0)
			{
				count++;
			}
		}

	}

	
	printf_s("Количество чётных цифр, стоящих на нечётных позициях: %d\n", count);
	sp();
	return 0;
}