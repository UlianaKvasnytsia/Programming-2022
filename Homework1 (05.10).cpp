//18. Знайти суму  цифр введеного трьохзначного числа
#include <iostream>
using namespace std;
int main() {
	int a;
	cout << "Enter a number" << endl;
	cin >> a;
	cout << a / 100 + a % 10 + a % 100 / 10;
	return 0;
}



//15. За введеним номером місяця року, вивести його назву
#include <iostream>
using namespace std;
int main() {
	int a;
	cout << "Введіть номер місяця" << endl;
	cin >> a;
	if (a == 1) cout << "january"<<endl;
	if (a == 2) cout << "february" << endl;
	if (a == 3) cout << "march" << endl;
	if (a == 4) cout << "april" << endl;
	if (a == 5) cout << "may" << endl;
	if (a == 6) cout << "june" << endl;
	if (a == 7) cout << "july" << endl;
	if (a == 8) cout << "august" << endl;
	if (a == 9) cout << "september" << endl;
	if (a == 10) cout << "october" << endl;
	if (a == 11) cout << "november" << endl;
	if (a == 12) cout << "december" << endl;
	if (a!=1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8 && a != 9 && a != 10 && a != 11 && a != 12) cout << "invalid month number" << endl;

	return 0;
}



//5.	Ввести x – дійсне число, обчислити значення виразу:
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int x;
	cout << "enter x" << endl;
	cin >> x;
	cout << pow(pow(x, 8) + pow(8, x), 0.125);

	return 0;

}



//13. За введеною датою Day, Month (цілі числа 1-31,1-12) вивести знак Зодіаку, для цієї дати.
#include <iostream>
using namespace std;
int main() {
	int day, month;
	cout << "Enter day and month" << endl;
	cin >> day >> month;
	if ((month == 3 && day >= 21 && day <= 31) || (month == 4 && day >= 1 && day <= 19)) cout << "it's aries"; 
	if ((month == 4 && day >= 20 && day <= 30) || (month == 5 && day >= 1 && day <= 20)) cout << "it's taurus";
	if ((month == 5 && day >= 21 && day <= 31) || (month == 6 && day >= 1 && day <= 20)) cout << "it's gemini";
	if ((month == 6 && day >= 21 && day <= 30) || (month == 7 && day >= 1 && day <= 22)) cout << "it's cancer";
	if ((month == 7 && day >= 23 && day <= 31) || (month == 8 && day >= 1 && day <= 22)) cout << "it's leo";
	if ((month == 8 && day >= 23 && day <= 31) || (month == 9 && day >= 1 && day <= 22)) cout << "it's virgo";
	if ((month == 9 && day >= 23 && day <= 30) || (month == 10 && day >= 1 && day <= 22)) cout << "it's libra";
	if ((month == 10 && day >= 23 && day <= 31) || (month == 11 && day >= 1 && day <= 21)) cout << "it's scorpio";
	if ((month == 11 && day >= 22 && day <= 30) || (month == 12 && day >= 1 && day <= 21)) cout << "it's sagittarius";
	if ((month == 12 && day >= 22 && day <= 31) || (month == 1 && day >= 1 && day <= 19)) cout << "it's capricorn";
	if ((month == 1 && day >= 20 && day <= 31) || (month == 2 && day >= 1 && day <= 18)) cout << "it's aquarius";
	if ((month == 2 && day >= 19 && day <= 28) || (month == 3 && day >= 1 && day <= 20)) cout << "it's pisces";
	return 0;
}


// 17. Обчислити середнє арифметичне, середнє геометричне двох заданих натуральних чисел.
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int a, b;
	cout << "enter two numbers" << endl;
	cin >> a >> b;
	cout << "arithmetic mean " << (a + b) / 2 << endl;
	cout << "geometric mean " << sqrt(a * b) << endl;

	return 0;

}
