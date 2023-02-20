#include <iostream>
using namespace std;

class Student {
private:
	string name;
	int id;
	string spec;
public:
	Student(string n) : name(n), id(rand()), spec(" ") {}
	Student() :name(""), id(0), spec("") {}
	Student(string n, string s) : name(n), id(rand()), spec(s) {}
	Student(const Student& st) : name(st.name), id(st.id), spec(st.spec) {}

	string getName() {
		return name;
	}
	string getSpec() {
		return spec;
	}
	int getId() {
		return id;
	}
	friend istream& operator>>(istream& is, Student& st) {
		is >> st.name >> st.id >> st.spec;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Student& st) {
		os << "name: " << st.name << endl << "id: " << st.id << endl << "speciality: " << st.spec << endl;
		return os;
	}
};

class Course {
private:
	string coname;
	int coid;
	string cospec;
public:
	Course() :coname(""), coid(rand()), cospec("") {}
	Course(string n, string s) : coname(n), coid(rand()), cospec(s) {}
	Course(const Course& c) : coname(c.coname), coid(c.coid), cospec(c.cospec) {}

	int getCoId() {
		return coid;
	}
	string getCoName() {
		return coname;
	}
	string getCoSpec() {
		return cospec;
	}
	friend istream& operator>>(istream& is, Course& c) {
		is >> c.coname >> c.coid >> c.cospec;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Course& c) {
		os << "course name: " << c.coname << endl << "course id: " << c.coid << endl << "course speciality: " << c.cospec << endl;
		return os;
	}
};

class Uni {
private:
	string uniname;
	string adress;
	Student* sarr;
	Course* carr;
	int scount;
	int ccount;
public:
	Uni() : scount(0), ccount(0) {
		sarr = new Student[100];
		carr = new Course[100];
	}
	Uni(string un, string a, int s, int c) : uniname(un), adress(a), scount(0), ccount(0) {
		sarr = new Student[s];
		carr = new Course[c];
	}
	void addStudent() {
		cout << "enter name, id and speciality: " << endl;
		cin >> sarr[scount];
		scount++;
	}
	void addCourse() {
		cout << "enter course name, id and speciality: " << endl;
		cin >> carr[ccount];
		ccount++;
	}
	void removeStudent() {
		cout << "enter an id: " << endl;
		int n;
		cin >> n;
		int i = 0;
		for (i; i < 100; i++) {
			if (n == sarr[i].getId()) break;
		}
		for (int j = i; j < 99; j++)
			sarr[j] = sarr[j + 1];
		scount--;
	}
	void removeCourse() {
		cout << "enter an id: " << endl;
		int n;
		cin >> n;
		int i = 0;
		for (i; i < 100; i++)
			if (n == carr[i].getCoId()) break;
		for (int j = i; j < 99; j++)
			carr[j] = carr[j + 1];
		ccount--;
	}
	void allStudents() {
		for (int i = 0; sarr[i].getName() != ""; i++)
			cout << sarr[i];
	}
	void allCourses() {
		for (int i = 0; carr[i].getCoName() != ""; i++)
			cout << carr[i];
	}
	void courseBySpec() {
		cout << "enter a course id: " << endl;
		int id;
		cin >> id;
		Course sear;
		for (int i = 0; i < 100; i++) {
			if (carr[i].getCoId() == id) sear = carr[i];
		}
		for (int i = 0; i < 100; i++) {
			if (sarr[i].getSpec() == sear.getCoSpec()) cout << sarr[i] << endl;
		}
	}
	void studentsCourses() {
		cout << "enter student`s id: " << endl;
		int id;
		cin >> id;
		Student sear;
		for (int i = 0; i < 100; i++) {
			if (sarr[i].getId() == id) sear = sarr[i];
		}
		for (int i = 0; i < 100; i++) {
			if (carr[i].getCoSpec() == sear.getSpec()) cout << carr[i];
		}
	}
};

int main() {
	cout << "enter uni name, adress, amount of students and courses: " << endl;
	string uniname, uniad;
	int students, courses;
	cin >> uniname >> uniad >> students >> courses;
	Uni uni;
	uni = Uni(uniname, uniad, students, courses);
	cout << "uni is created!" << endl;

	while (true) {
		int sw;
		cout << "1 - add student" << endl << "2 - remove student" << endl << "3 - add course" << endl << "4 - remove course" << endl << "5 - all students" << endl << "6 - all courses" << endl << "7 - view student's courses" << endl << "8 - view courses' students" << endl << "0 - exit" << endl;
		cin >> sw;
		if (sw == 0) break;
		switch (sw) {
		case 1: uni.addStudent(); break;
		case 2: uni.removeStudent(); break;
		case 3: uni.addCourse(); break;
		case 4: uni.removeCourse(); break;
		case 5: uni.allStudents(); break;
		case 6: uni.allCourses(); break;
		case 7: uni.studentsCourses(); break;
		case 8: uni.courseBySpec(); break;
		}
	}

	return 0;
}