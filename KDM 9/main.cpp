#include <iostream>
#include <stdlib.h>
#include <stdio.h>
const int inf=1E9;
using namespace std;
int main()
{
 int n,i,j,k,d[100][100];
 cout << "Введите количество вершин графа >>\n";
 scanf("%d",&n);
 n=7;
////////////////////////////////
int bet [7][7];
for (int i=0;i<7;i++)
for (int j=0;j<7;j++)
{
bet[i][j]=0;
}
bet[0][1]=5;
bet[1][2]=7;
bet[1][3]=-1;
bet[4][2]=3;
bet[5][2]=11;
bet[5][3]=6;
bet[6][0]=1;
cout << "Матрица весов ребер графа :\n ";
for (int i=0;i<7;i++)
{
for (int j=0;j<7;j++)
{
cout <<bet[i][j]<<"   ";
}
cout << endl;
}
cout << "====================\n";
cout << "Матрица путей для вершин графа : \n";
for (int i=0;i<7;i++)
for (int j=0;j<7;j++)
{
d[i][j]=1001;
}
d[0][1]=5;
d[1][2]=7;
d[1][3]=-1;
d[4][2]=3;
d[5][3]=6;
d[5][2]=11;
d[6][0]=1;



//////////////////////
 for (i=0;i<n;++i)
  for (j=0;j<n;++j)
  {
 //  scanf("%d",&d[i][j]);
   if (i==j) d[i][j]=min(d[i][j],0);
   if (d[i][j]==1001) d[i][j]=inf;
  }
 for (k=0;k<n;++k)
  for (i=0;i<n;++i)
   for (j=0;j<n;++j)
    if (d[i][k]<inf && d[k][j]<inf) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
 for (i=0;i<n;++i)
  if (d[i][i]<0) { printf("INCORRECT INPUT"); return 0; }
 for (i=0;i<n;++i,printf("\n"))
  for (j=0;j<n;++j)
   if (d[i][j]==inf) printf("X "); else printf("%d ",d[i][j]);
}
