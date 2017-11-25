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

int HashTable::search(Song S) const
{
	int index = hash(S.getName());
	if(Table[index].search(S) == false)
	{
		return -1;
	}
	else if(Table[index].search(S) == true)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

void HashTable::insert(Song S)
{
	int index = hash(S.getName());

		Table[index].insert(S);

}

void HashTable::remove(Song S)
{
	int index = hash(S.getName());

		bool found = Table[index].search(S);

		if(found)
		{
			Table[index].remove(S);
		}
		else
		{
			cout << "Song is not there";
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
		//Everything commented out here needs to be modified for the song class
		Song S = Table[i].getRoot();
		//out << "Books in Catalouge" <<endl <<endl;
		//out << "Group: " << i+1 << endl;
		out << S.getName() << " by Michael Jackson" <<endl;
		//out << "$"  << B.get_price() <<endl;
		//out << "ISBN: " << B.get_isbn() <<endl;
		//out << "+ " << Table[i].getSize()-1 << " many more similar books" << endl <<endl;
	}
}


