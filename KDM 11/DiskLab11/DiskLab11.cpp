//#include "stdafx.h";
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
//#include <conio.h>

#define SIZE 20							//������������ ������ ����� (�������� ��� ������, ��� � �����)
using namespace std;

int n, m;
const bool weight = false;				//������� ����� � ����� (������������ ������ ��� �����-������! ��������� ����������)
typedef int Matrix[SIZE][SIZE];
Matrix Graph, Adj;
bool visited[SIZE];
int way[SIZE];

void inputGraph(bool, Matrix);
void adjacency(Matrix, Matrix);
void GamiltonWay(Matrix, int);


int main()
{
	setlocale(LC_ALL, "Russian");
	inputGraph(weight, Graph);


	adjacency(Graph, Adj);
	for (int i = 0; i < n; i++)
		visited[i] = false;
	int t, check = 1;
	while (check == 1) {
		cout << " > ������� ��������� ������� : ";
		cin >> t;
		GamiltonWay(Adj, t - 1);
		if (way[0] == 0) cout << " > ����������� ���� �����������."; else
		{
			if (Adj[way[n - 1] - 1][way[0] - 1] == 1)
				cout << " > ����������� ���� : ";
			else cout << " > ����������� ���� : ";
			for (int i = 0; i < n; i++)
				cout << setw(3) << way[i];
		}
		cout <<endl<< " > ������ ����������� ������ ������� ? (1 - ��) ";
			cin >> check;
	}
	cout << endl;
//	_getch();
	return 0;
}

void inputGraph(bool weight, Matrix g)
{
	cout << " > ������� ���������� ������ ����� : "; cin >> n;
	while (n < 1) {
		cout << "!!! ����������� ����� , ���������� ��� ��� !!!" << endl << "������� ���-�� ������ ����� : "; cin >> n;
	}
	cout << " > ������� ���������� ����� ����� : "; cin >> m;
	while (m < 1) {
		cout << "!!! ����������� ����� , ���������� ��� ��� !!!" << endl << "������� ���-�� ����� ����� : "; cin >> m;
	}
	for (int j = 0; j<m; j++)
	{
		cout << " > ������� ������� ������ � ����� ����� : "; cin >> g[j][0] >> g[j][1];
	}
}

void adjacency(Matrix graph, Matrix adj)
{
	for (int i = 0; i < m; i++)
		adj[graph[i][0] - 1][graph[i][1] - 1] = 1;
}

void GamiltonWay(Matrix a, int s)
{
	visited[s] = true;
	for (int i = 0; i < n; i++)
		if (way[i] == 0) { way[i] = s + 1; break; }
	for (int i = 0; i < n; i++)
	{
		if (way[n - 1] != 0) return;
		if (a[s][i] == 1 && !visited[i]) GamiltonWay(a, i);
	}
	visited[s] = false;
	for (int i = 0; i < n; i++)
		if (way[i] == 0) { way[i - 1] = 0; break; }
}
