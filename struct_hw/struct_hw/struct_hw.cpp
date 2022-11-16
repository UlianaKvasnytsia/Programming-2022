//6.Визначити структуру для представлення раціонального числа   (a, b  - цілі числа,  a< b) . 
//Визначити функції для арифметичних операторів (+, -, *, /), визначити функцію скорочення дробу. 
//Ввести масив раціональних чисел, обчислити їх суму, добуток, різницю, середнє арифметичне.

#include <iostream>
using namespace std;
struct Rational {
	int a;
	int b;
};
int dilnyk(int a, int b) {
	int dil = 1;
	for (int i = 1; i <= abs(a); i++) {
		if (a % i == 0 && b % i == 0) dil = i;
	}
	return dil;
}
void skoro(Rational& elem) {
	int c = dilnyk(elem.a, elem.b);
	if (c != 1) {
		elem.a /= c;
		elem.b /= c;
	}
}

void input(Rational &elem) {
	cout << "enter numerator and denominator" << endl;
	cin >> elem.a >> elem.b;
	skoro(elem);
}
void output(Rational &elem) {
	cout << elem.a << "/" << elem.b;
}
Rational Palus(const Rational &n, const Rational &m) {
	Rational sum;
	sum.a = n.a * m.b + n.b * m.a;
	sum.b = n.b * m.b;
	skoro(sum);
	return sum;
}
Rational Mns(const Rational& n, const Rational& m) {
	Rational diff;
	diff.a = n.a * m.b - n.b * m.a;
	diff.b = n.b * m.b;
	skoro(diff);
	return diff;
}
Rational Mltpl(const Rational& n, const Rational& m) {
	Rational mlt;
	mlt.a = n.a * m.a;
	mlt.b = n.b * m.b;
	skoro(mlt);
	return mlt;
}
Rational Dvsn(const Rational& n, const Rational& m) {
	Rational dvsn;
	dvsn.a = n.a * m.b;
	dvsn.b = n.b * m.a;
	skoro(dvsn);
	return dvsn;
}
Rational Avrg(const Rational& n, const Rational& m) {
	Rational avrg;
	avrg=Palus(n, m);
	avrg.b *= 2;
	skoro(avrg);
	return avrg;

}
int main() {
	Rational elem1={2,3};
	Rational elem2 = { 2,3 };
	input(elem1);
	input(elem2);
	cout << "sum is " << endl;
	Rational sum = Palus(elem1, elem2);
	output(sum);
	cout <<endl<<"difference is "<< endl;
	Rational diff = Mns(elem1, elem2);
	output(diff);
	cout <<endl<<"result of multiply is "<< endl;
	Rational mlt = Mltpl(elem1, elem2);
	output(mlt);
	cout << endl << "result of division is " << endl;
	Rational dvsn = Dvsn(elem1, elem2);
	output(dvsn);
	cout << endl << "the average is " << endl;
	Rational avrg = Avrg(elem1, elem2);
	output(avrg);
	cout << endl;

	int n = 5;
	Rational* arr = new Rational[n];
	cout << "enter an array " << endl;
	for (int i = 0; i < n; i++) {
		input(arr[i]);
	}
	Rational summ = { 0,1 };
	for (int i = 0; i < n; i++) {
		summ=Palus(summ,arr[i]);
	} 
	cout <<endl<< "the sum is: " << endl;
	output(summ);
	Rational dobb = { 1,1 };
	for (int i = 0; i < n; i++) {
		dobb = Mltpl(dobb, arr[i]);
	} 
	cout << endl<< "the result of multiply is " << endl;
	output(dobb);
	Rational avr = { 1,n };
	avr = Mltpl(summ, avr);
	cout <<endl<< "the average is " << endl;
	output(avr);
	return 0;
}