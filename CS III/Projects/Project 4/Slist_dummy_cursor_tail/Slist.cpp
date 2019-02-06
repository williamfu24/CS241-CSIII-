// FILE: Slist.cpp
// B Sanders, Rhodes College
// CS 241, Fall 2012
//
//		Implementation: singly linked list
//
//		Class invariants:
//			- head, tail, and cursor are nonzero
//			- head points at empty head node
//			- tail points at last node
//			- last node has zero next pointer

#include	"Slist.h"
#include	<iostream>
using namespace std;


//////// private data type: Node ////////

struct Slist::Node {

// Node constructors

	Node (void) {
		next = 0;
	}
	Node (const DataType& newItem) {
		dataItem = newItem;
		next = 0;
	}

// Node data
	
	DataType	dataItem;
	Node		*next;
};


//////// public member functions ////////

//// constructor, destructor
Slist::Slist (void) {
	tail = cursor = head = new Node;
}

Slist::~Slist (void) {
	clean ();
	delete head;
}

//// mutators

// insert
//		insert newItem after cursor node
void Slist::insert (const DataType& newItem) {
	Node *pNewNode = new Node (newItem);
	pNewNode -> next = cursor -> next;
	if ((pNewNode -> next) == 0) {
		tail = pNewNode;
	}
	cursor -> next = pNewNode;
}

// remove
//		delete node following cursor node
bool Slist::remove (void) {
	Node *temp = cursor -> next;
	if (temp) {
		if (temp == tail) {
			tail = cursor;
		}
		cursor -> next = cursor -> next -> next;
		delete temp;
		return true;
	}
	return false;
}

// clean
//		delete all nodes
void Slist::clean (void) {
	reset ();
	while (remove ()) {
	}
}

// move
//		move cursor to next node
bool Slist::move (void) {
	if (cursor -> next) {
		cursor = cursor -> next;
		return true;
	}
	return false;
}

// moveToEnd
//		set cursor to point to tail node
void Slist::moveToEnd (void) {
	 cursor = tail; 
}

// reset
//		set cursor to point to empty head node
void Slist::reset (void) {
	 cursor = head; 
}



//// accessors

// empty
//		return true if list is empty; false otherwise
bool Slist::empty (void) const { 
	return (head == tail); 
}

// get
//		retrieve data item in node after cursor node
bool Slist::get (DataType& item) const {
	if (cursor -> next) {
		item = cursor -> next -> dataItem;
		return true;
	}
	return false;
}

// printDEBUG	[public wrapper]
//		print all items of the list
//		[for debugging ONLY --- application would normally control all output!]
void Slist::printDEBUG (void) const {
	printDEBUG (head -> next);
}



//////// private member function ////////

// printDEBUG	[private accessor]
//		print data item stored in thisNode and beyond
void Slist::printDEBUG (const Node *thisNode) const {
	if (thisNode) {
		cout << thisNode -> dataItem << ' ';
		printDEBUG (thisNode -> next);
	}
}
