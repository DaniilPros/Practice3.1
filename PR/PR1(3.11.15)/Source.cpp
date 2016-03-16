#include<iostream>
#include <cmath>
using namespace std;

void init(int **Array, int length);
void create_array_of_equation(int **Array,double **Equation, int length);
void output(int **Array, int length);
void output(double **Array, int length);
double square(int **Array, int index1, int index2);
double square(int **Array, int length);

int main()
{
	int **a=new int*[2],n;
	cout << "Input count of vertex: ";
	cin >> n;
	a[0] = new int[n];
	a[1] = new int[n];
	init(a, n);
	/*double **e = new double*[2];
	e[0] = new double[n];
	e[1] = new double[n];*/
	cout << "Vertexs : ";
	output(a, n);
	cout << "\nSquare = " << square(a, n)<<endl;
	system("pause");
	return 0;
}

void init(int **a, int c) {
	for (int i = 0; i < c; i++)
	{
		cout << "Coord of " << i + 1 << " vertex (x,y): ";
		cin >> a[0][i] >> a[1][i];
	}
}

void create_array_of_equation(int **a,double **e, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1) {
			e[1][i] = double(a[1][0] - a[1][i]) / double(a[0][0] - a[0][i]);
			e[0][i] = double(a[1][i] * (a[0][0] - 2 * a[0][i]) + a[0][i] * a[1][0]) /double (a[0][0] - a[0][i]);
		}
		else {
			e[1][i] = double(a[1][i + 1] - a[1][i]) /double (a[0][i + 1] - a[0][i]);
			e[0][i] = double(a[1][i] * (a[0][i + 1] - 2 * a[0][i]) + a[0][i] * a[1][i + 1])/double  (a[0][i + 1] - a[0][i]);
		}
	}

	
}

void output(int **a, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[0][i] << " " << a[1][i] << endl;
	}
}

void output(double **a, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[0][i] << " " << a[1][i] << endl;
	}
}

double square(int **a, int i, int j)
{
	double  aa=sqrt(pow((a[0][0]-a[0][i]),2)+ pow((a[1][0] - a[1][i]), 2)), 
		b= sqrt(pow((a[0][i] - a[0][j]), 2) + pow((a[1][i] - a[1][j]), 2)), 
		c= sqrt(pow((a[0][j] - a[0][0]), 2) + pow((a[1][j] - a[1][0]), 2)),
		p=(aa+b+c)/2;
	return sqrt(p*(p-aa)*(p-b)*(p-c));
}

double square(int **a, int n)
{
	double S=0;
	int j = 2, i = 1;
	do {
		S += square(a, i, j);
		i++;
		j++;
	} while (j != n);
	return S;
}