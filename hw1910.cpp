//6. а) Задано натуральне число  , дійсні числа     . Отримати  , де  .

/*#include <iostream>
using namespace std;
int main() {
	int n;
	double a, b, h;
	cout << "Enter a and b" << endl;
	cin >> a >> b;
	cout << "Enter n" << endl;

	cin >> n;
	h = (b - a) / n;
	for (int i = 0; i <= n;i++) {
		cout << "Returning r "<< i << " = " <<a + i * h << endl;
	}
	return 0;
}*/



//Розглядається послідовність ...
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a;
	int n = 0;
	for (int i = 1; i <= 1000; i=i*2) {
		a = (pow(sin(3 * i + 5), 2)) - cos(i * i - 15);
		if (a < 0.25) n++;

	}
	cout << n;
	return 0;
}