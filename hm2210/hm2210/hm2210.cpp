#include <iostream>
using namespace std;
int main() {
	double x, y, sum, a, b, h, e=1.0e-5, pop;
	int n;
	cout << "ener a, b, h = ";
	cin >> a >> b >> h;
	cout << "\tX\t\tS\t\ty\t\tPohybka" << endl;
	for (x = a; x < b+h/2; x += h) {
		sum = 0;
		n = 1;
		double p = n * (n + 2) * pow(x, n);
		do {
			sum += p;
			n++;
			pop = p;
			p = n * (n + 2) * pow(x, n);
		} while (abs(p - pop) > e);
		y = x * (3 - x) / pow(1 - x, 3);
		cout << "\t" << x << "\t\t" << sum << "\t\t" << y << "\t\t" << abs((sum - y) / y)*100 <<" n= " << n << endl;
	}


	return 0;
}