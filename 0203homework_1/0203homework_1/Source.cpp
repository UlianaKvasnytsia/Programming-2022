#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Phone {
protected:
	string name, firm;
	int price;
public:
	Phone() { price = 0; }
	int getPrice() {
		return price;
	}
	virtual void input(istream& is) {
		is >> name >> firm >> price;
	}
	friend istream& operator>>(istream& is, Phone& ph) {
		ph.input(is);
		return is;
	}
	virtual void output(ostream& os)const {
		os << "name: " << name << endl << "firm: " << firm << endl << "price: " << price << endl;
	}
	friend ostream& operator<<(ostream& os, const Phone& ph) {
		ph.output(os);
		return os;
	}
	bool operator<(Phone& ph2) {
		return price < ph2.price;
	}
	virtual bool hasAutoAnswer() = 0;
};
class MobilePhone: public Phone {
private:
	string color;
	int ram;
public:
	MobilePhone():Phone(), ram(0) {}
	void input(istream& is) {
		Phone::input(is);
		is >> color >> ram;
	}
	void output(ostream& os)const {
		Phone::output(os);
		os << "color: " << color << endl << "ram: " << ram << endl;
	}
	bool hasAutoAnswer() {
		return false;
	};
};

class RadioPhone : public Phone {
private:
	int radius;
	string autoanswer; //yes or no
public:
	RadioPhone():Phone(),radius(0) {}
	void input(istream& is) {
		Phone::input(is);
		is >> radius >> autoanswer;
	}
	void output(ostream& os)const {
		Phone::output(os);
		os << "radius: " << radius << endl << "autoanswer: " << autoanswer << endl;
	}
	bool hasAutoAnswer() {
		return (autoanswer == "yes");
	}
};


void sort(vector <Phone*> &arr, size_t n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j + 1]->getPrice() < arr[j]->getPrice()) swap(arr[j + 1], arr[j]);
}


int main() {
	vector <Phone*> all;
	ifstream file("firm1.txt");
	while (!file.eof()) {
		char type;
		Phone* temp;
		file >> type;
		if (type == 'm') temp = new MobilePhone;
		else temp = new RadioPhone;
		temp->input(file);
		all.push_back(temp);
	}
	ifstream file2("firm2.txt");
	while (!file2.eof()) {
		char type;
		Phone* temp;
		file2 >> type;
		if (type == 'm') temp = new MobilePhone;
		else temp = new RadioPhone;
		temp->input(file2);
		all.push_back(temp);
	}
	file.close();
	file2.close();
	ofstream result("result.txt");
	result << endl << "sorted by price + total : " << endl;
	sort(all, all.size());
	int sum = 0;
	for (int i = 0; i < all.size(); i++) {
		all[i]->output(result);
		sum += all[i]->getPrice();
		result << endl;
	}
	result << "total income: " << sum << endl<<endl;

	result << "radiophones with an autoanswer: "<<endl;
	for (int i = 0; i < all.size(); i++) {
		if (all[i]->hasAutoAnswer()) {
			/*all[i]->output(cout); 
			cout << endl;*/
			result<<*all[i]<<endl;
		}
	}
	result.close();
	return 0;
}