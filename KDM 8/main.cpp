#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
int main()
{
  int a[SIZE][SIZE]; // матрица связей
  int d[SIZE]; // минимальное расстояние
  int v[SIZE]; // посещенные вершины
  int temp;
  int minindex, min;
  // Инициализация матрицы связей
  for (int i = 0; i<SIZE; i++)
  {
    a[i][i] = 0;
    for (int j = i + 1; j<SIZE; j++) {
      printf("Введите расстояние %d - %d: ", i + 1, j + 1);
      scanf("%d", &temp);
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }
  // Вывод матрицы связей
  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }
  //Инициализация вершин и расстояний
  for (int i = 0; i<SIZE; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }
  d[0] = 0;
  // Шаг алгоритма
  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i<SIZE; i++)
    { // Если вершину ещё не обошли и вес меньше min
      if ((v[i] == 1) && (d[i]<min))
      { // Переприсваиваем значения
        min = d[i];
        minindex = i;
      }
    }
    // Добавляем найденный минимальный вес
    // к текущему весу вершины
    // и сравниваем с текущим минимальным весом вершины
    if (minindex != 10000)
    {
      for (int i = 0; i<SIZE; i++)
      {
        if (a[minindex][i] > 0)
        {
          temp = min + a[minindex][i];
          if (temp < d[i])
            d[i] = temp;
        }
      }
      v[minindex] = 0;
    }
  } while (minindex < 10000);
  // Вывод матрицы связей
  for (int i = 0; i<SIZE; i++)
    printf("%5d \n", d[i]);
  getchar(); getchar();
  return 0;
}
