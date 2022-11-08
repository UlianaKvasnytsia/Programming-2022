//3
#include <iostream>
using namespace std;
int main() {
	int m, n;
	cout << "enter the size of the matrix: " << endl;
	cin >> m >> n;
	double** matrix = new double*[m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new double[n];
	}
	cout << "enter the matrix: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << "your matrix: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	double sum=0, summin = 100000;
	int k = 0;
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += matrix[i][j];
		}
		if (sum < summin) { summin = sum; k = i; }
	}
	
	cout << "the minimal row: " << endl;
		for (int j = 0; j < n; j++) {
			cout << matrix[k][j] << " ";
		}
	
	return 0;
}