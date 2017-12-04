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

void readIn(ifstream &inputfile, int searchType, HashTable &HT) {
	//HashTable HT;
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
		getline(inputfile, songName, delimiter);
		//cout << "one" <<endl;
		//cout <<author;
		//cout << "two" <<endl;
		getline(inputfile, songAlbum, delimiter);
		getline(inputfile, year, delimiter);
		//cout << "three" <<endl;
		getline(inputfile, month, delimiter);
		//cout << "four" <<endl;
		getline(inputfile, day, delimiter);
		//cout << "five" <<endl;
		getline(inputfile, lyrics, delimiter);
		//inputfile >> price;
		//cout << "six" <<endl;
		//cout << "seven" <<endl;
		//cout << "eight" <<endl;
		getline(inputfile, onChart, delimiter);
		 getline(inputfile, length, delimiter);
		//cout << "nine"<<endl;
		getline(inputfile, views, delimiter);
		getline(inputfile, studio, delimiter);
		inputfile.ignore();
		//cout << "ten" <<endl;
		//inputfile >>keyHits;
		//inputfile.ignore();
		//inputfile.ignore();

		Song S1(songName,songAlbum, year, month, day, lyrics, onChart, length, views); //can call constructor instead of sets field with get
		/*cout << "Song  " << counter <<endl;
		cout << "Title: " <<S1.getName() <<endl;
		cout <<"Album: " <<S1.getAlbum() <<endl;
		cout <<"Date: "<< S1.getDate() <<endl;
		//cout << S1.getLyrics() <<endl;
		cout <<"OnChart: " <<S1.isOnChart() <<endl;
		cout <<"Length: " << S1.getLength() <<endl;
		cout <<"Views: " << S1.getViews() <<endl;*/
		HT.insert(S1, searchType);

		//bstobj.insert(S1);
	}
	//cout << counter << " songs read in." <<endl;
	/*for(int i = 0; i < 30; i++)
	{
		cout << "Index " << i <<endl;
		HT.printBucket(cout, i);
		cout << endl;
	}*/
}




#endif /* READIN_H_ */
