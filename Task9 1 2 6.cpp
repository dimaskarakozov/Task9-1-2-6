// Task9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void zadanie1() {
	int i, j, ** mas1, * mas2, tuda;
	printf("Выполнить операцию\nтуда - 1\nобратно-2 ?\n");
	scanf("%d", &tuda);
	


	//выделили память
	if (tuda == 1) {
		printf("Введите число строк: ");
		scanf("%d", &j);
		printf("Введите число столбцов: ");
		scanf("%d", &i);

		mas1 = (int**)malloc(i * sizeof(int*));
		for (int q = 0; q < i; q++) {
			mas1[q] = (int*)malloc(j * sizeof(int));
		}
		mas2 = (int*)malloc((j * i) * sizeof(int));
		for (int w = 0; w < i; w++) {

			for (int q = 0; q < j; q++) {
				printf("Введите значение: ");
				scanf("%d", &mas1[w][q]);
			}
		}
		printf("Начальный массив:");
		for (int w = 0; w < i; w++) {
			printf(" \n");
			for (int q = 0; q < j; q++) {
				printf("\t%d", mas1[w][q]);
			}
		}
		printf("\nПеределанный туда");
		for (int w = 0; w < i; w++) {
			for (int q = 0; q < j; q++) {
				mas2[w * q + q] = mas1[w][q];
				printf("\t%d", mas2[w * q + q]);
			}
		}
	}
	else if (tuda == 2) {
		printf("Введите число элементов в строке: ");
		scanf("%d", &j);
		mas2 = (int*)malloc((j) * sizeof(int));
		for (int j1 = 2; j1 < j; j1++) {
			if (j % j1 == 0) {
				i = j1;
				j= j / j1;
			}
		}
		
		mas1 = (int**)malloc(i * sizeof(int*));
		for (int q = 0; q < i; q++) {
			mas1[q] = (int*)malloc(j * sizeof(int));
		}




		for (int w = 0; w < i * j; w++) {

			printf("Введите значение: ");
			scanf("%d", &mas2[w]);

		}
		printf("Начальный массив:");
		for (int w = 0; w < i * j; w++) {
			printf("\t%d", mas2[w]);
		}

		printf("\nПеределанный обратно\n");
		for (int w = 0; w < i; w++) {
			printf("\n");
			for (int q = 0; q < j; q++) {
				mas1[w][q] = mas2[w * j + q];
				printf("\t%d", mas1[w][q]);
			}
		}

	}
	else {
		printf("Вы не правильно ввели данные");
	}

}
void zadanie2() {
	int n, m;
	printf("Введите размер через пробел");
	scanf("%d %d", &n, &m);

	int** mas;
	mas = (int**)malloc(n * sizeof(int*));
	for (int q = 0; q < n; q++) {
		mas[q] = (int*)malloc(m * sizeof(int));
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			mas[i][j] = j + 1 - i;
			if (mas[i][j] <= 0) {
				mas[i][j] = 2 - mas[i][j];
			}
		}
	}


	for (int i = 0; i < n; i++) {  //вывод
		printf("\n");
		for (int j = 0; j < m; j++) {
			printf("\t%d", mas[i][j]);
			mas[i][j] = 0;
		}
	}
	printf("\n\n");
	*/

	int sum = 1;

	if (n % 2 == 1 && m % 2 == 1) {
		mas[n / 2][m / 2] = n * m;

	}

	int krugov;
	if (n > m) {
		krugov = n / 2;
	}
	else{
		krugov = m / 2;
	}
	for (int i = 0; i < krugov; i++) {
		for (int j = i; j < (m - i); j++) {
			mas[i][j] = sum;
			sum++;
		}
		for (int j = 1; j < (n - i - i); j++) {
			mas[(j + i)][m- i -1] = sum;
			sum++;
		}
		for (int j = m-2 - i; j >= i; j--) {
			mas[n - i - 1][(j)] = sum;
			sum++;
		}
		for (int j = ((n - i) - 2); j > i; j--) {
			mas[j][i] = sum;
			sum++;
		}
	}


	for (int i = 0; i < n; i++) {  //вывод
		printf("\n");
		for (int j = 0; j < m; j++) {
			printf("\t%d", mas[i][j]);
		}
	}



}


