//1.	Ввести елементи матриці розміру n x m. 
//Впорядкувати (переставити) рядки матриці по зростанню значень 
//найменших елементів рядків. (Можна користуватися додатковим масивом)
#include <iostream>
using namespace std;
int main() {
    int n, m;
    cout << "enter the size of a matrix: " << endl;
    cin >> n >> m;
	int** matrix=new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    cout << "enter the matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int min=INT_MAX;
    int* arr=new int [n];
    for (int i = 0; i < n; i++) {
        min = matrix[i][0];
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min) min = matrix[i][j];
        } 
        arr[i] = min;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) { swap(arr[j], arr[j + 1]);
            for (int o = 0; o < m; o++) {
                swap(matrix[j][o], matrix[j + 1][o]);
            }
            }
        }
    }
    cout << "the sorted matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        } cout << endl;
    }
    return 0;
}