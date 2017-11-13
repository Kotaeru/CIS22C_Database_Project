/*
 * Song.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Kyle
 */

#ifndef SONG_H_
#define SONG_H_

#include <string>
#include <ostream>
using namespace std;

struct date
	{
		int month;
		int day;
		int year;
	};

class Song {
private:
    string songName;
    string songAlbum;
    date songDate;
    string lyrics;
    bool onChart;
    double length;
    int views;
    int keyHits;


public:

/**Constructors*/
    Song();
    Song(string songName, string songAlbum, date date, string lyrics, bool onChart, int length, int views, int keyHits);



    /**Access Functions*/
    string getName();
    string getAlbum();
    date getDate();
    string getLyrics();
    bool isOnChart();
    int getLength();
    int getViews();
    int getHits();

    /**Manipulation Procedures*/
    void setName(string songName);
    void setAlbum(string album);
    void setDate(date songDate);
    void setLyrics(string songLyrics);
    void setCharts(bool onChart);
    void setLength(int length);
    void setViews(int views);
    void setHits(int keyHits);


/**Additional Functions*/

    friend ostream& operator<<(ostream& os, const Song& song);

    bool operator==(const Song& song);

    bool operator<(const Song& song);

    bool operator>(const Song& song);

};



#endif /* SONG_H_ */
