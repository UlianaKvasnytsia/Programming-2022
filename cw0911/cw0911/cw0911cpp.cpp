//1 
/* #include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cout << "enten the line without spaces: " << endl;
	cin>>s;
	int a, sum = 0;
	bool p;
	for (int i = 0; i < s.length(); ) {
		
		p = true;
		a = 0;
		while (s[i] != ','&& s[i]!='.') {
			
			if (s[i] == '.') break;
			else if (s[i] == '-') p = false;
			else {
				a = (s[i] - '0') + a*10;
			}
			i++;
		}
		if (p==true) sum += a;
		else sum -= a;
		i++;	
	}
	cout << "the sum is: "<<sum;
	return 0;
}*/

//2) ������ �����, �� ���������� �������. ������ � ����� �������� ����������� ����, �� ����� �����.
/*#include <iostream>
#include <string>
using namespace std;
int main() {
	string text;
	getline(cin, text, '.');
	int i = 0;
	int start = 0, maxstart=0, len, maxlength=0;
	while (i < text.length()) {
		while (i < text.length()&&!isdigit(text[i])) {
			i++;
		}
		start = i;
		len = 1;
		while (i < text.length()&&isdigit(text[i])) {
			len++;
			i++;
		}
		if (len > maxlength) {
			maxlength = len;
			maxstart = start;
		}

	}
	cout << "the max number: ";
	for (int i = maxstart; i < maxstart + maxlength; i++) {
		cout << text[i];
	}
	return 0;
} */

//3. ������ �����, �� ������ �����, ������� ��������� � ���������� �������. 
//��� ������� ����� ����������� ������� ������� � �����. 
//���������� ������ ��� ����������� � ����������� �� ���� � �� � ����� ������.
#include <iostream>
#include <string>
using namespace std;
int main() {
	string text, word;
	getline(cin, text, '.');
	int len, thesame = 0;
	for (int i = 0; i < text.length(); ) {
		len = 0;
		word = "";
		while (i < text.length()&&text[i] != ' ') {
			word += text[i];
			len++;
			i++;
		}
		if (word[0] == word[word.length() - 1]) thesame++;
		cout << len<<" ";
		i++;
	}
	cout << "the amount of words with the same first and last digits: " << thesame;
	return 0;
}
