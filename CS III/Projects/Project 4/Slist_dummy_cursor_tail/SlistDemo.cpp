//	FILE: SlistDemo.cpp
//	B Sanders, Rhodes College
//	CS 241, Fall 2012
//
//		Demo program for singly linked list class Slist
//		NOTE: Several Slist member functions are *not* tested by this driver.

#include	"DataType.h"
#include	"Slist.h"
#include	<iostream>
using namespace std;

const DataType SENTINEL = "X";

////
/// main program
//
int main (void)
{
	Slist		list0, list1, list2;
	DataType	name, tempName;

// create three lists
	cout << "Type a name [" << SENTINEL << " to quit]: ";
	cin >> name;
	while (name != SENTINEL) {
		list0.insert (name);		// first list: at front

		list1.moveToEnd ();			// second list: at back
		list1.insert (name);

		list2.reset ();				// third list: in order
		while (list2.get (tempName) && (tempName < name)) {
			list2.move ();
		}
		list2.insert (name);
		
		cout << "Type another name [" << SENTINEL << " to quit]: ";
		cin >> name;
	}

// print the lists
	cout << endl << "list 0: ";
	list0.printDEBUG ();
	
	cout << endl << "list 1: ";
	list1.printDEBUG ();
	
// (Q: What's up with the list 2 cursor here?)
	cout << endl << endl << "   [ first element of list 2 is ";
	list2.reset ();
	if (list2.get (tempName)) {
		cout << tempName << ' ';
		list2.move ();
	}
	cout << "]" << endl;

	cout << endl << "list 2: ";
	list2.printDEBUG ();

	cout << endl << endl << "   [ remaining elements of list 2 are ";
	while (list2.get (tempName)) {
		cout << tempName << ' ';
		list2.move ();
	}
	cout << "]" << endl << endl;
		
	return 0;
}





/*** SESSION: ***

Type a name [X to quit]: Omar
Type another name [X to quit]: Joe
Type another name [X to quit]: Rosario
Type another name [X to quit]: Mary
Type another name [X to quit]: Bill
Type another name [X to quit]: Candice
Type another name [X to quit]: Tom
Type another name [X to quit]: X

list 0: Tom Candice Bill Mary Rosario Joe Omar
list 1: Omar Joe Rosario Mary Bill Candice Tom

   [ first element of list 2 is Bill ]

list 2: Bill Candice Joe Mary Omar Rosario Tom

   [ remaining elements of list 2 are Candice Joe Mary Omar Rosario Tom ]

Press any key to continue
****************/
