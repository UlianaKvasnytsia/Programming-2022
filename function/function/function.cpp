//1.	Задано три натуральних числа. Визначити їхній найбільший спільний дільник.
#include <iostream>
using namespace std;
int func(int a, int b, int c) {
	int dil=1;
	for (int i = 1; i <=a; i++) {
		if (a % i == 0 && b % i == 0 && c%i==0) dil = i;
	}
	return dil;
}

int main() {
	int a, b, c;             //int a=10, b=15, c=20;
	cin >> a >> b >> c;      //
	int dil=func(a,b,c);
	cout << dil;
	return 0;
}