#include <iostream>
using namespace std;
class Client {
private:
	string name;
	string adress;
	int number;
public:
	Client(): name(""), adress(""), number(000000){}
	Client(string n, int num): name(n), adress("hidden"), number(num){}
	Client(string n, string a, int num): name(n), adress(a), number(num){}
	string getName() {
		return name;
	}
	string getAdress() {
		return adress;
	}
	int getNumber() {
		return number;
	}
};
class BankAccount {
private:
	Client client;
	int cardnumber;
	int balance;
public:
	BankAccount(): client(), cardnumber(0), balance(0){}
	BankAccount(Client c): client(c), cardnumber(rand()), balance(0){}
	BankAccount(Client c, int cn, int b): client(c), cardnumber(cn), balance(b){}
	int getBalance() {
		return balance;
	}
	Client getClient() {
		return client;
	}
	int getCardnumber() {
		return cardnumber;
	}
	
	void addMoney(int amount) {
		balance += amount;
	}
	void takeMoney(int amount) {
		if (amount > balance)
			cout<< "not enough money on your bank account";
		else
		balance -= amount;
	}
	void outputInfo() {
		cout << endl<<endl;
		cout << "client info: " << endl << "name: " << client.getName() << endl << "adress: " << client.getAdress() << endl << "number: " << client.getNumber() << endl;
		cout <<endl<< "account info: " << endl << "card number: " << cardnumber << endl << "balance: " << balance << endl<<endl;
	}

};
void searchByName(BankAccount* arr, int n, string searchname) {
	for (int i = 0; i < n; i++) {
		if (searchname == arr[i].getClient().getName())
			arr[i].outputInfo();
	}
}
void searchByAdress(BankAccount* arr, int n, string searchadress) {
	for (int i = 0; i < n; i++) {
		if (searchadress == arr[i].getClient().getAdress())
			arr[i].outputInfo();
	}
}
BankAccount searchByCN(BankAccount* arr, int n, int cn) {
	for (int i = 0; i < n; i++) {
		if (cn == arr[i].getCardnumber())
			 return arr[i];
	}
}
void menu(BankAccount* arr, int n, int press, string searchname, string searchadress, int amount, int cn) {
	cout << "press 1 to search by name, 2 by adress" << endl;
	cin >> press;
	if (press == 1) {
		cout << "enter name: " << endl;
		cin >> searchname;
		searchByName(arr, n, searchname);
	}
	if (press == 2) {
		cout << "enter adress:" << endl;
		cin >> searchadress;
		searchByAdress(arr, n, searchadress);
	}
	else cout << "please, enter a valid number";

	press = 0;

	cout << "to choose an account enter a card number:" << endl;
	cin >> cn;
	cout << endl<<"chosen account: " << endl; 
	BankAccount current = searchByCN(arr, n, cn);

	cout << "press 1 to add money, 2 to take out" << endl;
	cin >> press;
	if (press == 1) {
		cout << "enter the amount: " << endl;
		cin >> amount;
		current.addMoney(amount);
	}
	if (press == 2) {
		cout << "enter the amount:" << endl;
		cin >> amount;
		current.takeMoney(amount);
	}
	else cout << "please, enter a valid number";

	cout << endl<<endl<<"current info: " << endl;
	current.outputInfo();

}

int main() {
	const int n = 3;
	BankAccount arr[n];
	arr[0] = BankAccount(Client("Lilo", "Lviv", 98710), 345345, 150);
	arr[1]= BankAccount(Client("Mori", "Kyiv", 93510), 345657, 4050);
	arr[2]= BankAccount(Client("Pio", "Lviv", 98056), 447345, 50);
	int press=0, amount=0, cn=0;
	string searchadress, searchname;

	menu(arr, n, press, searchname, searchadress, amount, cn);


	return 0;
}