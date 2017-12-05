/*
 * wordID.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: Kyle
 */

#include "wordID.h"

using namespace std;

wordID::wordID()
{
	key = "";
	id = -1;
}

wordID::wordID(string Key, int ID)
{
	key = Key;
	id =ID;
}

string wordID::getKey() const
{
	return key;
}

int wordID::getID() const
{
	return id;
}

void wordID::setID(int ID)
{
	id = ID;
}

void wordID::setKey(string Key)
{
	key = Key;
}

bool wordID::operator ==(const wordID& word)
{
	return(key == word.key);
}

bool wordID::operator <(const wordID& word)
{
	return(key < word.key);
}

bool wordID::operator >(const wordID& word)
{
	return(key > word.key);
}



