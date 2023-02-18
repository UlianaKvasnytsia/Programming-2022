#pragma once
#include <iostream>
#include <string>
using namespace std;
class Song
{ private:
	string name, artist;
	int duration;

public:
	Song();
	Song(string n, string a, int d);

	string getartist();
	string getname();
	int getduration();

	friend istream& operator>>(istream& is, Song& s);
	friend ostream& operator<<(ostream& os, const Song& s);

};

