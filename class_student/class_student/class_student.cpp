/*клас студент: ім'я, назва групи, айді
методи: конструктори, гкти і сети, інпут і прінт

ввести дані про н кількість студентів. видрукувати студентів вказаної групи
видрукувати студентів з вказаним ім''ям
змінити айді стулента anme1 на нове new
видрукувати студентів, посортованими за айдішкою*/


#include <iostream>
#include <string>
using namespace std;
class Student {
private:
	string name;
	string group;
	int id;
public:
	Student() :  name(" "), group(" "), id(0) { }
	Student( string n, string g, int idd) : name(n), group(g), id(idd){}
	int GetId() {
		return id;
	}
	string GetName() {
		return name;
	}
	string GetGroup() {
		return group;
	}
	void SetId(int new_id) {
		id = new_id;
	}
	void input() {
		cout << "-- enter a name --" << endl;
		cin >> name;
		cout << "-- enter a group --" << endl;
		cin >> group;
		cout << "-- enter id --" << endl;
		cin >> id;
	}
	void output() {
		cout << "name is -- " << name << endl;
		cout << "group is -- " << group << endl;
		cout << "id id -- " << id << endl;
	}
};
//sorting by id
void sorting(Student* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j].GetId() > arr[j + 1].GetId()) swap(arr[j], arr[j + 1]);
		}
	}
}

int main() {
	int n;
	cout << "---- enter the number of students ----" << endl;
	cin >> n;
	Student* arr = new Student[n];
	for (int i = 0; i < n; i++) {
		arr[i].input();
	}
	cout << "--- enter a group ---" << endl;
	string group;
	cin >> group;
	for (int i = 0; i < n; i++) {
		if (arr[i].GetGroup() == group) arr[i].output();
	}
	cout << "--- enter a name ---" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < n; i++) {
		if (arr[i].GetName() == name) arr[i].output();
	}
	int new_id;
	for (int i = 0; i < n; i++) {
		cout << "--- enter a new id ---" << endl;
		cin >> new_id;
		arr[i].SetId(new_id);
	}
	sorting(arr, n);
	cout << "--- students with new id ---" << endl;
	for (int i = 0; i < n; i++) {
		arr[i].output();
		cout << endl;
	}

	return 0;
}