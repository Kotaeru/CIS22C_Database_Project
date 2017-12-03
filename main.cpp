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
	HashTable H1;
	int userChoice;
	string userinput;
	ifstream inputFile;
	int index;
	inputFile.open("Songs.txt");
cout << "Welcome!\n\n";
cout << "1) Search\n2) Add or Delete\n3) Song Statistics\n\n";
cout << "Enter the number of your choice: ";
//*INPUT INT*
cin >> userChoice;
cout << "\n\n";

if(userChoice == 1)
{
// search menu
cout << "1) Search by Title\n2) Search by Album\n3) Search by Release Date\n4) Search by Lyrics";
cout << "\n\nEnter the number of your choice: ";
//*INPUT INT*
cin >> userChoice;
cout << "\n\n";
if(userChoice == 1)
// search screen (be sure to adjust these for each input type if necessary)
{
	cout << "Enter the song title: ";
	getline(cin, userinput);
	readIn(inputFile, 1, H1);
	index = H1.hash(userinput);
	H1.printResults(cout, index, userinput, 1);
}

// song info screen
cout << "Title: "; //<< *TITLE* << "\nAlbum: " << *ALBUM* << "\nRelease Date: " << *RELEASE DATE* << "\nLyrics: " << *LYRICS*;
cout << "\n\nGo back to main menu? Y/N: ";
//*INPUT CHOICE*
cout << "\n\n";
}


// add/delete menu
cout << "1) Add a new song\n2) Delete an existing song\n\n";
cout << "Please enter the number of your choice: ";
//*INPUT INT*
cout << "\n\n";

// add menu (please edit in the getline())
cout << "Title?: ";
//*INPUT NEXT LINE*
cout << "\nAlbum?: ";
//*INPUT NEXT LINE*
cout << "\nRelease Date?: ";
//*INPUT NEXT LINE*
cout << "\nLyrics?: ";
//*INPUT NEXT LINE*
cout << "\n\n";

// add confirmation screen
cout << "Title: "; //<< *TITLE* << "\nAlbum: " << *ALBUM* << "\nRelease Date: " << *RELEASE DATE* << "\nLyrics: " << *LYRICS*;
cout << "\n\nAre these fields correct? Y/N: ";
//*INPUT CHOICE*
cout << "\n\nGo back to main menu? Y/N: ";
//*INPUT CHOICE*
cout << "\n\n";


// delete menu (currently identical to "search menu"; use same menu?)
cout << "1) Search by title\n2) Search by album\n3) Search by Release Date\n4) Search by lyrics";
cout << "\n\nEnter the number of your choice: ";
//*INPUT INT*
cout << "\n\n";

// delete search screen (currently identical to "search screen"? use same menu)
cout << "Enter the title/album/date/lyrics: ";
cout << "\n\n";
cout << "Results for (user input):\n";
cout << "1) "; //<< *SEARCH RESULTS*; //edit later
cout << "2) "; //<< *SEARCH RESULTS*; //so on and so forth for the rest
cout << "\n\nEnter the number of the song you would like more information on: ";
//*INPUT INT*
cout << "\n\n";

// delete confirmation screen
cout << "Title: "; //<< *TITLE* << "\nAlbum: " << *ALBUM* << "\nRelease Date: " << *RELEASE DATE* << "\nLyrics: " << *LYRICS*;
cout << "\n\nConfirm deletion? Y/N: ";
//*INPUT CHOICE*
cout << "\n\nGo back to main menu? Y/N: ";
//*INPUT CHOICE*
cout << "\n\n";



// stat search menu (currently identical to "search menu")
cout << "1) Search by Title\n2) Search by Album\n3) Search by Release Date\n4) Search by Lyrics";
cout << "\n\nEnter the number of your choice: ";
//*INPUT INT*
cout << "\n\n";

// stat search screen (currently identical to "search screen")
cout << "Enter the title/album/date/lyrics: ";
cout << "\n\n";
cout << "Results for (user input):\n";
cout << "1) "; //<< *SEARCH RESULTS*; //edit later
cout << "2) "; //<< *SEARCH RESULTS*; //so on and so forth for the rest
cout << "\n\nEnter the number of the song you would like more information on: ";
//*INPUT INT*
cout << "\n\n";

// song stat screen
//cout << *SONG STATS*;
//cout << *SONG STATS*;
//cout << *SONG STATS*;
//cout << *SONG STATS*;
//cout << "\n\nGo back to main menu? Y/N: ";
//*INPUT CHOICE*
cout << "\n\n";

// ~~~ end of couts ~~~

}
