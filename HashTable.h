/*
 * HashTable.h
 *
 *  Created on: Nov 10, 2017
 *      Author: Maya
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include "Song.h"

using namespace std;

class HashTable {
public:
    /**Constructors*/

    HashTable();
    //constructor

    ~HashTable();
    //destructor


    /**Access Functions*/

    int hash(string key) const;

    int countBucket(int index) const;

    int search(Song b) const; //We need to discuss this one on Friday

    /**Manipulation Procedures*/

    void insert(Song S);
    //inserts a new book into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void remove(Song S);

    /**Additional Functions*/

    void printBucket(ostream& out, int index) const;

    void printTable(ostream& out) const;

private:
    static const int SIZE = 15;

};

#endif /* HASHTABLE_H_ */
