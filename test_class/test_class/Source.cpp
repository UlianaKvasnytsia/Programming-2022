/*�������� ���� ��� ������������� ����. г��� ���������������: ����������, ������.
� ���� ��������� ����������� �� ������������� �� ����������� � �����������, ������ ��������, ���������, 
�����, ���� ������� ���������� ���� �� �����, ���� ������� �� �����. ������ ��� ��� 10 ����.  
���������� ������� ���������� ��� ����. ������� ���������� ���������. 
������� ����� ���� � ��������� ����������, ����������� �� ����, � ���� ���� ����������� ����� '�'*/



#include <iostream>
using namespace std;
class River {
private:
	string name;
	double length;
public:
	River() : name(""), length(0){}
	River(string n, double l): name(n),length(l){}
	string GetName() {
		return name;
	}
	double GetLength() {
		return length;
	}

	friend istream& operator>>(istream& is, River& r) {
		is >> r.name >> r.length;
		return is;
	}
	friend ostream& operator<<(ostream& os, River& r) {
		os << r.name << " " << r.length << "km" << endl;
		return os;
	}
};



int main() {
	const int n = 10;
	River arr[n];
	cout << "enter river's name and length (10 times)" << endl;
	double sum = 0, maxlength = INT_MIN;
	string maxl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i].GetLength() > maxlength) {
			maxlength = arr[i].GetLength(); maxl = arr[i].GetName();
		}
		sum += arr[i].GetLength();
	}
	cout << "total length: " << sum << endl;
	cout << "river with maximum length: " << endl << maxl << " " << maxlength << endl;
	cout << endl << "rivers with letter 'D'" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].GetName().length(); j++) {
			if (arr[i].GetName()[j] == 'd'|| arr[i].GetName()[j] == 'D') {
				cout << arr[i]; break;
			}
		}
	}

	return 0;
}