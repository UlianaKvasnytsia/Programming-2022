#include <iostream>
using namespace std;
int main() {
	int n, m;
	cout << "enter the size of the first array: " << endl;
	cin >> n;
	int* a = new int[n];
	cout << "enter the elements: " << endl;
	for (int i = 0; i < n; i++)
	{ cin >> a[i]; }
	cout << "enter the size of the second array: " << endl;
	cin >> m;
	int* b = new int[m];
	cout << "enter the elements: " << endl;
	for (int i = 0; i < m; i++) 
	{ cin >> b[i]; }
	int* result = new int[n+m];
	int i = 0, j = 0, k=0;
	while (i<n && j<m) {
		if (a[i] > b[j]) {
			result[k] = b[j]; j++;
		}
		else {
			result[k] = a[i]; i++; 
		}
		k++;
	}
	while (i<n) {
			result[k] = a[i];
			k++; i++;
	}
	while (j<m) {
		
			result[k] = b[j];
			k++; j++;
		}
	cout << "sorted array: ";
	for (k = 0; k < n+m; k++) {
		cout << result[k]<< " ";
	}
	return 0;
}