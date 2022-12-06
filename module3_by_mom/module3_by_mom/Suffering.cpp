/* створити клас Автомобіль, що містить марку авто, номер, рік випуску та колір. передбачити конструктор за замовчуванням,
з параметрами, копіювання, методи доступу ло приватних полів (за потреби), метод перевірки коректності номеру авто (2 букви
та 5 цифр). перевантажити оператори введеня-виведення, оператор < для порівняння ща роком випуску. зчитати з текстового
файлу дані про кілька авто та записати у масив авто лише з коректним номером, розробити функції
виведення автомобілів заданої марки, визначення марки, яка зустрічається найчастіше в масиві, виведення інформації про всі
автомобілі заданого кольору, рік яких попадає у задані межі*/


/* 
зчитати з текстового файлу дані про кілька авто та записати у масив авто лише з коректним номером, 
розробити функції

- визначення марки, яка зустрічається найчастіше в масиві, 
*/

#include <iostream>
#include <fstream>
using namespace std;
class Auto {
private:
	string mark, number;
	int year;
	string color;
public:
	Auto(): mark(""), number(""), year(0), color(""){}
	Auto(string m, string n, int y, string c): mark(m), number(n), year(y), color(c){}
	Auto(const Auto &a): mark(a.mark), number(a.number), year(a.year), color(a.color){}
	string GetMark() {
		return mark;
	}
	int GetYear() {
		return year;
	}
	string GetColor() {
		return color;
	}
	bool GetCorrectNumber() {
		bool k = true;
		bool p = false;
		for (int i = 0; i < 2; i++) {
			if (number[i] >= 'A' && number[i] <= 'Z' || number[i] >= 'a' && number[i] <= 'z') k = true;
			else {
				k = false; break;
			}
			
		}
		if (k) {
			for (int i = 2; i < 7; i++) {
				if (number[i] >= '0' && number[i] <= '9') k = true;
				else {
					k = false; break;
				}
				
			}
		}
		if (k) {
			if (number.length() == 7) k = true;
			else {
				k = false;
			}
		}
		return k;
	}

	friend istream& operator >>(istream& is, Auto& a) {
		is >> a.mark >> a.number >> a.year >> a.color;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Auto& a) {
		os << a.mark << " " << a.number << " " << a.year << " " << a.color << endl;
		return os;
	}
	bool operator <(const Auto& a) const {
		 return year < a.year;
	}
};



int main() {
	Auto au;
	ifstream ifs;
	ifs.open("data.txt");

	const int n = 6;
	Auto arr[n];
	Auto correct[n];
	for (int i = 0; i < n; i++) {
		 ifs >> au;
		 arr[i] = au;
	}
	
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].GetCorrectNumber()) { correct[j] = arr[i]; j++; }
	}

	int a, b;
	string c;
	cout << "enter two years " << endl;
	cin >> a >> b;
	cout << "enter a color" << endl;
	cin >> c;
	for (int i = 0; i < j; i++) {
		if (correct[i].GetYear() >= a && correct[i].GetYear() <= b && correct[i].GetColor() == c)
			cout << correct[i];
	}


	cout << "enter a mark" << endl;
	string s;
	cin >> s;

	for (int i = 0; i < j; i++) {
		if (correct[i].GetMark() == s) cout << correct[i];
	}

	//popular mark


	ifs.close();
	return 0;
}