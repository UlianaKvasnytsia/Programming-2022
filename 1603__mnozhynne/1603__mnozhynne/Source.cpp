#include <iostream>
#include <fstream>
using namespace std;

class Transport {
protected:
	string name;
	int volume;
public:
	virtual void input(istream& is) {
		is >> name >> volume;
	}
	friend istream& operator>>(istream& is, Transport& t) {
		t.input(is);
		return is;
	}
	virtual void output(ostream& os)const {
		os << "name: " << name << endl << "volume: " << volume << endl;
	}
	friend ostream& operator<<(ostream& os, const Transport& t) {
		t.output(os);
		return os;
	}
	string getName() {
		return name;
	}
	int getVolume() {
		return volume;
	}
};
class Water: virtual public Transport {
protected:
	string type;
	int maxSpeedWater;
public:
	void input(istream& is) {
		Transport::input(is);
		is >> type >> maxSpeedWater;
	}
	void output(ostream& os)const {
		Transport::output(os);
		os << "type: " << type << endl << "max speed: " << maxSpeedWater << endl;
	}
};
class Ground: virtual public Transport {
protected:
	int amount;
	int maxSpeed;
public:
	void input(istream& is) {
		Transport::input(is);
		is >> amount >> maxSpeed;
	}
	void output(ostream& os)const {
		Transport::output(os);
		os << "max people: " << amount << endl << "max speed: " << maxSpeed << endl;
	}
};
class Amphi: public Water, public Ground {
private:
	int maxHoursW;
	int maxHours;
public:
	void input(istream& is) {
		Transport::input(is);
		is >>type>>maxSpeedWater>>amount>>maxSpeed>> maxHoursW>>maxHours;
	}
	void output(ostream& os)const {
		Transport::output(os);
		os << "type: " << type << "\nmax speed: " << maxSpeedWater <<"\nmax people: " << amount <<"\nmax speed: " << maxSpeed << "\nmax hours on water: " << maxHoursW <<"\nmax hours on ground: " << maxHours << endl;
	}
};
void sort(Transport** arr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j]->getName() > arr[j + 1]->getName()) swap(arr[j], arr[j + 1]);
}
int main() {
	ifstream file("data.txt");
	int n;
	file >> n;
	Transport** arr = new Transport * [n];
	int type;
	int maxVol = INT_MIN;
	int minVol = INT_MAX;
	for (int i = 0; i < n; i++) {
		file >> type;
		switch (type) {
		case 1: arr[i] = new Water; break;
		case 2: arr[i] = new Ground; break;
		case 3: arr[i] = new Amphi; break;
		default:
			break;
		}
		file >> *arr[i];
		if (arr[i]->getVolume() < minVol) minVol = arr[i]->getVolume();
		if (arr[i]->getVolume() > maxVol) maxVol = arr[i]->getVolume();
	}
	sort(arr, n);
	cout << "sorted by name: " << endl << endl;
	for (int i = 0; i < n; i++)
		cout << *arr[i] << endl;

	cout << "------------------\nmaximum volume: \n";
	for (int i = 0; i < n; i++)
		if(arr[i]->getVolume()==maxVol)
		cout << *arr[i] << endl;
	cout << "minimum volume: \n";
	for (int i = 0; i < n; i++)
		if (arr[i]->getVolume() == minVol)
			cout << *arr[i] << endl;
	cout << "-----------------------\nwater transport: \n";
	for (int i = 0; i < n; i++) {
		if (typeid(*arr[i]) == typeid(Water))
			cout << *arr[i] << endl;
	}
	cout << "\namphi transport: \n";
	for (int i = 0; i < n; i++) {
		if (typeid(*arr[i]) == typeid(Amphi))
			cout << *arr[i] << endl;
	}
	return 0;
}