/*
 * betterReadIn.h
 *
 *  Created on: Dec 3, 2017
 *      Author: Kyle
 */

#ifndef BETTERREADIN_H_
#define BETTERREADIN_H_

#include<windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<sstream>
#include "HashTable.h"
#include "BST.h"
#include "Song.h"
#include "HashMap.h"

using namespace std;

void readIn(HashTable& H1)
{
	string path = ".\\Group_8_Songs\\"; //the path to follow
	string searchPattern = "*.txt"; //the template for files to open (* is the wild card)
	string fullSearchPath = path + searchPattern;
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

	WIN32_FIND_DATA FindData; //gets attributes about the files
	HANDLE hFind; //what is this
	cout << fullSearchPath.c_str() <<endl;
	hFind = FindFirstFile(fullSearchPath.c_str(), &FindData);
	if(hFind == INVALID_HANDLE_VALUE)//checks if the directory exists
	{
		cout << "Error reading directory" <<endl;
		return;
	}

	do
	{
		string filePath = path + FindData.cFileName;
		ifstream in(filePath.c_str());
		if(in)
		{
			getline(in, songName, delimiter);
			getline(in, songAlbum, delimiter);
			getline(in, year, delimiter);
			getline(in, month, delimiter);
			getline(in, day, delimiter);
			getline(in, lyrics, delimiter);
			getline(in, onChart, delimiter);
			getline(in, length, delimiter);
			getline(in, views, delimiter);

			Song S1(songName,songAlbum, year, month, day, lyrics, onChart, length, views);
			H1.insert(S1);



		}
		in.close();
		if(!in)
		{
			cout << "file closed" <<endl;
		}
	}while(FindNextFile(hFind, &FindData) > 0); //checks to make sure that there is a new file
	if(GetLastError() != ERROR_NO_MORE_FILES)
	{
		cout << "Something went wrong during search" <<endl;
	}
	return;
}



#endif /* BETTERREADIN_H_ */
