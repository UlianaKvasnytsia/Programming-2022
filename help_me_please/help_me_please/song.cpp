#include "song.h"

Song::Song():name(""), artist(""), duration (0){ }

Song::Song(string n, string a, int d): name(n), artist(a), duration(d){}

string Song::getartist()
{return artist;}

string Song::getname()
{return name;}

int Song::getduration()
{return duration;}

istream& operator>>(istream& is, Song& s)
{is >> s.name >> s.artist >> s.duration;
	return is;}

ostream& operator<<(ostream& os, const Song& s)
{	os << "name: " << s.name << endl << "artist: " << s.artist << endl << "duration: " << s.duration << endl << endl;
	return os;}
