/*Визначити клас Автомобіль (марка, ціна, колір, рік випуску). Передбачити необхідні конструктори та 
методи доступу до приватних полів класу, а також перевантажити оператори введення/виведення та оператори порівняння
(як метод класу). Зчитати з файлу масив об'єктів цього типу. Записати у файл автомобілі заданого кольору, рік випуску
яких попадає у задані межі. Обчислити кількість автомобілів кожної марки. Вивести найдорожчі автомобілі. */

/* та оператори порівняння (як метод класу). 
Зчитати з файлу масив об'єктів цього типу. 
Записати у файл автомобілі заданого кольору, рік випуску яких попадає у задані межі. 
Обчислити кількість автомобілів кожної марки. 
Вивести найдорожчі автомобілі. */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Auto {
private:
	string mark;
	int price;
	string color;
	int year;
public:
	Auto(): mark(" "), price(0), color(" "),year(0){}
	Auto(string m, int p, string c, int y): mark(m), price(p),color(c), year(y){}

	friend istream& operator>>(istream& is, Auto& a) {
		is >> a.mark >> a.price >> a.color >> a.year;
		return is;
	}
	friend ostream& operator<<(ostream& os, Auto& a) {
		os << "mark " << a.mark << " price " << a.price << " color " << a.color << " year " << a.year<<endl;
		return os;
	}

};



int main() {


	return 0;
}
