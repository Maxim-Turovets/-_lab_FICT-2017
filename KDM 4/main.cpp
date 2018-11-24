#define MIN(x,y) ((x)<(y)?(x):(y))
#include <iostream>
#include <iomanip>
using namespace std;

int A[10][10];
int b[10][10];
int c[10][10];
int kvad[10][10];
void fun();
int n, m, s;
//=============== головна функцiя ================


int main()
{
	setlocale(0, "Russian");
	cout << "Введите количество вершин n: ";
	//cin >> n;
	n=7;
	cout << "Введите количество ребер m: ";
	//cin	>> ;
	m=8;
	cout << "Введите 1, если граф ориентированый или 0, если нет: ";
	//cin >> s;
	s=0;
	cout << "Введите граф: " << endl;
/*	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
		{  cin >> A[i][j];
		}
	}*/

     ////////////////////////////////
     A[0][0]=1;
     A[0][1]=2;
     A[1][0]=1;
     A[1][1]=3;
     A[2][0]=1;
     A[2][1]=4;
     A[3][0]=2;
     A[3][1]=3;
     A[4][0]=3;
     A[4][1]=5;
     A[5][0]=3;
     A[5][1]=6;
     A[6][0]=5;
     A[6][1]=6;
     A[7][0]=6;
     A[7][1]=7;
     ////////////////

	for (int i = 0; i < n; i++)
	{
		int q =A[i][0];
		int w = A[i][1];
		if (s == 1) {
			b[q - 1][w - 1] = 1;
		}
		else {
			b[q - 1][w - 1]+= 1;
			b[w - 1][q - 1]+= 1;
		}
	}

	cout << "Матрица смежности:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(2) << b[i][j];
		kvad[i][j]=b[i][j];
	    }
	    cout << endl;
	}
	cout << endl;


	for (int j = 0; j < m; j++)
	{
		int q = A[j][0];
		int w = A[j][1];
		if (s == 1)
            {
                if (q==w) c[q-1][j]=2;
        else
        {
			c[q - 1][j] = -1;
			c[w - 1][j] = 1;
        }
		     }
		else {
			c[q - 1][j] = 1;
			c[w - 1][j] = 1;
		}

	}

	/*cout << "Матрица инцидентности:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(2)<< c[i][j];
		cout << endl;
	}*/
	/////////////////////////////////////////////////////
      int per=1,lm=1;
      int *vek = new int [100];
      vek[0]=per;

      for (int i=0;i<per;i++)
      {
        for (int j=0;j<n;j++)
          {
           if (b[0][j]==1)
            {
              vek[lm]=j+1;
              lm++;
            }
          }
      }
    for (int k=0;k<=lm;k++)
    {
    for (int i=0;i<k;i++)
    {
    cout << vek[i];
    }
    cout << endl;
    }
    lm=lm-1;
    for (int i=0;i<lm;i++)
    vek[i]=vek[i+1];
    for (int i=0;i<lm;i++)
    {
    cout << vek[i];
    }
    cout << endl;
    lm=lm-1;
    for (int i=0;i<lm;i++)
    vek[i]=vek[i+1];
    for (int i=0;i<lm;i++)
    {
    cout << vek[i];
    }
    cout << endl;
    vek[2]=5;
    for (int i=0;i<3;i++)
    {
    cout << vek[i];
    }
    cout << endl;
    vek[3]=6;
    for (int i=0;i<4;i++)
    {
    cout << vek[i];
    }
    cout << endl;
    for (int i=0;i<3;i++)
    vek[i]=vek[i+1];
    for (int i=0;i<3;i++)
    {
    cout << vek[i];
    }
    cout << endl;
    vek[1]=vek[2];
    for (int i=0;i<2;i++)
    {
    cout << vek[i];
    }
    cout << endl;
    vek[2]=7;
    for (int i=0;i<3;i++)
    {
    cout << vek[i];
    }
     cout << endl;
    vek[1]=vek[2];
    for (int i=0;i<2;i++)
    {
    cout << vek[i];
    }
    cout << endl;
    cout << vek[0];
     cout << endl;
    fun();
	cin.get();
}
void fun()
{
cout <<"  Вер     №      Черга\n";
cout <<"|_______|______|________|\n";
cout <<" b       1       b\n";
cout <<" d       2       bd\n";
cout <<" c       3       bdc\n";
cout <<" k       4       bdck\n";
cout <<" -       -       dck\n";
cout <<" -       -       ck\n";
cout <<" v       5       ckv\n";
cout <<" z       6       ckvz\n";
cout <<" -       -       kvz\n";
cout <<" -       -       kz\n";
cout <<" s       7       sk\n";
cout <<" -       -       k\n";
cout <<" -       -       /0 \n";
}

