#include <iostream>
using namespace std;
class Product {
private:
	string name;
	int price;
public:
	Product() : name(), price(0) {}
	Product(string n) : name(n), price(rand()) {}

	int getPrice() { return price; }
	string getName() { return name; }
	friend ostream& operator<<(ostream& os, const Product& prod) {
		os << "name: " << prod.name << endl << "price: " << prod.price << endl << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Product& prod) {
		is >> prod.name >> prod.price;
		return is;
	}
};
class Cart {
private:
	Product* arr;
	int* quantity;
	int current;

public:
	Cart() : current(0) {
		arr = new Product[100];
		quantity = new int[100];
	}
	void additem(Product prod, int quant) {
		arr[current] = prod;
		quantity[current] = quant;
		current++;
	}

	void deleteitem(Product prod, int q) {
		for (int i = 0; arr[i].getName() != prod.getName(); i++) {
			if (quantity[i] > q) {
				quantity[i] -= q;
			}
			else {
				for (int j = i; j < current - 1; j++) {
					arr[j] = arr[j + 1];
					quantity[j] = quantity[j + 1];
				}
				current--;
			}
		}
	}

};

int main() {


	return 0;
}
