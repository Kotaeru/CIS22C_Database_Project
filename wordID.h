/*
 * wordID.h
 *
 *  Created on: Nov 29, 2017
 *      Author: Maya
 */

#ifndef WORDID_H_
#define WORDID_H_


#include <string>

namespace std {

class wordID {

private:
		string lyricword;
				int id;

public:

			wordID(){lyricword="Empty"; id=-1;}

			wordID(string lw, int identification)
			{
				lyricword=lw;
				id=identification;
			}

			~wordID(){}
			int getValue()
			{
				return id;
			}
			string getKey()
			{return lyricword;}

			void setKey(string Key)
			{lyricword = Key;}

			void setID(int ID)
			{
				id = ID;
			}

			bool operator>(wordID &wori)
			{
				return (lyricword >wori.lyricword );
			}
			bool operator<(wordID &wori)
				{
					return (lyricword <wori.lyricword );
				}
			bool operator==(wordID &wori)
				{
					return (lyricword ==wori.lyricword );
				}
	};


} /* namespace std */

#endif /* WORDID_H_ */
