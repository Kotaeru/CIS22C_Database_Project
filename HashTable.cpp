/*
 * HashTable.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: Kyle
 */

#include "HashTable.h"

#include<iostream>


HashTable::HashTable() //constructor
{
/*
	for(int i = 0; i < SIZE; i++) //fills the hashtable with nodes that contain empty values
	{
		//Book tempBook = Book("Empty", "Empty", -1, 0);
		Table[i].insert(Book("Empty", "Empty", -1, 0));
	}

*/
}

HashTable::~HashTable() //constructor
{


}

//Converts the key to an ASCII value to use for index
int HashTable:: hash(string key) const
{
	int index, sum = 0;
	    for(unsigned i = 0; i < key.length(); i++)
	        sum += (int) key[i]; //summing the ASCII values for each character in the string
	    index = sum % SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
	    return index;

}

int HashTable::countBucket(int index) const
{
	assert(index >= 0 && index < SIZE);
	return Table[index].getSize();
}

int HashTable::search(Song b) const
{
	Song A;
	int index = hash(b.getName());
	if(Table[index].search(b, A) == false)
	{
		return -1;
	}
	else if(Table[index].search(b, A) == true)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

void HashTable::insert(Song b)
{
	int index = hash(b.getName());

		Table[index].insert(b, cout);

}

void HashTable::remove(Song b)
{
	int index = hash(b.getName());
	Song A;
		bool found = Table[index].search(b, A);

		if(found)
		{
			Table[index].remove(b);
		}
		else
		{
			cout << "thebook is not there";
		}
}

void HashTable::printBucket(ostream& out, int index) const
{
	Table[index].inOrderPrint(out);
}

void HashTable::printTable(ostream &out) const
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

void HashTable::printResults(ostream &out, int index, string search, int& found)
{
	Table[index].results(search, out, found);
}

void HashTable::getFullResults(ostream &out, int index, string search, int& found)
{
	Table[index].getFullResults(search, out, found);
}

void HashTable::insertAtIndex(Song S, int index)
{
	Table[index].insert(S, cout);
}


