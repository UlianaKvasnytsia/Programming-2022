///* розробити клас для представлення навчальної дисципліни з полями - назва та вид коетролю (екзамен, залік). до класу додати
//конструктори, переантажити оператори введеня-виведенняб оператор менше (порівняння за назвою) та інші необхідні методи.
//утворити масив з 6 дисциплін та ввести дані про 3 з консолі, створити три за допомогою конструкторів і додати їх до цього масиву.
//вивести на консоль посортований за алфавітом перелік дисциплін. для кожного виду контролю порахувати кількість дисциплін та 
//вивести ці дані на консоль. ввести назву дисципліни і якщо така є - замінити вид контролю на екзамен, якщо немає - вивести повідомлення*/
//
//#include <iostream>
//using namespace std;
//class Subject {
//private:
//	string name;
//	string type;
//public:
//	Subject(): name(""), type(""){}
//	Subject(string n, string t): name(n), type(t){}
//	Subject(string n): name(n), type("exam"){}
//
//	friend istream& operator >>(istream& is, Subject& sub) {
//		is >> sub.name >> sub.type;
//		return is;
//	}
//	friend ostream& operator<<(ostream& os, const Subject& sub) {
//		os << sub.name << " " << sub.type << endl;
//		return os;
//	}
//	string getType() {
//		return type;
//	}
//	string getName() {
//		return name;
//	}
//	string setType(string newname) {
//		type = newname;
//		return type;
//	}
//	bool operator<(const Subject& sub) const {
//		return name < sub.name;
//	}
//};
//void sorting(Subject* arr, int n) {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n - i - 1; j++)
//			if (arr[j+1] < arr[j]) swap(arr[j], arr[j + 1]);
//}
//
//int main() {
//	const int n = 6;
//	Subject arr[n];
//	cout << "enter name and type" << endl;
//	for (int i = 0; i < 3; i++)
//		cin >> arr[i];
//	arr[3] = Subject("ooei");
//	arr[4] = Subject("programming");
//	arr[5] = Subject("algebra", "zalik");
//	sorting(arr, n);
//	int e = 0, z = 0;
//	cout << endl << endl;
//	for (int i = 0; i < n; i++){
//		cout << arr[i];
//		if (arr[i].getType() == "zalik") z++;
//		if (arr[i].getType() == "exam") e++;
//	}
//	cout <<endl<< "there are " << e << " exams and " << z << " zalikiv" << endl;
//	string username;
//	cout << endl << "enter the name of subject" << endl;
//	cin >> username;
//	bool k = false;
//	for (int i = 0; i < n; i++) {
//		if (arr[i].getName() == username) {
//			arr[i].setType("exam");
//			cout << arr[i] << endl;
//			k = true;
//		}
//	} if (!k) cout << "no subject found" << endl;
//	return 0;
//}