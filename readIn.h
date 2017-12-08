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
#include "HashMap.h"
#include "wordID.h"
#include "Song.h"
#include "BST.h"
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>
using namespace std;

void readIn(ifstream &inputfile, HashTable &HT, BST<Song> &B1, HashMap &HM, HashTable2 &HII, int &counter, int &totalViews) {
	BST<Song> bstobj;
	int count = 0;
	int viewcount;
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
	string temp;

	while(!inputfile.eof())
	{
		count++;
		getline(inputfile, songName, delimiter);
		//cout << "one" <<endl;
		getline(inputfile, songAlbum, delimiter);
		//cout <<author;
		//cout << "two" <<endl;
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
		stringstream ssone(views);
		ssone >> viewcount;
		totalViews += viewcount;
		//cout << "ten" <<endl;

		//getline(inputfile, studio, delimiter);
		inputfile.ignore();
		//inputfile >>keyHits;
		//inputfile.ignore();
		//inputfile.ignore();

		Song S1(songName,songAlbum, year, month, day, lyrics, onChart, length, views); //can call constructor instead of sets field with get


		HT.insert(S1);

		B1.insert(S1);

		HII.insert(S1, counter, HM);


		//bstobj.insert(S1);

	/*cout << S1.getName()<<endl;
	cout << S1.getAlbum()<<endl;
	cout << S1.getDate()<<endl;
	cout << S1.isOnChart()<<endl;
	cout << S1.getLength()<<endl;
	cout << S1.getLyrics()<<endl;
	cout << S1.getViews()<<endl <<endl;*/


	}
	//cout << count << " songs read in." <<endl;
}




#endif /* READIN_H_ */
