#include <iostream>
using namespace std;
struct Node {
	Node* prev;
	int item;
	Node* next;

	Node(int i = 0, Node* n = nullptr, Node* p = nullptr) :item(i), next(n), prev(p) {}
};
void output(Node* first) {
	Node* temp = first;
	while (temp != nullptr) {
		cout << temp->item << " ";
		temp = temp->next;
	}
	cout << endl;
}
void addfirst(int toadd, Node*& first) {
	Node* k = new Node(toadd, first);
	first->prev = k;
	first = k;
}
void addlast(int toadd, Node*& first) {
	Node* m = new Node(toadd);
	Node* temp = first;
	if (first == nullptr) {
		first = m; return;
	}
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	m->prev = temp;
	temp->next = m;
}
int size(Node* first) {
	Node* temp = first;
	int s = 0;
	while (temp != nullptr) {
		s++;
		temp = temp->next;
	}
	return s;
}
void outt(Node* first) {
	if (first == nullptr) {
		cout << endl;
		return;
	}
	cout << first->item << " ";
	outt(first->next);

}
bool cond1(int i) {
	return i < 5;
}
int countif(Node* first, bool(*pf)(int)) {
	int k = 0;
	Node* temp = first;
	while (temp->next != nullptr) {
		if (pf(temp->item)) k++;
		temp = temp->next;
	}
	return k;
}
void deletelast(Node*& first) {
	if (first == nullptr) return;
	Node* temp = first;
	if (temp->next == nullptr) {
		delete temp;
		first = nullptr;
		return;
	}
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
}
void deletefirst(Node*& first) {
	if (first == nullptr) return;
	Node* second = first->next;
	delete first;
	first = second;
	first->prev = nullptr;
}
bool iseven(int i) {
	return !(i % 2);
}
void conddelete(Node*& first, bool(*pf)(int)) {
	Node* temp = first->next;
	//first is passing the condition
	if (pf(first->item)) {
		delete first;
		first = temp;
		first->prev = nullptr;
		return;
	}
	temp = first;
	while (temp->next != nullptr && !pf(temp->next->item)) {
		temp = temp->next;
	}
	if (temp->next != nullptr) {
		Node* todelete = temp->next;
		temp->next = temp->next->next;
		if (temp->next != nullptr) {
			temp->next->prev = temp;
		}
		delete todelete;
		
	}
	else return;
}

int main() {
	
	Node* c = new Node(3);
	Node* b = new Node(2);
	Node* a = new Node(1);
	
	c->next = b;
	b->next = a;
	b->prev = c;
	a->prev = b;
	addfirst(4, c);
	addlast(5, c);
	deletefirst(c);
	outt(c);
	conddelete(c, iseven);
	addlast(2, c);
	outt(c);
	conddelete(c, iseven);
	output(c);
	
	return 0;
}