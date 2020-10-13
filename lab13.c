#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

/* Лабораторная работа 13.
13. Определить, содержатся ли в массиве хотя бы два
отрицательных числа. Если да, прибавить сумму этих чисел ко всем
элементам массива. В противном случае оставить массив
неизменным.
*/

// Декоративная функция для вывода.
void sp() {
	printf("------------------------------------------------\n");
}

/* Функция вывода массива на экран.
На входе получает:
* arr - указатель на массив
* array_size - размерность массива
*/
void array_print(int* arr, int array_size) {
	sp();
	printf_s("Список элементов массива:\n");
	for (int i = 0; i < array_size; i++)
	{
		printf_s("arr[%d] = %d\n", i, arr[i]);
	}
	sp();
}

/* Функция заполнения массива с клавиатуры.
На входе получает:
* arr - указатель на массив
* array_size - размерность массива
*/
void array_input(int* arr, int array_size) {
	sp();
	for (int i = 0; i < array_size; i++)
	{
		printf_s("Введите arr[%d]: ", i); scanf_s("%d", &arr[i]);
	}
}

/* Функция заполнения массива случайными числами.
На входе получает:
* arr - указатель на массив
* array_size - размерность массива
* A - начальное число диапазона случайных чисел
* B - конечное число диапазона случайных чисел
*/
void array_random(int* arr, int array_size, int A, int B) {
	int random;
	sp();
	for (int i = 0; i < array_size; i++)
	{
		random = rand() % (B - A + 1) + A; // Генерация псевдослучайного числа
		arr[i] = random; // Присваивание элементу массива псевдослучайного числа
		printf_s("Заполнен элемент arr[%d] = %d\n", i, random);
	}
}

/* Функция выполнения действий с массивом, исходя из условий задачи.
На входе получает:
* arr - указатель на массив
* array_size - размерность массива
*/
void array_processing(int* arr, int array_size) {
	int negative_count = 0, negative_sum = 0;
	for (int i = 0; i < array_size; i++)
	{
		if (arr[i] < 0) // Подсчёт количества и суммы отрицательных элементов массива
		{
			negative_count++;
			negative_sum += arr[i];
		}
	}

	if (negative_count >= 2) // Обработка условия по количеству отрицательных эл-в массива
	{
		for (int i = 0; i < array_size; i++)
		{
			arr[i] += negative_sum;
		}
	}
}

// Главная функция, запускаемая при инициализации.
int main() {
	setlocale(LC_ALL, "Russian"); // Установка русской локализации
	int* arr; // Инициализация указателя на массив
	int way, A, B, array_size; // Инициализация остальных переменных
	srand(time(NULL)); // Генерация новой псевдослучайной последовательности
	do
	{
		sp();
		printf_s("Способы заполнения массива:\n"
			"1) С клавиатуры\n"
			"2) Случайными числами в заданном диапазоне\n\n"
			"Каким способом вы хотите заполнить массив? "); scanf_s("%d", &way);
		sp();
		if (way > 2 || way < 1) { printf_s("Неверное значение способа заполнения массива!\n"
			"Значение должно быть равно 1 или 2.\n"); }
	} while (way > 2 || way < 1);

	printf_s("Введите размерность массива: "); scanf_s("%d", &array_size);
	arr = (int*)malloc(array_size * sizeof(int)); // Выделение памяти под массив
	switch (way) // Обработка введённого способа заполнения массива
	{
	case 1: { // Выбран ввод с клавиатуры
		array_input(arr, array_size);       // Функция ввода чисел с клавиатуры
		array_processing(arr, array_size);  // Функция обработки массива в соответствии с условием задачи
		array_print(arr, array_size);       // Функция вывода массива на экран
	} break;
	case 2: { // Выбрано заполнение псевдослучайными числами
		printf_s("Введите начало диапазона случайных чисел для заполнения массива: "); scanf_s("%d", &A);
		printf_s("Введите конец диапазона случайных чисел для заполнения массива: "); scanf_s("%d", &B);
		array_random(arr, array_size, A, B); // Функция заполнения массива псевдослучайными числами
		array_processing(arr, array_size);   // Функция обработки массива в соответствии с условием задачи
		array_print(arr, array_size);        // Функция вывода массива на экран
	} break; }

	return 0; // Завершение программы
}