///* ввести два масиви чисел х та у pозміру н та м відповідно. замінити всі елементи масиву на їх куби лише у тому масиві,
//в якому кількіть від'ємних елементів найбільша. Для цього визначити функцію введення масиву, функцію знахождення
//кількості від'ємних елементів та функцію заміни*/
//
//#include <iostream>
//using namespace std;
//
//void input(int* arr, int n) {
//	cout << "enter the elements" << endl;
//	for (int i = 0; i < n; i++) 
//		cin >> arr[i];
//}
//int count(int* arr, int n) {
//	int k = 0;
//	for (int i = 0; i < n; i++) 
//		if (arr[i] < 0) k++;
//	return k;
//}
//void replace(int* arr, int n) {
//	for (int i = 0; i < n; i++)
//		arr[i] = pow(arr[i], 3);
//}
//void output(int* arr, int n) {
//	for (int i = 0; i < n; i++) 
//		cout << arr[i] << ' ';
//	cout << endl;
//}
//int main() {
//	int n, m;
//	cout << "enter the sizes of arrays" << endl;
//	cin >> n >> m;
//	int* x = new int[n];
//	int* y = new int[m];
//	
//	input(x, n);
//	input(y, m);
//	int k1= count(x, n);
//	int k2 = count(y, m);
//	cout << "the result is: " << endl;
//	if (k1 > k2) replace(x, n); 
//	else replace(y, m); 
//
//	output(x, n); output(y, m);
//	return 0;
//}