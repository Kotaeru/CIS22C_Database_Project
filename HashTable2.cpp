/*
 * HashTable.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: Kyle
 */

#include "HashTable2.h"

#include<iostream>
#include<sstream>


HashTable2::HashTable2() //constructor
{
/*
	for(int i = 0; i < SIZE; i++) //fills the hashtable with nodes that contain empty values
	{
		//Book tempBook = Book("Empty", "Empty", -1, 0);
		Table[i].insert(Book("Empty", "Empty", -1, 0));
	}

*/
}

HashTable2::~HashTable2() //constructor
{


}

//Converts the key to an ASCII value to use for index
int HashTable2:: hash(string key) const
{
	int index, sum = 0;
	    for(unsigned i = 0; i < key.length(); i++)
	        sum += (int) key[i]; //summing the ASCII values for each character in the string
	    index = sum % SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
	    return index;

}

int HashTable2::countBucket(int index) const
{
	assert(index >= 0 && index < SIZE);
	return Table[index].getSize();
}

int HashTable2::search(Song b)
{
	Song A;
	int index = hash(b.getName());
	if(Table[index].search(b) == false)
	{
		return -1;
	}
	else if(Table[index].search(b) == true)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

void HashTable2::insert(Song b, int& counter, HashMap &HM)
{

	wordID WI;
	string s;
	string s1;
	string title = b.getName();
	string album = b.getAlbum();
	string year = b.getYear();
	string month = b.getMonth();
	string day = b.getDay();
	string lyrics = b.getLyrics();
	string length = b.getLength();
	string views = b.getViews();
	s = title + " " + album + " " + year + " " + month + " " + day + " " + lyrics + " " + length + " " + views;
	stringstream ss1(s);
	while(ss1 >> s1)
	{
		WI.setKey(s1);
		HM.insert(counter, WI);
		cout << "Inserting at index " << HM.get(WI) <<endl;
		Table[HM.get(WI)].insert(b);
	}
}

void HashTable2::remove(Song b, HashMap &HM)
{
	wordID WI;
		string s;
		string s1;
		string title = b.getName();
		cout << title <<endl;
		string album = b.getAlbum();
		cout << album <<endl;
		string year = b.getYear();
		cout << year <<endl;
		string month = b.getMonth();
		cout << month <<endl;
		string day = b.getDay();
		cout << day <<endl;
		string lyrics = b.getLyrics();
		cout << lyrics <<endl;
		string length = b.getLength();
		cout << length <<endl;
		string views = b.getViews();
		cout << views <<endl;
		s = title + " " + album + " " + year + " " + month + " " + day + " " + lyrics + " " + length + " " + views;
		cout << s <<endl <<endl;
		system("pause");
		stringstream ss1(s);
		while(ss1 >> s1)
		{
			WI.setKey(s1);
			HM.get(WI);

			cout << "word to index remove " << WI.getKey() <<endl;
			cout << "removing from index " << HM.get(WI) <<endl;
			Table[HM.get(WI)].remove(b);
			cout << "Table is now: " <<endl;
			Table[HM.get(WI)].inOrderPrint(cout);
			cout << endl;
		}
}

void HashTable2::printBucket(ostream& out, int index) const
{
	Table[index].inOrderPrint(out);
}

void HashTable2::printTable(ostream &out) const
{
	for(int i = 0; i < SIZE; i++)
	{
		Song B = Table[i].getRoot();
		out << "Songs in Catalouge" <<endl <<endl;
		out << "Group: " << i+1 << endl;
		out << B.getName() << endl;
		out << B.getAlbum();
		out << B.getDate();
		//out << "+ " << Table[i].getSize()-1 << " many more similar books" << endl <<endl;
	}
}

void HashTable2::printResults(ostream &out, int index, string search)
{
	Table[index].inOrderPrint(cout);
}

void HashTable2::getFullResults(ostream &out, int index, string search)
{
	Table[index].getFullResults(search, out);
}

