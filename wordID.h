/*
 * wordID.h
 *
 *  Created on: Dec 4, 2017
 *      Author: Kyle
 */

#ifndef WORDID_H_
#define WORDID_H_
#include<iostream>

using namespace std;

class wordID
{
private:
	string key;
	int id;
public:
	wordID();
	wordID(string Key, int ID);

	string getKey() const;
	int getID() const;

	//manipulation functions
	void setKey(string Key);
	void setID(int ID);

	//other functions

	bool operator==(const wordID& word);

	bool operator<(const wordID& word);

	bool operator>(const wordID& word);
};




#endif /* WORDID_H_ */
