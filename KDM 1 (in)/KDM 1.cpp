#include<iostream>
#include<stdio.h>
#include<ctime>
#include<cstring>
#include<stdlib.h>
void mass(int rad , int stov);
using namespace std;
int rad,stov;

int main ()
{
	setlocale(0, "rus");
	cout << " ������� ���������� ������ ����� ";
   cin>>rad;
   cout << " ������� ���������� ����� ����� ";
    cin>>stov;	
	mass (rad,stov);
	system("pause");
}

void mass (int rad,int stov)
{
	int  mas [rad][stov];
	for (int i=0;i<rad;i++)
	{
		for (int j=0;j<stov;j++)
		{
			mas[i][j]=0;
		}
	}
	int k,s;
 for (int i=0;i<stov;i++)
 {
 	cout << "����� e"<<i+1<<" ������ � ������� >>"; cin >>k;
 	cout << "����� e"<<i+1<<" ������� � ������� <<"; cin >> s;
 	//if (k==s) 
	 mas[0][0]=2;
 	mas[k-1][i]=1;
 	mas[s-1][i]=-1;
 	
 	
 }
 cout << "������� ������������� ������� �����...\n";
	for (int i=0;i<rad;i++)
	{
		for (int j=0;j<stov;j++)
		{
			cout << mas[i][j]<<"\t";
		}
		cout << endl;
	}
	cout << "�������! :)";

	
}
 
 
 
 
 
