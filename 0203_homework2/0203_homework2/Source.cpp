#include <iostream>
#include <fstream>
using namespace std;
class Note {
protected:
	string subject;
	int number;
public:
	Note() { number = 0, subject = ""; }
	int getNumber() {
		return number;
	}
	string getSubject() {
		return subject;
	}
	virtual void input(istream& is) {
		is >> number >> subject;
	}
	friend istream& operator>>(istream& is, Note& n) {
		n.input(is);
		return is;
	}
	virtual void output(ostream& os)const {
		os << "number: " << number << endl << "subject: " << subject << endl;
	}
	friend ostream& operator<<(ostream& os, const Note& n) {
		n.output(os);
		return os;
	}
	bool operator<(Note& n2) {
		if (subject == n2.subject)
			return number < n2.number;
		return subject < n2.subject;
	}
};
class PaperNote : public Note {
private:
	int size;
	string place;
public:
	PaperNote() :Note() { size = 0; place = ""; }
	void input(istream& is) {
		Note::input(is);
		is >> size >> place;
	}
	void output(ostream& os)const {
		Note::output(os);
		os << "size: " << size << endl << "place: " << place << endl;
	}
};
class ENote : public Note {
private:
	string naming;
public:
	string getNaming() {
		return naming;
	}
	ENote() :Note() { naming = ""; }
	void input(istream& is) {
		Note::input(is);
		is >> naming;
	}
	void output(ostream& os)const {
		Note::output(os);
		os << "eName: " << naming << endl;
	}
};
class Student {
private:
	string name;
	string surname;
	string group;
	Note** notes;
	int size;
public:
	Student() { notes = nullptr; }
	friend istream& operator>>(istream& is, Student& s) {
		is >> s.name >> s.surname >> s.group >> s.size;
		s.notes = new Note * [s.size];
		char point;
		for (int i = 0; i < s.size; i++) {
			is >> point;
			if (point == 'p')
				s.notes[i] = new PaperNote;
			else if (point == 'e')
				s.notes[i] = new ENote;
			is >> *s.notes[i];
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Student& s) {
		for (int i = 0; i < s.size; i++)
			os << *(s.notes[i]) << endl;
		return os;
	}
	int getSize() {
		return size;
	}
	Note** getNotes() {
		return notes;
	}
	~Student() {
		if (notes != nullptr) {
			for (int i = 0; i < size; i++) 
				delete notes[i];
			delete []notes;
		}
	}

};

void sort(Note** notesArr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (*notesArr[j + 1] < *notesArr[j]) 
				swap(notesArr[j + 1], notesArr[j]);
}
/*
Note* copy(Note* origin) {
	if (typeid(*origin) == typeid(Note))
		return new Note(*dynamic_cast<Note*>(origin));
	if (typeid(*origin) == typeid(PaperNote))
		return new PaperNote(*dynamic_cast<PaperNote*>(origin));
	if (typeid(*origin) == typeid(ENote))
		return new ENote(*dynamic_cast<ENote*>(origin));
}*/


int main() {
	ifstream file("data.txt");
	int size;
	file >> size;
	int sum = 0;
	Student* arr = new Student[size];
	for (int i = 0; i < size; i++) {
		file >> arr[i];
		sum += arr[i].getSize();
	}
	
	Note** notes = new Note*[sum];
	int allNotes = 0;
	for (int i = 0; i < size; i++) {
		Note** pull = arr[i].getNotes();
		for (int k = 0; k < arr[i].getSize(); k++) {
			notes[allNotes + k] = pull[k];
		}
		allNotes += arr[i].getSize();
	}
	sort(notes, sum);
	ofstream result1("sorted.txt");
	for (int i = 0; i < sum; i++)
		result1<<*notes[i]<<endl;
	ofstream result2("comp.txt");
	int comps = 0;
	for (int i = 0; i < sum; i++) {
		ENote* e = dynamic_cast<ENote*>(notes[i]);
		if (e != nullptr && e->getNaming() == "comp") {
			result2 << *e << endl;
			comps++;
		}
	}
	result2 << comps;

	return 0;
}