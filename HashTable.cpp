#include "HashTable.h"
#include "Song.h"

#include<iostream>

using namespace std;


HashTable::HashTable() //constructor
{

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
	int index = hash(b.get_songName());
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

void HashTable::insert(Song s)
{
	int index = hash(s.get_songName() + s.get_songAlbum());

		Table[index].insert(s);

}

void HashTable::remove(Song s)
{
	int index = hash(s.get_songName() + s.get_songAlbum());

		bool found = Table[index].search(s);

		if(found)
		{
			Table[index].remove(s);
		}
		else
		{
			cout << "theSong is not there";
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
		Song S = Table[i].getRoot();
		out << "Songs in Catalouge" <<endl <<endl;
		out << "Group: " << i+1 << endl;
		out << S.get_songName() << " by " << S.get_songAlbum() <<endl;
		out << "+ " << Table[i].getSize()-1 << " many more similar Songs" << endl <<endl;
	}
}


