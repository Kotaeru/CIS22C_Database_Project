/*
 * invertedIndexReadIn.h
 *
 *  Created on: Dec 4, 2017
 *      Author: Kyle
 */

#ifndef INVERTEDINDEXREADIN_H_
#define INVERTEDINDEXREADIN_H_

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

void readInverted(HashMap &HM, HashTable &H2)
{
	string path = ".\\Group_8_Songs\\"; //the path to follow
	string searchPattern = "*.txt"; //the template for files to open (* is the wild card)
	string fullSearchPath = path + searchPattern;
	char delimiter(';');
	Song obj1;
	string songData;
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
	int counter = 0;

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
			in.seekg(0);
			while(!in.eof())
			{
			string s;
			getline(in, songData, delimiter);
			stringstream ss(songData);
			while(ss >> s)
			{
				HM.insert(s, counter);
				H2.insertAtIndex(S1, counter-1);
			}
			cout << "Finished reading" <<endl;
			}


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




#endif /* INVERTEDINDEXREADIN_H_ */
