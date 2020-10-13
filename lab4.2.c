#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/* Лабораторная работа №4.2
13. Дано пятизначное число. Определить число, полученное при перестановке в нем тысяч и сотен. 
*/

void sp() {
	printf("------------------------------------------------\n");
}

int main() {
	setlocale(LC_ALL, "Russian");
	int x, x1, x2, x3, x4, x5;

	sp();
	printf_s("Введите пятизначное число: "); scanf_s("%d", &x);
	sp();

	x1 = x / 10000;
	x2 = (x / 1000) % 10;
	x3 = (x / 100) % 10;
	x4 = (x / 10) % 10;
	x5 = x % 10;

	printf_s("Полученное число при перестановки тысяч и сотен: %d%d%d%d%d\n", x1, x3, x2, x4, x5);
	sp();
	return 0;
}