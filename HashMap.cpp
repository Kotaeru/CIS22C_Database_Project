/*
#include "wordID.h"
#include<string>
#include<iostream>

class HashMap{

private:
	static const int SIZE = 1000;
	wordID **table;

public:
      HashMap(){
          table = new wordID*[SIZE];
          for (int i = 0; i < SIZE; i++)
                table[i] = NULL;

      }

      int hash(string key){
        	int index;
        	int sum = 0;
        	for (unsigned i = 0; i < key.length(); i++) {
        		sum += (int) key[i];
        	}
        	index = sum % SIZE;
        	return index;

      }

      int get(string key){
          int index = hash(key);
          while (table[index] != NULL && table[index]->getKey() != key)
          	index = (index + 1) % SIZE;
          if (table[index] == NULL)
                return -1;
          else
                return table[index]->getID();

      }

      void insert(string key, int value){
          int index = hash(key);
          while (table[index] != NULL && table[index]->getKey() != key)
          	index = (index + 1) % SIZE;
          if (table[index] != NULL)
                delete table[index];
          table[index] = new wordID(key, value);

      }

};

*/
