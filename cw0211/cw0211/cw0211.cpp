#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{ cin >> a[i]; }
	cin >> m;
	int* b = new int[m];
	
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
	for (k = 0; k < n+m; k++) {
		cout << result[k]<< " ";
	}
	return 0;
}