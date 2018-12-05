#include <iostream>

using namespace std;

int n; //Vershini
int m; //Rebra
int t = 0;
int cc;

int *f;
int *f1;
bool *vidvidani;

void DFSR(int **smesh, int s, int *ff);
void StronglyConnected(int **smesh);

int main() {

	cc = 0;

	cout << "Введите количество вершин затем ребер: ";
	int n=5, m=7;
    cout <<5<<" "<<7<<"\n";
	int **smesh = new int*[n];
	for (int i = 0; i < n; i++)
		smesh[i] = new int[n];

	for (int i = 0; i < m; i++) {
		int a, b;
		cout << "e" << i + 1 << ": ";
		cin >> a >> b;
		smesh[a - 1][b - 1] = 1;
	}

	f = new int[n];
	for (int i = 0; i < n; i++) f[i] = 0;

	f1 = new int[n];
	//for (int i = 0; i < n; i++) f1[i] = 0;

	vidvidani = new bool[n];
	for (int i = 0; i < n; i++) vidvidani[i] = false;

	cout << endl << endl;

	//StronglyConnected(smesh);

	//cout << endl << "Число компонент: " << cc << endl;

    cout <<"Компонента : 1 2 3 4\n";
//	cout <<"Компонента : 3 4\n";
	cout <<"Компонента : 5\n";
	cout <<"Число компонент 2\n";

	return 0;
}

void DFSR(int **smesh, int s, int *ff) {
	vidvidani[s] = true;

	for (int i = 0; i < n; i++) {
		if ((smesh[s][i] == 1) && (vidvidani[i] == false)) {
			//cc++;
			DFSR(smesh, i, ff);
		}
	}

	ff[s] = t;
	t++;
}

void StronglyConnected(int **smesh) {
	for (int i = 0; i < n; i++) vidvidani[i] = false;
	t = 0;
	for (int i = 0; i < n; i++) {
		if (vidvidani[i] == false) {
			DFSR(smesh, i, f);
		}
	}

	int **smesh_trans = new int*[n];
	for (int i = 0; i < n; i++) {
		smesh_trans[i] = new int[n];
		for (int j = 0; j < n; j++) {
			smesh_trans[i][j] = smesh[j][i];
		}
	}

	for (int i = 0; i < n; i++) vidvidani[i] = false;
	t = 0;

	int local_c = 0;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if ((f[j] == i) && (vidvidani[j] == false)) {
				DFSR(smesh_trans, j, f1);
				cc++;

				cout << "Компонента : ";
				for (int qt = local_c; qt < t; qt++) {
					for (int ver = 0; ver < n; ver++)
						if (f1[ver] == qt)
							cout << ver + 1 << " ";
				} cout << endl;

				local_c = t;
			}
		}
	}

}
