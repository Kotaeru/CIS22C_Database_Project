/*
 * readOut.h
 *
 *  Created on: Dec 6, 2017
 *      Author: Kyle
 */

#ifndef READOUT_H_
#define READOUT_H_

#include <iostream>
#include <fstream>
#include "BST.h"

void readOut(BST<Song> B1)
{
	ofstream outfile;
	outfile.open("Songs.txt", ios::trunc);
	B1.OrderPrint(outfile);
	outfile.close();
}



#endif /* READOUT_H_ */
