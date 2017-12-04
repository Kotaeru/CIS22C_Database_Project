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

HashTable::~HashTable() //destructor
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

int HashTable::search(Song S, int searchType) const
{
	string field;
	if(searchType == 1)
	{
		field = S.getName();
	}
	else if(searchType == 2)
	{
		field = S.getAlbum();
	}
		else if(searchType == 3)
	{
		field = S.getYear();
	}
	else if(searchType == 4)
	{
		field == S.getMonth();
	}
	else if(searchType == 5)
	{
		field = S.getDay();
	}
	else if(searchType == 6)
	{
		field == S.isOnChart();
	}
	else if(searchType == 7)
	{
		field = S.getLength();
	}
	else if(searchType == 8)
	{
		field = S.getViews();
	}
	int index = hash(field);
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

void HashTable::insert(Song S, int searchType)
{
	string field;
	if(searchType == 1)
	{
		field = S.getName();
	}
		else if(searchType == 2)
	{
		field = S.getAlbum();
	}
		else if(searchType == 3)
	{
		field = S.getYear();
	}
	else if(searchType == 4)
	{
		field = S.getMonth();
	}
	else if(searchType == 5)
	{
		field = S.getDay();
	}
	else if(searchType == 6)
	{
		field = S.isOnChart();
	}
	else if(searchType == 7)
	{
		field = S.getLength();
	}
	else if(searchType == 8)
	{
		field = S.getViews();
	}
	int index = hash(field);
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
		cout << "Index " << i <<": ";
		out << S.getName() <<endl;
		//out << "$"  << B.get_price() <<endl;
		//out << "ISBN: " << B.get_isbn() <<endl;
		//out << "+ " << Table[i].getSize()-1 << " many more similar books" << endl <<endl;
	}
}

void HashTable::printResults(ostream &out, int index, string search, int searchType, int& found)
{
	Table[index].results(search, searchType, out, found);
}

void HashTable::getFullResults(ostream &out, int index, string search, int& found)
{
	Table[index].getFullResults(search, out, found);
}


