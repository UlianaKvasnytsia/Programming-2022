//#include <iostream>
//using namespace std;
//struct Node {
//	int item;
//	Node* next;
//
//	Node(int i=0, Node*n=nullptr):item(i),next(n){}
//};
//void output(Node* first) {
//	Node* temp = first;
//	while (temp != nullptr) {
//		cout << temp->item << " ";
//		temp = temp->next;
//	}
//	cout << endl;
//}
//void addfirst(int toadd, Node*& first) {
//	Node* k = new Node(toadd, first);
//	first = k;
//}
//void addlast(int toadd, Node*& first) {
//	Node* m = new Node(toadd);
//	Node* temp = first;
//	if (first == nullptr) {
//		first = m; return;
//	}
//	while (temp->next != nullptr) {
//		temp = temp->next;
//	}
//	temp->next = m;
//}
//int size(Node* first) {
//	Node* temp = first;
//	int s = 0;
//	while (temp != nullptr) {
//		s++;
//		temp = temp->next;
//	}
//	return s;
//}
//void outt(Node* first) {
//	if (first == nullptr) {
//		cout << endl;
//		return;
//	}
//	cout << first->item << " ";
//	outt(first->next);
//
//}
//bool cond1(int i) {
//	return i < 5;
//}
//int countif(Node* first, bool(*pf)(int)) {
//	int k = 0;
//	Node* temp = first;
//	while (temp->next != nullptr) {
//		if (pf(temp->item)) k++;
//		temp = temp->next;
//	}
//	return k;
//}
//void deletelast(Node*& first) {
//	if (first == nullptr) return;
//	Node* temp = first;
//	if (temp->next == nullptr) {
//		delete temp;
//		first = nullptr;
//		return;
//	}
//	while (temp->next->next != nullptr) {
//		temp = temp->next;
//	}
//	delete temp->next;
//	temp->next = nullptr;
//}
//void deletefirst(Node*& first) {
//	if (first == nullptr) return;
//	Node* second = first->next;
//	delete first;
//	first = second;
//}
//bool iseven(int i) {
//	return !(i % 2);
//}
//void conddelete(Node*& first, bool(*pf)(int)) {
//	Node* temp = first->next;
//	//first is passing the condition
//	if (pf(first->item)) {
//		delete first;
//		first = temp;
//		return;
//	}
//	temp = first;
//	while (temp->next!=nullptr&&!pf(temp->next->item)) {
//		temp = temp->next;
//	}
//	if (temp->next != nullptr) {
//		Node* todelete = temp->next;
//		temp->next = temp->next->next;
//		delete todelete;
//	}
//	else return;
//}
//
//int main() {
//	Node* a = new Node(1);
//	Node* b = new Node(2, a);
//	Node* c = new Node(3, b);
//	output(c);
//	Node* d = new Node(4, b);
//	c->next = d;
//	output(c);
//	addfirst(5, c);
//	output(c);
//	addlast(9, c);
//	output(c);
//	cout<<size(c)<<endl;
//	outt(c);
//	cout << endl<<countif(c,cond1) << endl;
//	deletelast(c);
//	outt(c);
//	deletefirst(c);
//	outt(c);
//	conddelete(c, iseven);
//	outt(c);
//	conddelete(c, iseven);
//	outt(c);
//	conddelete(c, iseven);
//	outt(c);
//	addfirst(2, c);
//	conddelete(c, iseven);
//	outt(c);
//	addlast(6, c);
//	outt(c);
//	conddelete(c, iseven);
//	outt(c);
//	
//	return 0;
//}