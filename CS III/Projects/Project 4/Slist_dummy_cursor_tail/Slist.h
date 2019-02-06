// FILE: Slist.h
// B Sanders, Rhodes College
// CS 241, Fall 2012
//
//		Interface: singly linked list
//

#ifndef	SLIST_H
#define	SLIST_H

#include "DataType.h"

class Slist {
public:
//// public member functions:	

	Slist (void);					//// constructor, destructor
	~Slist (void);

									//// mutators
	
	void insert (const DataType& newItem);	// insert new item after current
	bool remove (void);						// remove item
	void clean (void);						// remove all items

	bool move (void);						// move to next item
	void moveToEnd (void);					// move to end of list
	void reset (void);						// return to beginning of list

									//// accessors
	
	bool empty (void) const;				// is list empty?
	bool get (DataType& item) const;		// get current item
	void printDEBUG (void) const;			// print all items [DEBUG]

private:
//// private data

	struct Node;		// (pure declaration --- not a definition)
	Node *head, *tail, *cursor;

//// private member function:

	void printDEBUG (const Node *thisNode) const;
};

#endif