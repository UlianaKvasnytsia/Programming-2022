///* розробити клас для педставлення монітора з такими полями: бренд, довжина діагоналі, ціна. до класу додати конструктори,
//перевантажити оператори введення-виведення, оператор для порівняння за ціноою та інші необхідні методи.
//утоврити масив із шести моніторів і ввести з консолі дані про три монітори та створити три нові монітори за допомогою різних
//видів конструкторів і додати їх до масиву. вивести на консоль масив посортований за ціною. запропонувати користувачеві вибрати 
//монітори за такими фільтрами: бренд (вивести на консоль перелік брендів з масиву) та довжиною діагоналі (звпропонувати ввести число
//що відповідає діагоналі). після введення даних вивести доступні монітори за заданими параметрами
//*/
//
//#include <iostream>
//using namespace std;
//class Display {
//private:
//	string brand;
//	double size;
//	int price;
//public:
//	Display() : brand(""), size(0), price(0) {}
//	Display(string b, double s, int p) :brand(b), size(s), price(p) {}
//	Display(double s, int p) :brand("no brand"), size(s), price(p) {}
//	Display(const Display& D) : brand(D.brand), size(D.size), price(D.price) {}
//
//	friend istream& operator >>(istream& is, Display& d) {
//		is >> d.brand >> d.size >> d.price;
//		return is;
//	}
//	friend ostream& operator <<(ostream& os, const Display& d) {
//		cout << d.brand << ' ' << d.size << ' ' << d.price << endl;
//		return os;
//	}
//	bool operator<(const Display& d) const{
//		return price < d.price;
//	}
//	string getBrand() { return brand;}
//	int getPrice() { return price;}
//	double getSize() { return size;}
//};
//void sorting(Display* arr, int n) {
//	for (int i = 0; i < n; i++) 
//		for (int j = 0; j < n - i - 1; j++) 
//			if (arr[j] < arr[j + 1]) swap(arr[j], arr[j + 1]);	
//}
//
//int main() {
//	const int n = 6;
//	Display arr[n];
//	cout << "enter data about 3 displays. brand, size and price" << endl;
//	for (int i = 0; i < 3; i++)
//		cin >> arr[i];
//	arr[3] = Display();
//	arr[4] = Display("sony", 23, 12600);
//	arr[5] = Display(29.5, 28645);
//	sorting(arr, n);
//	cout <<endl<< "array sorted by price:" << endl;
//	for (int i = 0; i < n; i++)
//		cout << arr[i];
//	string userbrand;
//	int usersize;
//	cout << endl << "choosing a suitable display" << endl << "available brands are: " << endl;
//	string brand[n];
//	int s = 0;
//
//	for (int i = 0; i < n; i++) {
//		string name = arr[i].getBrand();
//		bool yes=false;
//		for (int j = 0; j < s; j++){
//			if (brand[j] == name) { yes = true; break; }
//			
//		} if (!yes) brand[s++] = name;
//	}
//	for (int i = 0; i < s; i++)
//		cout << brand[i] << endl;
//
//	cout <<endl<< "enter a brand and a size of display:" << endl;
//	cin >> userbrand >> usersize;
//	cout << endl<<"what we found for you:" << endl;
//	for (int i = 0; i < n; i++) {
//		if (arr[i].getBrand() == userbrand && arr[i].getSize() == usersize) cout << arr[i] << endl;
//	}
//	return 0;
//}
