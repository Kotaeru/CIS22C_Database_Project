/*
 * main.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: Kyle
 */

#include<iostream>
#include<string>
#include<fstream>
#include "Song.h"
#include "HashTable.h"
#include "betterReadIn.h"
#include "readOut.h"
#include "HashMap.h"
#include "wordID.h"
#include "invertedIndexReadIn.h"

using namespace std;

int main()
{
	int menuChoice = 0;
	string userInput;
	char userChoice;
	int found = 0;
	int index = -1;
	HashTable H1;
	HashTable H2;
	HashMap HM;
	cout << "Welcome!" <<endl;
	while(menuChoice != 4)
	{
		readIn(H1);
		cout << "1) Search by Title\n2) Search by keywords\n3) Add or Delete\n4) Quit\n\n";
		cout << "Enter the number of your choice: ";
		cin >> menuChoice;
		if(menuChoice == 1)
		{
			cout << "Enter the title of the song you wish to search for: ";
			getline(cin, userInput);
			Song Sobj;
			Sobj.setName(userInput);
			index = H1.search(Sobj);
			H1.printResults(cout, index, userInput, found);
			do
			{
			if(found)
			{
				found = 0;
				cout << "Would you like to see more information about this song? y/n ";
				cin >> userChoice;
				if(userChoice == 'y')
				{
					H1.getFullResults(cout, index, userInput, found);
					system("pause");
				}
			}
			}while(userChoice != 'y' || userChoice != 'n');
		}
		else if(menuChoice == 2)
		{
			cout << "Enter the key word you would like to search for: ";
			getline(cin, userInput);
			//this is where the inverted index function goes
			readInverted(HM, H2);
			index = HM.get(userInput);
			H2.printBucket(cout, index);
		}
		else if(menuChoice == 3)
		{
			cout << "1) Add a new song\n2) Delete an existing song\n";
			cout << "Enter the number of your choice: ";
			cin >> menuChoice;
			if(menuChoice == 1)
			{
				char confirm;
				//char confirm2;
				string newTitle = "Empty";
				string newAlbum = "Empty";
				string newDate = "Empty";//this one requires an sstream function to pick apart the fields
				string newYear = "Empty";
				string newMonth = "Empty";
				string newDay = "Empty";
				string lyrics = "Empty";
				string onChart = "Empty";
				string length = "Empty";
				string views = "Empty";
				cout <<endl << "Please fill in as many fields as possible. If you do not know one of the fields, please leave it blank." <<endl;
				cout << "Enter the new songs title: ";
				cin.ignore();
				getline(cin, newTitle);
				cout <<endl << "Enter the new songs album: ";
				getline(cin, newAlbum);
				cout <<endl << "Enter the new songs release date in format dd/mm/yyyy: ";
				getline(cin, newDate);
				cout <<endl << "Enter the new songs lyrics: ";
				getline(cin, lyrics);
				cout <<endl << "Enter true if the song was on chart or false if it was not: "; //i dont know what chart so someone fix that
				cin >> onChart;
				cout << endl <<"Enter the length of the song in format mm:ss : ";
				cin >> length;
				cout <<endl << "Enter the amount of views the song has on youtube: ";
				cin >> views;
				do
				{
					cout <<endl <<endl;
					cout << "Title: " << newTitle <<endl;
					cout << "Album: " << newAlbum <<endl;
					cout << "Release Data: " << newDate <<endl;
					cout << "On Chart: " << onChart <<endl;
					cout << "Length: " << length <<endl;
					cout << "Youtube Views: " << views << endl;
					cout <<"Are these field correct? y/n " <<endl;
					cin >> confirm;
					if(confirm == 'n')
					{
						cout << "This is the editing menu thing someone do this" <<endl;
						//put a menu here asking which field the user wants to change then change the field
					}
				}while(confirm != 'y');
				newDay = newDate.substr(0, 2);
				cout << newDay <<endl;
				newMonth = newDate.substr(3, 2);
				cout << newMonth <<endl;
				newYear = newDate.substr(6, 2);
				cout << newYear <<endl;
				Song S(newTitle, newAlbum, newYear, newMonth, newDay, lyrics, onChart, length, views);
				readOut(S);
			}
			else if(menuChoice == 2)
			{
				cout << "Enter the title of the song you wish to delete: ";
			}
		}
	}
}


