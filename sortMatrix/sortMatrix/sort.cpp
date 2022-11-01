/*Ввести елементи матриці розміру n x m.
Впорядкувати (переставити) рядки матриці по
зростанню значень найменших елементів рядків. 
(Можна користуватися додатковим масивом)*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	cout << "enter n and m" << endl;
	cin >> n >> m;
	vector <int> array(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> array[i, j];
		}
	}
	
	int min;
	for (int i = 0; i < n; i++) {
		int min1 = array[i, 0];
		for (int j = 0; j < m; j++) {
			if (array[i, j] < min1) min = array[i, j];
		} cout << min << endl;
	}

	return 0;
}