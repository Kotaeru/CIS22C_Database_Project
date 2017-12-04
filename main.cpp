/*
 * main.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Kyle
 */

// ~~~ couts ~~~
// the "cout << "\n\n"" at the end of each screen is my way of visually separating each screen for now

// main menu

#include<iostream>
#include<fstream>
#include "HashTable.h"
#include "readIn.h"

using namespace std;

int main()
{
	int userChoice = 0;
	ifstream inputFile;
	inputFile.open("Songs.txt");
	string userinput;
	while(userChoice != 4)
	{
	userChoice = 0;
	int index = -1;
	int found = 0;
	HashTable H1;
	cout << "Welcome!\n\n";
	cout << "1) Search by field\n2) Search by keyword\n3) Add or Delete\n4) Quit\n\n";
	cout << "Enter the number of your choice: ";
	//*INPUT INT*
	cin >> userChoice;
	cout << "\n\n";

	if(userChoice == 1)
	{
		// search menu
		cout << "1) Search by Title\n2) Search by Album\n3) Search by Release Date\n";
		cout << "\n\nEnter the number of your choice: ";
		//*INPUT INT*
		cin >> userChoice;
		if(userChoice == 1)// search screen (be sure to adjust these for each input type if necessary)
		{
			cout <<endl << "Enter the song title: ";
			cin.ignore();
			getline(cin, userinput);
			readIn(inputFile, 1, H1);
			index = H1.hash(userinput);
			H1.printResults(cout, index, userinput, 1, found);
			if(!found)
			{
				cout << "No songs matching Title" <<endl <<endl;
			}
			found = 0;
		}
		else if(userChoice == 2)
		{
			cout << "Enter the songs Album: ";
			getline(cin, userinput);
			readIn(inputFile, 2 , H1);
			index = H1.hash(userinput);
			H1.printResults(cout, index, userinput, 2, found);
			if(!found)
			{
				cout << "No songs matching Album" <<endl <<endl;
			}
			found = 0;
		}
		else if(userChoice == 3)
		{
			cout << "1) Search by release year\n2) Search by release month\n";
			cout << "Enter the number of your choice: ";
			cin >> userChoice;
			if(userChoice == 1)
			{
				cout << "Enter the songs release year: ";
				cin >> userinput;
				readIn(inputFile, 3, H1);
				H1.hash(userinput);
				H1.printResults(cout, index, userinput, 3, found);
				if(!found)
				{
					cout << "No songs matching Year" <<endl <<endl;
				}
				found = 0;
			}
			else if(userChoice == 2)
			{
				cout << "Enter the songs release month: ";
				cin >> userinput;
				readIn(inputFile, 4, H1);
				index = H1.hash(userinput);
				H1.printResults(cout, index, userinput, 4, found);
				if(!found)
				{
					cout << "No songs matching release month" <<endl <<endl;
				}
				found = 0;
			}
		}
		while(!found)
		{
		cout << "Enter the title of the song you would like more information on or enter q to return to the main menu: ";
		getline(cin, userinput);
		cout << endl;
		if(userinput == "q")
		{
			userChoice = 0;
			userinput = " ";
			break;
		}
		H1.getFullResults(cout, index, userinput, found);
		if(!found)
		{
			cout << "Please enter a valid title from the search results" <<endl;
		}
		}
	}
	else if(userChoice == 2)
	{
		cout << "Enter the term you would like to search all songs for: ";
		getline(cin, userinput);
		//this is where the inverted index search function would be
	}
	else if(userChoice == 3)
	{
		cout << "1) Add new song\n2)Delete existing song\n3)Edit existing song\n\n";
		cin >> userChoice;
		if(userChoice == 1)
		{
			char confirm;
			string newTitle;
			string newAlbum;
			string newDate;//this one requires an sstream function to pick apart the fields
			string newYear;
			string newMonth;
			string newDay;
			string lyrics;
			string onChart;
			string length;
			string views;
			string fulllyrics;
			cout << "Please fill in as many fields as possible. If you do not know one of the fields, please leave it blank." <<endl;
			cout << "Enter the new songs title: ";
			getline(cin, newTitle);
			cin.ignore();
			cout <<endl << "Enter the new songs album: ";
			getline(cin, newAlbum);
			cin.ignore();
			cout <<endl << "Enter the new songs release date: ";
			getline(cin, newDate);
			cin.ignore();
			//function call here to pick apart the date and assign the year month and day
			cout << endl << "Enter the new songs lyrics: " <<endl;
			while(getline(cin, lyrics))
			{
				fulllyrics += lyrics;
				fulllyrics.push_back('\n');
			}
			cin.ignore();
			cout <<endl << "Enter true if the song was on chart or false if it was not: "; //i dont know what chart so someone fix that
			cin >> onChart;
			cout << endl <<"Enter the length of the song in format mm:ss : ";
			cin >> length;
			cout <<endl << "Enter the amount of views the song has on youtube: ";
			cin >> views;
			do
			{
				cout <<endl <<endl <<"Are these field correct? y/n " <<endl;
				cout << "Title: " << newTitle <<endl;
				cout << "Album: " << newAlbum <<endl;
				cout << "Release Data: " << newDate <<endl;
				cout << "On Chart: " << onChart <<endl;
				cout << "Length: " << length <<endl;
				cout << "Youtube Views: " << views << endl;
				cin >> confirm;
				while(confirm == 'n')
				{
					//put a menu here asking which field the user wants to change then change the field
				}
			}while(confirm != 'y');
			//this is where the write to file function would be which would take all those fields as parameters;
		}
		else if(userChoice == 2)
		{
			char confirm;
			int userchoice3;
			int userChoice2;
			string userinput2;
			cout << "Choose how you would like to search for a song to delete: " <<endl <<"1) Search by field\n2) Search by keyword\n";
			cin >> userchoice3;
			if(userchoice3 == 1)
			{
				// search menu
						cout << "1) Search by Title\n2) Search by Album\n3) Search by Release Date\n";
						cout << "\n\nEnter the number of your choice: ";
						//*INPUT INT*
						cin >> userChoice2;
						if(userChoice2 == 1)// search screen (be sure to adjust these for each input type if necessary)
						{
							cout <<endl << "Enter the song title: ";
							cin.ignore();
							getline(cin, userinput2);
							readIn(inputFile, 1, H1);
							index = H1.hash(userinput2);
							H1.printResults(cout, index, userinput2, 1, found);
							if(!found)
							{
								cout << "No songs matching Title" <<endl <<endl;
							}
							found = 0;
						}
						else if(userChoice2 == 2)
						{
							cout << "Enter the songs Album: ";
							getline(cin, userinput2);
							readIn(inputFile, 2 , H1);
							index = H1.hash(userinput2);
							H1.printResults(cout, index, userinput2, 2, found);
							if(!found)
							{
								cout << "No songs matching Album" <<endl <<endl;
							}
							found = 0;
						}
						else if(userChoice2 == 3)
						{
							cout << "1) Search by release year\n2) Search by release month\n";
							cout << "Enter the number of your choice: ";
							cin >> userChoice2;
							if(userChoice2 == 1)
							{
								cout << "Enter the songs release year: ";
								cin >> userinput2;
								readIn(inputFile, 3, H1);
								H1.hash(userinput2);
								H1.printResults(cout, index, userinput2, 3, found);
								if(!found)
								{
									cout << "No songs matching Year" <<endl <<endl;
								}
								found = 0;
							}
							else if(userChoice2 == 2)
							{
								cout << "Enter the songs release month: ";
								cin >> userinput2;
								readIn(inputFile, 4, H1);
								index = H1.hash(userinput2);
								H1.printResults(cout, index, userinput2, 4, found);
								if(!found)
								{
									cout << "No songs matching release month" <<endl <<endl;
								}
								found = 0;
							}
						}
						while(!found)
						{
						cout << "Enter the title of the song you would like more information on or enter q to return to the main menu: ";
						getline(cin, userinput2);
						cout << endl;
						if(userinput == "q")
						{
							userChoice2 = 0;
							userinput2 = " ";
							break;
						}
						H1.getFullResults(cout, index, userinput2, found);
						if(!found)
						{
							cout << "Please enter a valid title from the search results" <<endl;
						}
						}
						cout << "Is this the song you wish to delete? y/n ";
						cin >> confirm;
						if(confirm == 'y')
						{
							//this is also the function to save to the file at the end
							//create a song object here putting the userinput as the song title and pass it to delete
							//remove the data from the node
							//write hashtable to file
							cout << "Don't mess with this one too much without having backups because the trunc function deletes the entire songs.txt content";
							ofstream outputFile;
							outputFile.open("Songs.txt", ofstream::out | ofstream::trunc);
							outputFile.close();
							outputFile.open("Songs.txt");
							//this is where the function should write the hash table to the file
							for(int i = 0; i < 30; i++)
							{
								H1.printBucket(outputFile, i);
							}
							outputFile.close();
						}
			}
		}
	}



	H1.~HashTable();
	}
}
