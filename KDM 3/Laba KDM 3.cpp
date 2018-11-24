#define MIN(x,y) ((x)<(y)?(x):(y))
#include <iostream>
#include <iomanip>
using namespace std;

int A[10][10];
int b[10][10];
int c[10][10];
int kvad[10][10];
int C[10][10];
int zikl[30];
int n, m, s;
//=============== головна функцiя ================


int main()
{
	setlocale(0, "Russian");
	cout << "Введите количество вершин n: ";
	cin >> n;
//	n=4;
	cout << "Введите количество ребер m: ";
	cin	>> m;
//	m=4;
	cout << "Введите 1, если граф ориентированый или 0, если нет: ";
	cin >> s;
	cout << "Введите граф: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
		{  cin >> A[i][j];
		}
	}

     ////////////////////////////////
   /*   A[0][0]=1;
     A[0][1]=2;
     A[1][0]= 2;
     A[1][1]=3;
  A[2][0]= 3;
     A[2][1]= 4;
     A[3][0]=4;
     A[3][1]=4;*/
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

	cout << "Матрица инцидентности:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(2)<< c[i][j];
		cout << endl;
	}
///////////////////////////// Новый массив  для степени SUMijnist
int Step [19],maz;
if (s==0)
{ int w[20],s[20],d=0,k=0;
int temp=0,tep=0;

  for ( int i=0; i<n;i++)
  {
      for ( int j=0 ;j<m;j++)
      {
          if (c[i][j]!=0)
            temp++;
      }
      Step[i]=temp;
      if (temp==1) {w[d]=i;d++;}
      if(temp==0) {s[k]=i;k++;}
      temp=0;
      if (Step[i]>tep) {tep=Step[i];maz=i+1;}
       cout << "Степень вершины d(v"<<i+1<<") = "<<Step[i]<<endl;
  }
    for (int i=0;i<d;i++)
    cout <<"Вершина "<<"v"<<w[i]+1<<" --Висячая\n";
    for (int i=0;i<k;i++)
    cout <<"Вершина "<<"v"<<s[i]+1<<" --Изолирована\n";
	int kol = 0;
	for (int i = 0; i <= n; i++)
	{
		if (Step[i] == Step[i + 1]) kol += 1;
	}
	if (kol==n)  {cout << "Система однородная \n";}
    else {cout<<"Система не однородная \n";  cout << endl;}
}
else
{ int temp1=0, temp2=0;

    int Step2 [20][2];
      for ( int i=0; i<n;i++)
  {
      for ( int j=0 ;j<m;j++)
      {
          if (c[i][j]==1) temp1++;
          if (c[i][j]==-1) temp2++;
          if (c[i][j]==2) {temp1++;temp2++;}
      }
      Step2[i][0]=temp1; //VHOD
      Step2[i][1]=temp2; // VIHOD
      temp1=0; temp2=0;
       cout << "Cтепень полувхода вершины  "<<i+1<<" = "<< Step2[i][0]<<endl;
       cout << "Cтепень полувыхода вершины "<<i+1<<" = "<< Step2[i][1]<<endl;
  }
}
///////////////////////////// Изолированые вершины
int prov=0;
for (int i=0;i<n;i++)
{
    for (int j=0;j<m;j++)
    {
    if (c[i][j]==0) prov++;
    }
        if(prov==m) cout <<"Вершина "<<i+1<<"- изолированая\n";
        prov=0;
}
/////////////////////////////////////
  cout << "матрица расстояний\n";
    int **edge = new int *[n];
    for (int i = 0; i < n; i++)
        edge[i] = new int [n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            edge[i][j] = b[i][j];
            if (!edge[i][j])
                edge[i][j] = 10000;
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    edge[i][j] = MIN(edge[i][j], edge[i][k]+edge[k][j]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (edge[i][j] == 10000)
                edge[i][j] = 0;
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int z=0;z<n-1;z++)
    {
       for (int i = 0; i < n; ++i)  
	   {                            
	    for (int j = 0; j < n; ++j) 
		{                                  
         float sum = 0;                                                  
           for (int k = 0; k < n; ++k)
		   {                                   
            sum += b[i][k] * kvad[k][j];
	       }
           C[i][j] = sum;                                                
        }   
       }
               for (int i = 0; i < n; ++i)
	           {                                    
	             for (int j = 0; j < n; ++j)                                    
                  {                                                             
                   b[i][j] = C[i][j];                                   	                                                   
	              } 
               }
	}        
	cout << "****************\n";  
	cout << "Матрица досегаемости\n";                                                   
             for (int i = 0; i < n; ++i)
            	{                                    
	              for (int j = 0; j < n; ++j)                                    
                     { 
					    if (C[i][j]!=0)
					        {
					 	     C[i][j]=1;
					        }  
							 C[i][i]=1;                                                         
                             cout << C[i][j]<<" ";                                   	                                                   
	                 } 
            	 cout << endl;
                }
cout << "****************\n";

cout << "****************\n";
//cout << "**"<<maz<<"**";
   cout << "Цикл\n";
		 if (A[0][0]==maz||A[0][1]==maz)
		 {
		   //cout << A[0][0]<<A[0][1];
		   for (int i=1;i<n;i++)
		   {
		     for (int j=0;j<2;j++)
		     {
		       cout << A[i][j];
		     }
		     cout << " | ";
		     if ( A[i][1]==A[1][0])
		        break;
		   }
         }

         else if(A[0][0]!=maz&&A[0][1]!=maz)
         {

		  // cout << A[0][0]<<A[0][1];
		   for (int i=0;i<n;i++)
		   {
		     for (int j=0;j<2;j++)
		     {
		       cout << A[i][j];
		     }
		     cout << " | ";
		     if ( A[i][1]==A[0][0])
		        break;
		   }
         }
          else if(A[0][0]!=maz && A[0][1]!=maz&&A[1][0]!=maz&&A[1][1]==maz)
         {

		 //  cout << A[0][0]<<A[0][1];
		   for (int i=2;i<n;i++)
		   {
		     for (int j=0;j<2;j++)
		     {
		       cout << A[i][j];
		     }
		     cout << " | ";
		     if ( A[i][1]==A[2][0])
		        break;
		   }
         }


//cout << "Цикла нет\n";
	cin.get();
}

