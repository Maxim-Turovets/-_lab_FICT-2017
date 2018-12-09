#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;
const int siz = 20;
typedef int Matrix[siz][siz];
int n, m, St[siz], k = 0;
Matrix G, S;
void graph_input(Matrix);
void matr_sum(Matrix, Matrix);
bool CycleCheck(Matrix);
int WayCheck(Matrix);
void FindEulerPath(int);

int main()
{
	setlocale(LC_ALL, "rus");
	graph_input(G);
	matr_sum(G, S);
	int way = WayCheck(S);
	if (CycleCheck(S))
	{
		cout << " > Граф содержит цикл Эйлера :";
		FindEulerPath(1);
		for (int i = m; i >= 0; i--) cout << setw(3) << St[i];
		cout << endl;
	}
	else
	{
		if (way != 0)
		{
			cout << " > Граф содержит путь Эйлера:";
			FindEulerPath(way);
			for (int i = m; i >= 0; i--) cout << setw(3) << St[i];
			cout << endl;
		}
		else cout << " > Граф не содержит ни циклов, ни путей Эйлера." << endl;
	}
	_getch();
	//system("pause");
	return 0;
}

void graph_input(Matrix g)
{
	cout << " > Введите кол-во вершин графа : "; cin >> n;
	while (n < 1) {
		cout << "!!! Некоректный ответ , попробуйте еще раз !!!" << endl << "Введите кол-во вершин графа : "; cin >> n;
	}
	cout << " > Введите кол-во ребер графа : "; cin >> m;
	while (n < 1) {
		cout << "!!! Некоректный ответ , попробуйте еще раз !!!" << endl << "Введите кол-во ребер графа : "; cin >> n;
	}
	for (int j = 0; j<m; j++)
	{
		cout << " > Введите начало и конец ребра : "; cin >> g[j][0] >> g[j][1];
	}
}


void matr_sum(Matrix g, Matrix s)
{
	for (int i = 0; i < m; i++)
		s[g[i][0] - 1][g[i][1] - 1] = 1;
}
bool CycleCheck(Matrix matr)
{
	bool flag = true;
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s1 += matr[i][j];
			s2 += matr[j][i];
		}
		if (s1 != s2) flag = false;
		s1 = 0;
		s2 = 0;
	}
	return flag;
}
int WayCheck(Matrix matr)
{
	int s1 = 0, s2 = 0, v = 0, start;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s1 += matr[i][j];
			s2 += matr[j][i];
		}
		if (s1 == s2); else
			if (s1 == s2 + 1)
			{
				v++;
				start = i + 1;
			}
			else
				if (s1 == s2 - 1) v++; else v = 3;
		s1 = 0;
		s2 = 0;
	}
	if (v == 2) return start; else
		return 0;
}
void FindEulerPath(int start)
{
	start--;
	for (int i = 0; i < n; i++)
		if (S[start][i] == 1)
		{
			S[start][i] = 0;
			//cout << i + 1;
			FindEulerPath(i + 1);
		}
	St[k] = start + 1;
	k++;
}
