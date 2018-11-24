#include<iostream>
#include<stdio.h>
#include<ctime>
#include<cstring>
#include<stdlib.h>
void mass(int n , int m);
using namespace std;
int n,m,g;

int main ()
{
	setlocale(0, "rus");
//	cout << "Если граф неориентированый нажмите 0 б если же нет любую цифру\n";
//	int d; cin >> d;
//	if (d=0) m=m*2;
	cout <<"Введите колечество вершин графа  ";
	cin >> g;
	cout <<"Введите колечество  комбинаций вершин ";
   cin>>n; m=2;	
	mass (n,m);
	system("pause");
}

void mass (int n,int m)
{
	cout <<"Введите первую затем вторую вершины\n";
	int z;
	int **a= new int *[n];
	for ( int i=0;i<n;i++)
	a[i]= new int [m];
	for (int i=0; i<n;i++)
	{
		for ( int j=0;j<m;j++)
		{
			cin >> z; 
			
			a[i][j]=z;
	
			z=0;
			if(j==1||j==5||j==3||j==7||j==9) cout <<"***\n";
		}
		
	}

	/////////////////////
	int k=g;
	int b [k][k];
		for (int i=0; i<k;i++)
	{
		for ( int j=0;j<k;j++)
		{
			b[i][j]=0;
		}
	}

	////////////////////////
	int w , q;
		for (int i=0; i<n;i++)
	{
		w=a[i][0];
		q=a[i][1];
		b[w-1][q-1]=1;
	}
	///////////////////////////'
	cout << "Массив смежности \n";
				for (int i=0; i<k;i++)
	{
		for ( int j=0;j<k;j++)
		{
			cout << b[i][j]<<" ";
		}
		cout << endl;
	}
}

 
 
