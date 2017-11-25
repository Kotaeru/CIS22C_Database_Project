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
    int year;
	int month;
	int day;
    string songlyrics;
    bool onChart;
    double length;
    int views;
    //int keyHits;


public:

/**Constructors*/
    Song();
    Song(string songTitle, string Album, int y, int m, int d, string lyrics, bool isonChart, int songlength, int songviews);



    /**Access Functions*/
    string getName();
    string getAlbum();
    string getDate();
    string getLyrics();
    bool isOnChart();
    int getLength();
    int getViews();
    int getHits();

    /**Manipulation Procedures*/
    void setName(string title);
    void setAlbum(string album);
   // void setDate(int year, int month, int day);
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setLyrics(string songLyrics1);
    void setCharts(bool isOnChart);
    void setLength(int songlength);
    void setViews(int ytViews);
    //void setHits(int keyHits);


/**Additional Functions*/

    friend ostream& operator<<(ostream& os, const Song& song);

    bool operator==(const Song& song);

    bool operator<(const Song& song);

    bool operator>(const Song& song);

};



#endif /* SONG_H_ */
