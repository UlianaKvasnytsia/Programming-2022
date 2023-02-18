/* визначте функцію, яка обчислює кількість елементів масиву дійсних чисел, для яких виконується дана умова. Така функція приймає масив і
умову(вказівник на функцію). продемонструйте використання функції на звичайному масиві, наприклад обчисліть кількість додатніх елементів.
Задано натуральне н, дійсні а0, а1, ..., ан-1. Утворіть динамічний масив розміру н, завантажте в нього задані числа. Визначте, скільки 
елементів масиву налкжить проміжку -1,5;1,5, а скільки перевищують число 2,25.  Оголошення функції розташуйте в окремому файлі,
використайте заголовковий файл для оголошкння прототипу функції, використайте сторожі включення*/

//#include <iostream>
//using namespace std;
//
//int CountIf(double* arr, int n, bool(*pf)(double)) {
//	int k = 0;
//	for (int i = 0; i < n; i++)
//		if (pf(arr[i])) k++;
//	return k;
//}
//
//bool func1(double t) {
//	return t > 0;
//}
//bool func2(double t) {
//	return t >= -1.5 && t <= 1.5;
//}
//bool func3(double t) {
//	return t > 2.25;
//}
//
//
//int main() {
//	int n;
//	cout << "enter size of the array" << endl;
//	cin >> n;
//	double* arr = new double[n];
//	cout << "enter the elements of the array" << endl;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//	cout << "elements that fit the condition 1: " << CountIf(arr, n, func2) << endl;
//	cout << "number of elements greater than 2.25: " << CountIf(arr, n, func3) << endl;
//	return 0;
//}