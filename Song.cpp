/*
 * Song.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: Maya
 */

#include "Song.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Song::Song():songName(""), songAlbum(""), songDate.month=0, songDate.day=0,songDate.year=0, lyrics(""), onChart(false), length(0), views(0), keyHits(0){};

Song::Song()
{
	songName = "Empty";
	songAlbum = "Empty";
	songDate.year = 0;
	songDate.month = 0;
	songDate.day = 0;
	lyrics = "Empty";
	onChart = false;
	length = 0;
	views = 0;
	keyHits=0;
}
Song::Song(string sn, string sa, date sD,string lyr, bool oC,int len, int viw,int kH) {
    songName = sn;
    songAlbum = sa;
    lyrics= lyr;
    onChart=oC;
    length=len;
    views=viw;
    keyHits=kH;
}

/**Access Functions*/

string Song:: get_songName() {
    return songName;
}

string Song::get_songAlbum() {
    return songAlbum;

}

date Song:: get_songDate()
{
	return songDate;
}

string Song:: getLyrics()
    {return lyrics;}


bool Song:: isOnChart()
{return onChart;}

 int Song:: getLength()
 {return length;}

 int Song:: getViews()
 {return views;}

 int Song:: getHits()
 {return keyHits;}




/**Manipulation Procedures*/




void Song::set_songName(string sn)
{songName=sn;}
 void Song:: set_songAlbum(string sa)
   {songAlbum=sa;}
 void Song:: set_songDate(date sD)
   {songDate=sD;}
   void Song:: setLyrics(string lyr)
   {lyrics=lyr;}
   void Song:: setCharts(bool oC)
   {onChart=oC;}
   void Song:: setLength(int len)
   {length=len;}
   void Song:: setViews(int viw)
   {views=viw;}
   void Song:: setHits(int kH)
   {keyHits=kH;}

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


