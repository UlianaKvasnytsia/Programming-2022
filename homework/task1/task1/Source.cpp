//18.  Знайти суму  цифр введеного трьохзначного числа
#include <iostream>
using namespace std;
int main() {
	int a;
	cout << "Enter a number" << endl;
	cin >> a;
	cout << a / 100 + a % 10 + a % 100 / 10;
	return 0;
}