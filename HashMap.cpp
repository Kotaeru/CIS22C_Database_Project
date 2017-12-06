/*
 * HashMap.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: Kyle
 */

#include<iostream>
#include "HashMap.h"

using namespace std;

HashMap:: HashMap(){




      }
HashMap:: ~HashMap()
{}

int HashMap:: hash(string key){
    int index;
    int sum = 0;
    for (unsigned i = 0; i < key.length(); i++) {
   	sum += (int) key[i];
    }
       index = sum % SIZE;
        return index;

    }

      int HashMap:: get(wordID w){
          int index = hash(w.getKey());

        if(Table[index].search(w))//if the word is in the table
        {
        	Table[index].search(w);
        	return w.getValue();//this has to be the actual id from the table
        }
        else
        {
        	return -1;
        }
      }

      void HashMap:: insert(int &idcount, wordID w){
          int index = hash(w.getKey());
          if(Table[index].search(w)==1)//if the word is already in the table go back
          {
        	  return;
          }
          else//if the song is not in the table
          {
        	  w.setID(idcount);//set its id to idcount which should be increasing
        	  Table[index].insert(w);//insert the object into the table
        	  idcount++;//increase idcount
        	  return;
          }

        //  if(!Table[index].isEmpty())
        //  {
         // Table[index].insert(wordID(w.getKey(), w.getValue()));
         // idcount++;
         // }

      }


