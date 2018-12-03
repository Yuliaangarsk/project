#include "pch.h"
#include "locale.h" 
#include <conio.h> //Для работы функции getch(); 
#include <math.h> //Для работы математических функций 
#include <stdlib.h> //Для реализации псевдослучайных чисел 
#include <ctime> //Для реализации псевдослучайных чисел 
#include <stdio.h> //Cтандартный заголовочный файл ввода-вывода

int input() //Проверка вводимого пользователем числа и возвращение этого числа 
{
	int number = 0;
	char cheking = '\0';
	bool izmenite = false;
	while (!izmenite)
	{
		if (scanf_s("%d%c", &number, &cheking, 1) != 2 || cheking != '\n')
		{
			while (getchar() != '\n'); //Устанавливает внутренний указатель положения файла в начальное положение (начало файла). 
			printf("Введено некорректное значение. Повторите попытку.\n");
		}
		else
		{
			izmenite = true;
		}

	}
	return number;
}

int inputMenu() //Проверка вводимого пользователем числа Меню и возвращение этого числа 
{
	int value = 0;
	char cheking = '\0';
	bool izmenite = false;
	while (!izmenite)
	{
		if (scanf_s("%d%c", &value, &cheking, 1) != 2 || cheking != '\n')
		{
			while (getchar() != '\n'); //Устанавливает внутренний указатель положения файла в начальное положение (начало файла). 
			printf("Введено некорректное значение. Повторите попытку.\n");
		}
		else
		{
			if (value == 1 || value == 2 || value == 3)
			{
				izmenite = true;
			}
		}

	}
	return value;
}
int**inputMatrix(int n, int m)//создание матрицы
{
	int** a = new int*[n];   // здесь передаётся массив в функцию
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m]();

	}
	return a;
}
int ClearMemory(int**a, int n);
{
	for (int i = 0; i < n; i++)//Освобождение памяти 
	{
		delete[] a[i];
	}
	delete[] a;
}
void FillArrayRand(int** a, int n, int m)//заполнение массива случайными элементами 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
}
void FillArray(int** a, int n, int m)//заполнение массива собственными числами 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("Введите элемент матрицы %d %d: ", i + 1, j + 1);
			a[i][j] = input();
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Rus"); //Русский язык 
	srand(time(NULL)); //Для реализации псевдослучайных чисел 
	printf("Введите количество строк и столбцов квадратной матрицы: ");
	int str = input()
		int col = str;
	int** matrix = inputMatrix(str, col);
	bool izmenite = false;
	while (!izmenite)
		int** matrix = inputMatrix(str, col);
	printf("\n1 - Заполнить массив случайными числами\n2 - Заполнить массив собственными числами\n3 - Закрыть программу\n");
	int menu = 0;
	menu = inputMenu();
	if (menu == 3)
	{
		ClearMemory(matrix, str);
	}
	if (menu == 2)
	{
		FillArray(matrix, str, col);
	}
	if (menu == 1)
	{
		FillArrayRand(matrix, str, col);
	}
	menu = 0;
	while (menu != 3)
	{
		printf("\n\n1 - Обработать массив\n2 - Вывести массив на экран\n3 - Закрыть программу\n");
		while (menu != 3)
			menu = inputMenu();
		if (menu == 3)
		{
			ClearMemory(matrix, str);
		}
		if (menu == 1)

		{
			printf("\n\n1 - Обработать массив\n2 - Вывести массив на экран\n3 - Закрыть программу\n");
			menu = inputMenu();
			if (menu == 3)
			{
				_getch();
				for (int i = 0; i < str; i++)		 //Освобождение памяти 
				{
					delete[] matrix[i];
				}
				delete[] matrix;
				return 0;
			}

			if (menu == 1)
			{
				if (menu == 2)
				{
					printf("Матрица:\n");
					for (int i = 0; i < str; i++)
					{
						for (int j = 0; j < col; j++)
						{
							printf("%d ", matrix[i][j]);
						}
						printf("\n");
					}
					printf("\n");
				}
			}

			_getch();
			for (int i = 0; i < str; i++)		 //Освобождение памяти 
			{
				delete[] matrix[i];
			}
			delete[] matrix;
			return 0;
		}
	}
