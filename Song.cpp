/*
 * Song.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: Maya
 */

#include "Song.h"
#include <iostream>
#include <iomanip>
#include<string>
#include<sstream>

using namespace std;

//Song::Song():songName(""), songAlbum(""), songDate.month=0, songDate.day=0,songDate.year=0, lyrics(""), onChart(false), length(0), views(0), keyHits(0){};

Song::Song()
{
	songName = "Empty";
	songAlbum = "Empty";
	year = "0";
	month = "0";
	day = "0";
	songlyrics = "Empty";
	onChart = "false";
	length = "0";
	views = "0";
}

Song::Song(string songTitle, string Album, string y, string m, string d, string lyrics, string isonChart, string songlength, string songviews) {
    songName = songTitle;
    songAlbum = Album;
    year = y;
    month = m;
    day = d;
    songlyrics = lyrics;
    onChart = isonChart;
    length = songlength;
    views = songviews;
}

/**Access Functions*/

string Song:: getName() {
    return songName;
}

string Song::getAlbum() {
    return songAlbum;

}

string Song::getDate()
{
	stringstream ss;
	ss << month << "/" << day << "/" << year;
	string dateData = ss.str();
	return dateData;
}

string Song:: getLyrics()
    {return songlyrics;}


string Song:: isOnChart()
{return onChart;}

 string Song:: getLength()
 {return length;}

 string Song:: getViews()
 {return views;}

 //int Song:: getHits()
 //{return keyHits;}




/**Manipulation Procedures*/




void Song::setName(string title)
{songName=title;}
 void Song::setAlbum(string album)
   {songAlbum= album;}
 void Song::setYear(int y)
   {year = y;}
   void Song:: setLyrics(string lyr)
   {songlyrics=lyr;}
   void Song:: setCharts(bool oC)
   {onChart=oC;}
   void Song:: setLength(int len)
   {length=len;}
   void Song:: setViews(int viw)
   {views=viw;}
  // void Song:: setHits(int kH)
  // {keyHits=kH;}

/**Additional Functions*/


bool Song::operator==(const Song& song) {
    return (songName == song.songName && songAlbum==song.songAlbum);
}


ostream& operator<<(ostream& os, const Song& song)
{
	os << song.songName << " by " << song.songAlbum << endl;
	//os <<"$"<<song.price << endl;
	//os <<"ISBN#: " <<song.isbn<< endl;
	return os;
}


bool Song:: operator<(const Song& song)
{

	return (songName < song.songName || ( songName == song.songName && songAlbum < song.songAlbum ));


}


bool Song:: operator>(const Song& song)
{
	return (songName > song.songName || ( songName == song.songName && songAlbum > song.songAlbum ));
}
