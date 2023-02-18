#include "song.h"
#include <fstream>

int summary(Song* arr, int n,string s) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if(arr[i].getartist()==s)
		sum += arr[i].getduration();
	}
	return sum;
}
Song themin(Song* arr, int n) {
	int min = INT_MAX;
	Song minsong;
	for (int i = 0; i < n; i++) {
		if (arr[i].getduration() < min) {
			min = arr[i].getduration(); minsong = arr[i];
		}}
	return minsong;
}
int main() {
	int n;
	ifstream file("input.txt");
	file >> n;
	Song* arr = new Song[n];
	for (int i = 0; i < n; i++)
		file >> arr[i];
	cout << "enter an artist to start search: " << endl;
	string search;
	cin >> search;
	cout << "total length of all artist's songs: " << summary(arr, n, search) << endl;
	cout << "the shortest song: " <<endl << themin(arr, n) << endl;

	return 0;
}