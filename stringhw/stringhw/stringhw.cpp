//6,3.	Ввести текст, що складається зі слів, розділених пропуском. 
//В кінці тексту – крапка. Для кожного слова визначити яка частка в ньому голосних букв. 
//(по відношенню до всіх інших букв у слові, напр. abhiho = 50%) .
#include <iostream>
#include <string>
using namespace std;
int main() {
	string text, word;
	string holos = "aeuioAEUIO";
	getline(cin, text, '.');
	int len;
	for (int i = 0; i < text.length(); ) {
		len = 0;
		word = "";
		while (i < text.length() && text[i] != ' ') {
			word += text[i];
			for (int j = 0; j < holos.length(); j++) {
				if (text[i] == holos[j]) len++;
			}
			i++;
		}
		cout << len*1.0/word.length() << " ";
		i++;
	}
	return 0;
}