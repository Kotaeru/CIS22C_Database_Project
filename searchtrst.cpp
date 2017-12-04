/*
 * searchtrst.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: Kyle
 */


/*
#include<iostream>
#include "HashTable.h"
#include "BST.h"
#include "Song.h"
#include "readIn.h"
#include <fstream>

using namespace std;

int main()
{
	//Test of readIn function
	HashTable H1;
	HashTable H2;
	HashTable H3;
	HashTable H4;
	HashTable H5;
	HashTable H6;
	HashTable H7;
	HashTable H8;
	BST<Song> B1;
	Song B2;
	Song B3;
	Song B4;
	Song B5;
	Song B6;
	Song B7;
	Song B8;
	Song B9;
	string userstring;
	ifstream inFile;
	inFile.open("Songs.txt");
	inFile.seekg(0);
	readIn(inFile, 1, H1);
	inFile.seekg(0);
	readIn(inFile, 2, H2);
	inFile.seekg(0);
	/*readIn(inFile, 3, H3);
	inFile.seekg(0);
	readIn(inFile, 4, H4);
	inFile.seekg(0);
	readIn(inFile, 5, H5);
	inFile.seekg(0);
	readIn(inFile, 6, H6);
	inFile.seekg(0);
	readIn(inFile, 7, H7);
	inFile.seekg(0);
	readIn(inFile, 8, H8);
	inFile.seekg(0);*/
	//cout << endl;
	//use this to test if the readIn worked properly
	/*for(int i = 0; i < 30; i++)
	{
		cout << "Index " << i <<": " <<endl;
		H1.printBucket(cout, i);
		cout << endl;
	}*/
	//test of searchFunction
/*	cout << "Enter the songs title: ";
	getline(cin, userstring);
	B2.setName(userstring);
	int index = H1.hash(userstring);
	//int index = H1.search(B2, 1);
	//cout << index <<endl;
	//H1.printBucket(cout, index);
	cout <<endl << "Search results for " <<userstring << ":";
	H1.printResults(cout, index, userstring, 1);
	cout <<endl << "Enter the songs album: ";
	getline(cin, userstring);
	B3.setAlbum(userstring);
	index = H2.hash(userstring);
	cout <<endl << "Search Results for " << userstring << ":";
	H2.printResults(cout, index, userstring, 2);
	cout << endl << "Enter the name of the song you would like more information on: ";
	getline(cin, userstring);
	index = H1.hash(userstring);
	H1.getFullResults(cout, index, userstring);
	//H2.printBucket(cout, index);
	/*cout << H2.search(B3, 2) <<endl <<endl;
	cout << "Enter the songs year: ";
	getline(cin, userstring);
	B4.setYear(userstring);
	cout << H3.search(B4, 3) <<endl <<endl;*/
	//return 0;
//}

