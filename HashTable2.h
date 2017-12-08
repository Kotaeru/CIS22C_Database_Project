/*
 * HashTable.h
 *
 *  Created on: Nov 18, 2017
 *      Author: Maya & Kyle
 */

#ifndef HASHTABLE_H2_
#define HASHTABLE_H2_

#include <string>

#include "Song.h"
#include "BST.h"
#include "wordID.h"
#include "HashMap.h"
using namespace std;

class HashTable2 {
public:
    /**Constructors*/

    HashTable2();
    //constructor

    ~HashTable2();
    //destructor


    /**Access Functions*/

    int hash(string key) const;
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: title + author

    int countBucket(int index) const;
    //counts the number of Books at this index
    //returns the count
    //pre: 0<= index < SIZE

    int search(Song b);
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table

    /**Manipulation Procedures*/

    void insert(Song b, int& counter, HashMap &HM);
    //inserts a new book into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void remove(Song b, HashMap &HM);
    //removes b from the table
    //calls the hash function on the key to determine
    //the correct bucket
    //pre: b is in the table

    /**Additional Functions*/

    void printBucket(ostream& out, int index) const;
    //Prints all the books at index according to inOrderPrint
    //pre: 0<= index < SIZE
    //Should print according to the following formula:
    //Prints each book at that index in the format:
    //<title> by <author>
    //$<X.XX>
    //ISBN#: <isbn>
    //followed by a blank line

    void printTable(ostream& out) const;
    //Prints the first book at each index
    //along with a count of the total books
    //at each index by calling count_bucket
    //as a helper function
    //Prints in the format:
    //Books in the Catalogue:
    //<new line>
    //Group <bucket>
    //<title> by <author>
    //$<X.XX>
    //ISBN: <isbn>
    //+<number of elements at this index> -1 more similar book(s)
    //<new line><new line><new line>


    void printResults(ostream& out, int index, string search);

    void getFullResults(ostream& out, int index, string search);

private:
    static const int SIZE = 10000;
    BST<Song> Table[SIZE];
};



#endif /* HASHTABLE_H2_ */
