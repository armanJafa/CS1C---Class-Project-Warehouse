/**************************************************************************
 * AUTHOR        : Jacob Mc'Iver
 * STUDENT ID    : 265933
 * Assignment #  : Group Project
 * CLASS         : MW 12:30pm - 4:20pm
 * SECTION       : CS1C
 * DUE DATE      : 3//2015
 **************************************************************************/

#ifndef MEMBERLIST_H_
#define MEMBERLIST_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "Preferred.h"

using namespace std;

class MemberList
{
public:

	/*METHODS*/

	MemberList();
	~MemberList();
	void CreateList();
//	void DeleteMember(string deleteName);
	Basic *SearchMember(int userId)const;
	Basic *GetHead()const;

private:

	Basic* head;

};

#endif /* MEMBERLIST_H_ */
