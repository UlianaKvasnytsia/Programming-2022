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


//7
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double b, g;
  cout << "enter beta and gamma "<<endl;
  cin >> b >> g;
  double pi = 2 * asin(1.0);
  cout << (b + pow(sin(pow(pi, 4)), 2)) / (cos(2) + abs(1 / tan(g)));
  return 0;
}


//15. За введеним номером місяця року, вивести його назву
#include <iostream>
using namespace std;
int main() {
	int a;
	cout << "Введіть номер місяця" << endl;
	cin >> a;
	switch(a){
	case 1: cout << "january" << endl; break;
	case 2: cout << "february" << endl; break;
	case 3: cout << "march" << endl; break;
	case 4: cout << "april" << endl; break;
	case 5: cout << "may" << endl; break;
	case 6: cout << "june" << endl; break;
	case 7: cout << "july" << endl; break;
	case 8: cout << "august" << endl; break;
	case 9: cout << "september" << endl; break;
	case 10: cout << "october" << endl; break;
	case 11: cout << "november" << endl; break;
	case 12: cout << "december" << endl; break;
	default: cout << "invalid month number";
	}

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
	else if ((month == 4 && day >= 20 && day <= 30) || (month == 5 && day >= 1 && day <= 20)) cout << "it's taurus";
	else if ((month == 5 && day >= 21 && day <= 31) || (month == 6 && day >= 1 && day <= 20)) cout << "it's gemini";
	else if ((month == 6 && day >= 21 && day <= 30) || (month == 7 && day >= 1 && day <= 22)) cout << "it's cancer";
	else if ((month == 7 && day >= 23 && day <= 31) || (month == 8 && day >= 1 && day <= 22)) cout << "it's leo";
	else if ((month == 8 && day >= 23 && day <= 31) || (month == 9 && day >= 1 && day <= 22)) cout << "it's virgo";
	else if ((month == 9 && day >= 23 && day <= 30) || (month == 10 && day >= 1 && day <= 22)) cout << "it's libra";
	else if ((month == 10 && day >= 23 && day <= 31) || (month == 11 && day >= 1 && day <= 21)) cout << "it's scorpio";
	else if ((month == 11 && day >= 22 && day <= 30) || (month == 12 && day >= 1 && day <= 21)) cout << "it's sagittarius";
	else if ((month == 12 && day >= 22 && day <= 31) || (month == 1 && day >= 1 && day <= 19)) cout << "it's capricorn";
	else if ((month == 1 && day >= 20 && day <= 31) || (month == 2 && day >= 1 && day <= 18)) cout << "it's aquarius";
	else if ((month == 2 && day >= 19 && day <= 29) || (month == 3 && day >= 1 && day <= 20)) cout << "it's pisces";
	else cout<<"invalid data";
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
	cout << "arithmetic mean " << (a + b) / 2.0 << endl;
	cout << "geometric mean " << sqrt(a * b) << endl;

	return 0;

}

//2
#include <iostream>
using namespace std;
int main() {
	int h, m, s, f;
	//положення годинникової стрілки міняється кожні 2 хв
	cout << "Enter hours, minutes and seconds" << endl;
	cin >> h >> m >> s;
	if ((h >= 12 || h < 0) || (m < 0 || m >= 60) || (s < 0 || s >= 60)) cout << "data is incorrect";
	else {
		cout << "f = " << (h * 60 + m) / 2 << endl;
	}

	return 0;

}
