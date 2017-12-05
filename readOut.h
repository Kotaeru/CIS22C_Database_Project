/*
 * betterReadIn.h
 *
 *  Created on: Dec 3, 2017
 *      Author: Kyle
 */

#ifndef READOUT_H_
#define READOUT_H_

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include "HashTable.h"
#include "BST.h"
#include "Song.h"

using namespace std;

void readOut(Song S1)
{
	string path = ".\\Group_8_Songs\\";
	string fullFileName = path + "Song_" + S1.getName() + ".txt";
	cout << "Writing to " << fullFileName <<endl <<endl;
	ofstream out(fullFileName);
	out << S1.getName() << ";" <<S1.getAlbum() << ";" << S1.getYear() << ";" << S1.getMonth() << ";" << S1.getDay() <<";" <<endl;
	out << S1.getLyrics() << ";" << S1.isOnChart() << ";" << S1.getLength() << ";" << S1.getViews() << ";";
	out.close();
	return;
}



#endif /* READOUT_H_ */
