//#include <iostream>
//using namespace std;
//
//double* transform(int* arr, int n, double(*pf)(int)) {
//	double* b = new double[n];
//	for(int i=n-n;i<n;i++)
//	 b[i]=pf(arr[i]);
//	return b;
//}
//double firsthalf(int n) {
//		return sin(n);
//}
//double secondhalf(int n) {
//		return sqrt(1 + n*n);
//}
//
//int main() {
//	int n;
//	cout << "enter size of the array:" << endl;
//	cin >> n;
//	int* arr = new int[n];
//	cout << "enter the elements of the array:" << endl;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//	
//	cout << "the result is:" << endl;
//	double* b = transform(arr, n / 2, firsthalf);
//	double* c = transform(arr + n / 2, n - n / 2, secondhalf);
//	for (int i = 0; i < n / 2; i++)
//		cout << b[i] << " ";
//	for (int i = n / 2; i < n; i++)
//		cout << c[i - n / 2] << " ";
//
//	return 0;
//}