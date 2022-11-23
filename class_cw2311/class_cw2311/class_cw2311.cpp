//
#include <iostream>
#include <string>
using namespace std;
class Car {
private:
	int price;
	string name;
	string color;
public:
	Car() : price(0), name(" "), color(" ") { }
	Car(int p, string n, string c): price(p), name(n), color(c) {}
	int GetPrice() {
		return price;
	}
	string GetName() {
		return name;
	}
	string GetColor() {
		return color;
	}
	void SetPrice(int newprice) {
		price = newprice;
	}
	void input() {
		cout << "---enter price---" << endl;
		cin >> price;
		cout << "---enter a name---" << endl;
		cin>>name;
		cout << "---enter a color---" << endl;
		cin>> color;
	}
	void print() {
		cout << "Price is -- " << price << endl;
		cout << "Name is -- " << name<< endl;
		cout << "Color is -- " << color << endl;
	}
};



int main() {
	Car car1;
	Car car2(1000, "Opel", "red");
	Car car;
	int m;
	cout << "-----enter the quantity" << endl;
	cin >> m;
	Car* array = new Car[m];
	array[0] = car1;
	array[1] = car2;
	for (int i = 2; i < m; i++) {
		array[i].input();
	}
	cout << "-----enter a color-----" << endl;
	string color;
	cin >> color;
	for (int i = 0; i < m; i++) {
		if (array[i].GetColor() == color) array[i].print();
	}
	cout << "-----enter a name-----" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < m; i++) {
		if (array[i].GetName() == name) array[i].print();
	}
	int price;
	cout << "-----enter a price-----" << endl;
	cin >> price;
	for (int i = 0; i < m; i++) {
		if (array[i].GetPrice() == price) array[i].GetPrice();
	}
	int newprice;
	cout << "---reduced price for gold autos---" << endl;
	for (int i = 0; i < m; i++) {
		if (array[i].GetColor() == "gold") {
			array[i].SetPrice(array[i].GetPrice() * 0.9);
			array[i].print();
		}
	}
	return 0;
}