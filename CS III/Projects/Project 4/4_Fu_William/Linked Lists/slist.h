/****************
William Fu
Comp Sci 241
Project 4
Betsy Sanders
****************/
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

#include "DataType.h"

class Slist {
public:
//// public member functions:

	Slist (void);					//// constructor, destructor
	~Slist (void);

									//// mutators

	void insert (const dataType& newItem);	// insert new item after current
	bool remove (void);						// remove item
	void clean (void);						// remove all items

	bool move (void);						// move to next item
	void moveToEnd (void);					// move to end of list
	void reset (void);						// return to beginning of list

									//// accessors

	bool empty (void) const;				// is list empty?
	bool get (dataType& item) const;		// get current item
	void printDEBUG (void) const;			// print all items [DEBUG]


	//Added 7 Functions
	//Checkpoint
	bool append(Slist& other);
	bool prepend(Slist& other);
	//Full
	bool rotateLeft(unsigned n);
	bool rotateRight(unsigned n);
	int length();
	bool truncate(const dataType &item);
	void reverse(void);

private:
//// private data

	struct Node;		// (pure declaration --- not a definition)
	Node *head, *tail, *cursor;

//// private member function:

	void printDEBUG (const Node *thisNode) const;
};

#endif // SLIST_H_INCLUDED
