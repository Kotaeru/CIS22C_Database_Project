/*
 * HashMap.h
 *
 *  Created on: Dec 4, 2017
 *      Author: Kyle
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include<iostream>
#include "wordID.h"
#include "BST.h"
#include "HashTable.h"

using namespace std;

class HashMap
{
private:
	static const int SIZE = 30;
	//wordID **table;
	BST<wordID> Table[SIZE];
	wordID WI;
public:
	HashMap();
	int hash(string key);
	int get(string key);
	void insert(string key, int &value);
};

HashMap::HashMap()
{
   //table = new wordID*[SIZE];
   WI.setKey("");
   WI.setID(-1);
   for (int i = 0; i < SIZE; i++)
   {
   //table[i] = NULL;
   Table[i].insert(WI, cout);
   }
}

int HashMap::hash(string key)
{
   int index;
   int sum = 0;
   for (unsigned i = 0; i < key.length(); i++)
   {
      sum += (int) key[i];
   }
   index = sum % SIZE;
   return index;
}

int HashMap::get(string key)
{
    int index = hash(key);
    wordID W2(key, -1);
    wordID W3(" ", -1);
    if (Table[index].isEmpty())
    return -1;
    else
    Table[index].search(W2, W3);
    return W3.getID();
}

void HashMap::insert(string key, int &value)
{
    int index = hash(key);
    wordID W4(" ", -1);
    wordID W5(key, value);
    wordID W6;
    if (Table[index].getRoot() == W4)
    {
    	Table[index].remove(W4);
    	Table[index].insert(W5, cout);
    	value++;
    }
    else
    {
    	if(Table[index].search(W5, W6) == false)
    	{

    		cout << "Data inserted" << endl;
    	Table[index].insert(W5, cout);
    	value++;
    	}
    	else
    	{
    		cout << "Data already in HashTable" <<endl;
    	}
    }
}



#endif /* HASHMAP_H_ */
