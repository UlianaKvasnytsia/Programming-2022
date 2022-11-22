/*1.	ј) ¬изначити перел≥ченн€ дл€ збер≥ганн€ м≥с€ц≥в року Month.
- Ќаписати функц≥ю, €ка перетворюЇ р€док тексту назви м≥с€ц€ в зм≥нну типу Month, враховуючи ≥ неповн≥ вар≥анти, 
наприклад УDecemberФ, УDecФ.
- ј також визначити зворотню функц≥ю, €ка за зм≥нною типу Month повертаЇ р€док його ≥мен≥.
- ¬вести масив р€дк≥в назв м≥с€ц≥в Ц перетворити його в масив зм≥нних типу Month.
- ѕорахувати ск≥льки кожен м≥с€ць зустр≥чаЇтьс€ в масив≥ ≥ видрукувати пари Ќазва м≥с€ц€ Ц к≥льк≥сть повтор≥в в масив≥
Ѕ)¬изначити структуру Date, в €к≥й три пол€ : день(1..31), м≥с€ць типу Months ≥ р≥к Ц ц≥ле число.
¬ основн≥й програм≥ створити масив з 5 елемент≥в типу Date ≥ ввести дати, вивести дату, €ка найближча до сьогодн≥шньоњ*/

#include <iostream>
using namespace std;
enum Month {
	January = 1, February, March, April, May, June, July, August, September, October, November, December
};
struct Date {
	int d;
	Month m;
	int y;
};
Month string_to_month(string mon) {
	for (int i = 0; i < mon.length(); i++) {
		mon[i] = tolower(mon[i]);
	}
	string month_array[] = {"january","february","march","april","may","june","july","august","september","october","november","december"};
	int index = 0;
	for (int i = 0; i < 12; i++) {
		if (month_array[i].compare(0, mon.length(), mon) == 0) { index = i + 1; break; }
	}
	return Month(index);
	}
string month_to_string(Month m) {
	switch (m) {
	case January: return "January";
	case February: return "February";
	case March: return "March";
	case April: return "April";
	case May: return "May";
	case June: return "June";
	case July: return "July";
	case August: return "August";
	case September: return "September";
	case October: return "October";
	case November: return "November";
	case December: return "December";
	default: return "invalid month, try again";
	}
}
void sorting(Month* arr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}
void input(Date& date) {
	cout << "enter the date" << endl;
	bool check=true;
	while (check) {
		cin >> date.d;
		if (date.d >= 1 && date.d <= 31) check = false;
		else cout << "day is invalid. enter another" << endl;
	}
	check = true;
	string mm;
	while (check) {
		cin >> mm;
		if (string_to_month(mm) != 0) {
			date.m = string_to_month(mm);
			check = false;
		}
		else cout<< "month is invalid. enter another" << endl;
	}
	check = true;
	while (check) {
		cin >> date.y;
		if (date.y >= 1) check = false;
		else cout<< "year is invalid. enter another" << endl;
	}
}
void output(Date date) {
	cout << date.d << " " << month_to_string(date.m) << " " << date.y << endl;
}
bool operator<(Date date1, Date date2) {
	if (date1.y != date2.y) return date1.y<date2.y;
	if (date1.m != date2.m) return date1.m < date2.m;
	return date1.d < date2.d;
}
Date addoneday(Date date) {
	Date newdate;
	if (date.d + 1 <= 31) { newdate.d = date.d + 1; 
	newdate.m = date.m;
	newdate.y = date.y;}
	else if (int(date.m) + 1 <= 12) {
		newdate.d = 1;
		newdate.m = Month(date.m + 1);
		newdate.y = date.y;
	}
	else {
		newdate.d = 1;
		newdate.m = January;
		newdate.y = date.y + 1;
	}
	return newdate;
}
Date closest(Date* date_array, int datenum, Date date) {
	int counter = 0;
	int min = INT_MAX;
	int index_min = 0;
	for (int i = 0; i < datenum; i++) {
		counter = 0;
		if (date_array[i] < date) {
			Date temp = date_array[i];
			while (temp < date) {
				temp = addoneday(temp);
				counter++;
			}
		}
		else if (date < date_array[i]) {
			Date temp = date;
			while (temp < date_array[i]) {
				temp = addoneday(temp);
				counter++;
			}
		}
		if (counter < min) { min = counter; index_min = i; }

	}
	return date_array[index_min];
}


int main() {
	int n;
	string s;
	cout << "part a" << endl;
	cout << "enter the quantity" << endl;
	cin >> n;
	Month* month_array = new Month[n];
	cout << "enter the array" << endl;
	for (int i = 0; i < n; i++) {
		cin >> s;
		month_array[i] = string_to_month(s);
	}
	sorting(month_array, n);
	int index=0;
	int index_start = 0;
	Month cur = month_array[index];
	while (index < n) {
		cout << month_to_string(cur) << " ";
		while (index < n && month_array[index] == cur) {
			index++;
		}
		cout << index - index_start << endl;
		index_start = index;
		if(index<n) cur = month_array[index];
	}

	Date date;
	cout << "part b" << endl;
	cout << "enter today's date" << endl;
	input(date);
	cout << "enter an array of dates" << endl;
	const int datenum = 5;
	Date date_array[datenum];
	for (int i = 0; i < datenum; i++) {
		input(date_array[i]);
	}
	Date new_date = closest(date_array, datenum, date);
	output(new_date);
	return 0;
}