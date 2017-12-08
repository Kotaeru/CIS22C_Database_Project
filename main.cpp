/*
 * main.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: Kyle
 */


#include<iostream>
#include<string>
#include<fstream>
#include "HashTable.h"
#include "HashMap.h"
#include "Song.h"
#include "BST.h"
#include "wordID.h"
#include "HashTable2.h"
#include "readIn.h"
#include "readOut.h"

using namespace std;

int main()
{
	int totalViews = 0;
	int counter = 0;
	int userChoice = 0;
	int userSearchType = 0;
	string userSearch;
	char userLetter;
	Song S1;
	HashTable H1; //standard hashtable sorted by title
	HashTable2 H2; //fancy hashtable thats not sorted in a good way
	HashMap HM; //list of the words and the indexes
	wordID WI;
	BST<Song> B1;
	ifstream infile;
	infile.open("Songs.txt");
	readIn(infile, H1, B1, HM, H2, counter, totalViews);
	infile.close();
	cout << "Welcome!" <<endl;
	//H2.printBucket(cout, 0);
	while(userChoice != 7)
	{
		cout << "1) Search\n2) Add a new song\n3) Delete a song\n4) List songs by title\n5) Data Statistics\n6) Write to file\n7) Quit\n\n";
		cout << "Please enter the number of your choice: ";
		cin >> userChoice;
		cin.ignore();
		if(userChoice == 1)//Search menu
		{
			cout << "1)Search by title\n2)Search by keywords\n\n";
			cout << "Please enter the number of you choice: ";
			cin >> userSearchType;
			if(userSearchType == 1)//Search by title
			{
				cout << "Please enter the title of the song you would like to search for: ";
				cin.ignore();
				getline(cin, userSearch);
				S1.setName(userSearch);
				if(H1.search(S1) == -1)
				{
					cout << "Song not in database!" <<endl;
				}
				else
				{
					H1.printResults(cout, H1.search(S1), userSearch);
					cout << "Would you like to see full song information? y/n ";
					cin >> userLetter;
					if(userLetter == 'y')
					{
						cout << endl <<endl;
						H1.getFullResults(cout, H1.search(S1), userSearch);
					}
				}
			}
			else if(userSearchType == 2)//search by keywords
			{
				cout << "Enter the key word you would like to search for: ";
				cin >> userSearch;
				WI.setKey(userSearch);
				if(HM.get(WI) != -1)
				{
					//HM.insert(counter, WI);
					cout << "Songs containing the word " << userSearch << ":" << endl;
					H2.printBucket(cout, HM.get(WI));
					cout << endl;
				}
				else
				{
					cout << "error finding word" <<endl;
				}
			}
			else
			{
				cout << "Invalid choice, returning to main menu." <<endl;
			}
		}
		else if(userChoice == 2)//Add a new song
		{
			char confirm;
			char confirm2;
			int userstuff;
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
				cout << "YouTube Views: " << views << endl;
				cout <<"Are these field correct? y/n ";
				cin >> confirm;
				if(confirm == 'n')
				{
					cout << "1) Title\n2) Album\n3) ReleaseDate\n4) On Chart\n5) Length\n6) YouTube Views\n\n";
					cout << "Enter the number of the field you would like to edit: ";
					cin >> userstuff;
					if(userstuff == 1)
					{
						cout << "\nEnter the title of the song: ";
						getline(cin, newTitle);
					}
					else if(userstuff == 2)
					{
						cout << "\nEnter the songs album: ";
						getline(cin, newAlbum);
					}
					else if(userstuff == 3)
					{
						cout << "\nEnter the songs release date in format mm/dd/yyyy: ";
						getline(cin, newDate);
					}
					else if(userstuff == 4)
					{
						cout << "\nEnter true if the song was on chart or false if it was not: ";
						cin >> onChart;
					}
					else if(userstuff == 5)
					{
						cout <<"\nEnter the length of the song in format mm:ss : ";
						cin >> length;
					}
					else if(userstuff == 6)
					{
						cout << "\nEnter the amount of views the song has on youtube: ";
						cin >> views;
					}
				}
			}while(confirm != 'y');
			cout << "Would you like to view the inputed lyrics? y/n ";
			cin >> confirm2;
			while(confirm2 == 'y')
			{
				if(confirm2 == 'y')
				{
					cout << lyrics <<endl;
					cout << "Are these lyrics correct? y/n ";
					cin >> confirm2;
					cin.ignore();
					if(confirm2 == 'n')
					{
						cout << "Enter the songs lyrics: ";
						getline(cin, lyrics);
					}
					else if(confirm2 == 'y')
					{
						break;
					}
				}
			}
			newDay = newDate.substr(0, 2);
			newMonth = newDate.substr(3, 2);
			newYear = newDate.substr(6, 4);

			Song S(newTitle, newAlbum, newYear, newMonth, newDay, lyrics, onChart, length, views);
			int views2;
			stringstream ss3(views);
			ss3 >> views2;
			totalViews += views2;
			H1.insert(S);
			B1.insert(S);
			H2.insert(S, counter, HM);
			cout << S.getName() << " successfully added to database." <<endl;
		}
		else if(userChoice == 3)//delete a song
		{
			char confirm;
			while(confirm != 'y' && confirm != 'q')
			{
				cout << "Enter the title of the song you wish to delete or q to return to main menu: ";
				getline(cin, userSearch);
				Song S1;
				S1.setName(userSearch);
				if(userSearch == "q")
				{
					break;
				}
				if(H1.search(S1) == -1)//if its not found
				{
					cout << "Song is not in database." <<endl;
				}
				else//if it is found
				{
					//H1.search(S1);
					cout << S1 << endl;
					//H1.printResults(cout, H1.search(S1), userSearch);
					cout << "Is this the song you wish to remove? y/n ";
					cin >> confirm;
					if(confirm == 'y')
					{
						//cout << H1.search(S1) << endl;
						//cout << "removing from H1 " <<endl;
						H1.remove(S1);
						//cout << "removing from B1 " <<endl;
						B1.remove(S1);
						//cout << "removing from H2 " <<endl;
						H2.remove(S1, HM);
						//system("pause");
					}
					cin.ignore();
				}
			}
		}
		else if(userChoice == 4)//List Songs by title
		{
			B1.inOrderPrint(cout);
		}
		else if(userChoice == 5)//data stats
		{
			cout << "Size of Database: " << B1.getSize() <<endl;
			cout << "Total amount of Youtube Views: " << totalViews << endl;
		}
		else if(userChoice == 6)
		{
			char confirm5;
			B1.inOrderPrint(cout);
			cout << "Would you like to print the table to the file? y/n ";
			cin >> confirm5;
			if(confirm5 == 'y')
			{
				readOut(B1);
			}
		}
		else if(userChoice == 7)
		{
			char confirm6;
			cout << "Are you sure you would like to quit? Table will be written to file if you quit. y/n ";
			cin >> confirm6;
			if(confirm6 == 'y')
			{
				readOut(B1);
				cout << "Goodbye";
				return 0;
			}
		}
		else
		{
			cout << "Please enter a valid option." <<endl;
		}
	}
}

