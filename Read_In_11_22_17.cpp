//============================================================================
// Name        : Read_In_11_22_17.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HashTable.h"
#include "Song.h"
#include "BST.h"
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

int main() {
	BST<Song> bstobj;
	HashTable HT;
	char delimiter = ';';
	ifstream inputfile;
	Song obj1;
	string songName;
	 string songAlbum;
	 int year;
	 int month;
	 int day;
	  string lyrics;
	  double price;
	  bool onChart;
	  double length;
	  int views;
	  //int keyHits;
	string temp;
	inputfile.open("catalogue.txt");

	/*if(inputfile)    //just for me~
	{
		cout <<"successful open";
	}*/

	while(!inputfile.eof())
	{
		getline(inputfile, songName , delimiter);
		getline(inputfile, songAlbum);
		//cout <<author;
		inputfile >> year;
		inputfile >> month;
		inputfile >> day;
		inputfile >> price;
		getline(inputfile, lyrics);
		inputfile >>onChart;
		inputfile >> length;
		inputfile >>views;
		//inputfile >>keyHits;
		inputfile.ignore();
		inputfile.ignore();

		Song S1(songName,songAlbum, year, month, day, lyrics, onChart, length, views); //can call constructor instead of sets field with get
	//	cout <<b;

		HT.insert(S1);
		bstobj.insert(S1);
	}
	//bstobj.inOrderPrint(cout);

}
