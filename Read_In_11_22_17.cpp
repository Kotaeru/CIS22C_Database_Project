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
	ifstream inputfile;
	Song obj1;
	string songName;
	 string songAlbum;
	 date songDate; // can you just inputfile
	  string lyrics;
	  bool onChart;
	  double length;
	  int views;
	  int keyHits;
	string temp;
	inputfile.open("songs.txt");

	if(inputfile)    //just for me~
	{
		cout <<"successful open";
	}
	char delimeter(';');
	while(!inputfile.eof())
	{
		getline(inputfile, songName , delimeter);
		getline(inputfile, songAlbum, delimeter);
		//cout <<author;
		inputfile >> songDate.year;
		inputfile >> songDate.month;
		inputfile >> songDate.day;
		getline(inputfile, lyrics, delimeter);
		inputfile >>onChart;
		inputfile >> length;
		inputfile >>views;
		inputfile >>keyHits;
		inputfile.ignore();
		inputfile.ignore();
//Song::Song(string sn, string sa, date sD,string lyr, bool oC,int len, int viw,int kH)
		Song s1(songName, songAlbum, songDate, lyrics, onChart, length, views, keyHits); //can call constructor instead of sets field with get
	//	cout <<s;

		HT.insert(s1);
		bstobj.insert(s1);
	}
	//bstobj.inOrderPrint(cout);

}
