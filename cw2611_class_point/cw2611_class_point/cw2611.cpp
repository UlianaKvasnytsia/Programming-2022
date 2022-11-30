/*Визначити тип коло на площині (коло - це координати центру та радіус). Написати методи/конструктори, перевантажити оператори
порівняння, визначити методи обчислення площі круга, довжини кола, метод перевірки перетину двох кіл. Ввести дані про 10 кіл.
Посортувати їх, використовуючи відповідний оператор порівняння, у поядку спадання площ. Порахувати скільки кіл перетинаються з заданим
коломю Обчислити довжини тих кіл, що лкжпть у першій чверті координатної площини*/

#include <iostream>
#include <fstream>
using namespace std;
struct Point {
	int x;
	int y;
};

istream& operator >>(istream& is, Point& point) {
	//cout << "enter x" << endl;
	is >> point.x;

	//cout << "enter y" << endl;
	is >> point.y;

	return is;
}
ostream& operator <<(ostream& os, Point& point) {
	os << "x="<<point.x << endl;
	os << "y="<<point.y << endl;

	return os;
}

class Circle {
private:
	Point center;
	int radius;
public:
	Circle(): center(), radius (0){}
	Circle(Point _center, int _radius): center (_center), radius (_radius){}
	Circle (const Circle &circle): center(circle.center), radius(circle.radius){}

	friend istream & operator >>(istream& is,Circle& circle){
		//cout << "enter radius" << endl;
		is >> circle.radius;
		
		//cout << "enter center" << endl;
		is >> circle.center;
		return is;
	}

	friend ostream& operator <<(ostream& os, Circle& circle) {
		os << "radius = "<<circle.radius <<endl;
		os << "center"<< endl << circle.center << endl;
		return os;
		
	}

};


int main() {
	Circle circle;
	//cout << "enter circle data" << endl;
	//cin >> circle; //operator >> (cin, circle)
	//cout << circle;
	ifstream ifs;
	ofstream result("result.txt");
	ifs.open("data.txt");
	int size;
	ifs >> size;
	Circle* arr = new Circle[size];
	for (int i = 0; i < size; i++) {
		ifs >> circle;
		result << circle;
	}
	ifs.close();
	result.close();
	return 0;
}