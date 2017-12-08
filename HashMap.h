/*
 * HashMap.h
 *
 *  Created on: Dec 4, 2017
 *      Author: Maya
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_

//Creates the wordID hashTable
#include "wordID.h"
#include<string>
#include<iostream>
#include "BST.h"
class HashMap{

private:
	static const int SIZE = 30;
	BST<wordID> Table[SIZE];

public:
	int get(wordID w);
	int hash(string key);
	void insert(int &idcount,wordID w);
	HashMap();
	~HashMap();

};




#endif /* HASHMAP_H_ */
