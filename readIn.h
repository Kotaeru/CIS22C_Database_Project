/*
 * readIn.h
 *
 *  Created on: Nov 27, 2017
 *      Author: Kyle
 */

#ifndef READIN_H_
#define READIN_H_

#include <iostream>
#include "HashTable.h"
#include "Song.h"
#include "BST.h"
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

void readIn(ifstream &inputfile) {
	BST<Song> bstobj;
	HashTable HT;
	char delimiter(';');
	Song obj1;
	string songName;
	string str;
	 string songAlbum;
	 string year;
	 string month;
	 string day;
	  string lyrics;
	 string studio;
	  string onChart;
	  string length;
	  string views;
	  //int keyHits;
	  int counter = 0;
	string temp;
	//inputfile.open("Songs.txt");
	/*if(inputfile)    //just for me~
		{
			cout <<"successful open";
		}
	else
	{
		cout << "error opening" <<endl;
	}*/

	/*while(getline(inputfile, str, ';'))
	{
		cout << "hi" <<endl;
		cout << str;
	}*/



	while(!inputfile.eof())
	{
		counter++;
		getline(inputfile, songName, ';');
		//cout << "one" <<endl;
		//cout <<author;
		//cout << "two" <<endl;
		getline(inputfile, year, delimiter);
		//cout << "three" <<endl;
		getline(inputfile, month, delimiter);
		//cout << "four" <<endl;
		getline(inputfile, day, delimiter);
		//cout << "five" <<endl;
		getline(inputfile, songAlbum, delimiter);
		//inputfile >> price;
		getline(inputfile, studio, delimiter);
		//cout << "six" <<endl;
		//cout << "seven" <<endl;
		//cout << "eight" <<endl;
		 getline(inputfile, length, delimiter);
		//cout << "nine"<<endl;
		getline(inputfile, views, delimiter);
		//cout << "ten" <<endl;
		getline(inputfile, onChart, delimiter);
		//inputfile >>keyHits;
		//inputfile.ignore();
		getline(inputfile, lyrics, delimiter);
		//inputfile.ignore();

		Song S1(songName,songAlbum, year, month, day, lyrics, onChart, length, views); //can call constructor instead of sets field with get

		HT.insert(S1);
		//bstobj.insert(S1);

	/*cout << S1.getName()<<endl;
	cout << S1.getAlbum()<<endl;
	cout << S1.getDate()<<endl;
	cout << S1.isOnChart()<<endl;
	cout << S1.getLength()<<endl;
	cout << S1.getLyrics()<<endl;
	cout << S1.getViews()<<endl <<endl;*/


	}
	cout << counter << " songs read in." <<endl;
	return;
}




#endif /* READIN_H_ */
