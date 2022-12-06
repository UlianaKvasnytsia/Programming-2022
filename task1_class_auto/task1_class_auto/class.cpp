/*��������� ���� ��������� (�����, ����, ����, �� �������). ����������� �������� ������������ �� 
������ ������� �� ��������� ���� �����, � ����� ������������� ��������� ��������/��������� �� ��������� ���������
(�� ����� �����). ������� � ����� ����� ��'���� ����� ����. �������� � ���� �������� �������� �������, �� �������
���� ������ � ����� ���. ��������� ������� ��������� ����� �����. ������� ���������� ��������. */

/* �� ��������� ��������� (�� ����� �����). 
������� � ����� ����� ��'���� ����� ����. 
�������� � ���� �������� �������� �������, �� ������� ���� ������ � ����� ���. 
��������� ������� ��������� ����� �����. 
������� ���������� ��������. */

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