void gaussMethod(
	int m,          // Число столбцов матрицы
	int n,          // Число  строк матрицы
	double* a,      // Адрес массива элементов матрицы
	double eps      // Точность вычислений
) {
	int i, j, k, l;
	double r;

	i = 0; j = 0;
	while (i < m && j < n) {
		// Инвариант: минор матрицы в столбцах 0..j-1
		//   уже приведен к ступенчатому виду, и строка
		//   с индексом i-1 содержит ненулевой эл-т
		//   в столбце с номером, меньшим чем j

		// Ищем максимальный элемент в j-м столбце,
		// начиная с i-й строки
		r = 0.0;
		for (k = i; k < m; ++k) {
			if (fabs(a[k * n + j]) > r) {
				l = k;      // Запомним номер строки
				r = fabs(a[k * n + j]); // и макс. эл-т
			}
		}
		if (r <= eps) {
			// Все элементы j-го столбца по абсолютной
			// величине не превосходят eps.
			// Обнулим столбец, начиная с i-й строки
			for (k = i; k < m; ++k) {
				a[k * n + j] = 0.0;
			}
			++j;      // Увеличим индекс столбца
			continue; // Переходим к следующей итерации
		}

		if (l != i) {
			// Меняем местами i-ю и l-ю строки
			for (k = j; k < n; ++k) {
				r = a[i * n + k];
				a[i * n + k] = a[l * n + k];
				a[l * n + k] = (-r); // Меняем знак строки
			}
		}

		// Утверждение: fabs(a[i*n + k]) > eps

		// Обнуляем j-й столбец, начиная со строки i+1,
		// применяя элем. преобразования второго рода
		for (k = i + 1; k < m; ++k) {
			r = (-a[k * n + j] / a[i * n + j]);

			// К k-й строке прибавляем i-ю, умноженную на r
			a[k * n + j] = 0.0;
			for (l = j + 1; l < n; ++l) {
				a[k * n + l] += r * a[i * n + l];
			}
		}

		++i; ++j;   // Переходим к следующему минору
	}


}

void treug() {
	int  n, m, i, j, rank;
	double* a;
	double eps, det;

	printf("Введите размеры матрицы m, n: ");
	scanf("%d", &m);
	n = 2 * m;

	// Захватываем память под элементы матрицы
	a = (double*)malloc((m * n) * sizeof(double));

	printf("Введите элементы матрицы:\n");
	for (i = 0; i < m; ++i) {
		for (j = 0; j < m; ++j) {
			// Вводим элемент с индексами i, j
			scanf("%lf", &(a[i * n + j]));
		}
	}

	printf("Введите точность вычислений eps: ");
	scanf("%lf", &eps);


	for (i = 0; i < m; ++i) {
		for (j = m; j < n; ++j) {
			if (i + m == j) {
				a[i * n + j] = 1;
			}
			else {
				a[i * n + j] = 0;
			}
		}
	}


	// Вызываем метод Гаусса
	gaussMethod(m, n, a, eps);


	j = 1;
	i = m * n - 1 - m;
	for (int zxc = 0; zxc < m; zxc++) {
		int q = a[i];
		for (int qwe = i+1; qwe < m+zxc; qwe++) {
			a[qwe] = a[qwe] / a[i];
		}
		a[i] = 1;
		for (int k = 0; k < m - zxc - 1; k++) {
			for (int qwe = i - n + 1; qwe < n; ++qwe) {
				a[qwe-k*n] = a[qwe - k * n] - (a[i - n - k * n] * a[qwe + n]);
			}
			a[i - n - k * n]=0;
		}





		j++;
		i = i - n - 1;
	}



	//определитель 
	det = 1.0;
	for (i = 0; i < m; ++i) {
		det = det * a[i * n + i];
	}
	printf("Определитель матрицы = %.3lf\n", det);


	printf("Конечный результат:\n");
	for (i = 0; i < m; ++i) {
		// Печатаем i-ю строку матрицы
		for (j = 0; j < n; ++j) {
			printf(         // Формат %10.3lf означает 10
				"%10.3lf ", // позиций на печать числа,
				a[i * n + j]  // 3 знака после точки
			);
		}
		printf("\n");   // Перевести строку
	}

	printf("Тогда ответ:\n");
	for (i = 0; i < m; ++i) {
		// Печатаем i-ю строку матрицы
		for (j = m; j < n; ++j) {
			printf(         // Формат %10.3lf означает 10
				"%10.3lf ", // позиций на печать числа,
				a[i * n + j]  // 3 знака после точки
			);
		}
		printf("\n");   // Перевести строку
	}
	
}


void zadanie6() {
	treug();
}



int main()
{


	int q = -1;
	setlocale(LC_ALL, "Russian");

	//Task6

	printf("\n\n1) (1)  Считаем, что двумерный массив размера m на n преобразуется в одномерный массив размера m* n путем последовательной записи строк. (m и n заданы) Реализовать такое преобразование «туда» и «обратно».  ");
	printf("\n\n2) (2) Заполнить двумерный массив размером n x m так, как представлено в таблице для 5х5");
	printf("\n\n6) (2) Найти обратную матрицу методом Гаусса (сделать проверку)");
	printf("\n\n0)Выйти");
	while (q != 0) {
		printf("\n\nВведите номер нужного задания : ");
		scanf_s("%d", &q);
		switch (q) {
		case 1: {
			zadanie1();//Задание 1
			break;
		}
		case 2: {
			zadanie2();//Задание 2
			break;
		}
		case 6: {
			zadanie6();//Задание 6
			break;
		}

		}
	}
	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
