/*
 * Song.h
 *
 *  Created on: Nov 22, 2017
 *      Author: Maya
 */
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

class Song {
private:
    string songName;
    string songAlbum;
    //date songDate;
    string year;
	string month;
	string day;
    string songlyrics;
    string onChart;
    string length;
    string views;
    //int keyHits;


public:

/**Constructors*/
    Song();
    Song(string songTitle, string Album, string y, string m, string d, string lyrics, string isonChart, string songlength, string songviews);



    /**Access Functions*/
    string getName();
    string getAlbum();
    string getDate();
    string getYear();
    string getMonth();
    string getDay();
    string getLyrics();
    string isOnChart();
    string getLength();
    string getViews();

    //string getHits();

    /**Manipulation Procedures*/
    void setName(string title);
    void setAlbum(string album);
   // void setDate(int year, int month, int day);
    void setYear(string y);
    void setMonth(string m);
    void setDay(string d);
    void setLyrics(string songLyrics1);
    void setCharts(string oC);
    void setLength(string len);
    void setViews(string viw);
    //void setHits(int keyHits);


/**Additional Functions*/

    friend ostream& operator<<(ostream& os, const Song& song);

    bool operator==(const Song& song);

    bool operator<(const Song& song);

    bool operator>(const Song& song);

};



#endif /* SONG_H_ */
