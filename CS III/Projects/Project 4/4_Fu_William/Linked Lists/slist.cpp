/****************
William Fu
Comp Sci 241
Project 4
Betsy Sanders
****************/
#include <iostream>
#include "slist.h"
using namespace std;

//////// private data type: Node ////////

struct Slist::Node {

// Node constructors

	Node (void) {
		next = 0;
	}
	Node (const dataType& newItem) {
		dataItem = newItem;
		next = 0;
	}

// Node data

	dataType	dataItem;
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
void Slist::insert (const dataType& newItem) {
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
bool Slist::get (dataType& item) const {
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



//////////////////////////////////////////Project Add-ons////////////////////////////////////////////////////
//Append a copy of another list to the end of this list.
//A list cannot be appended to itself
bool Slist::append(Slist& other)// just changes the tail of the original list to have a next of the first element from the new list. find new end and set it as the new tail
{
    if(other.empty()==true)
        return true;
    reset();
    other.reset();
    if (this->head->next==other.head->next)
        return false;
    tail->next=other.head->next;
    tail=other.tail;
    return true;
}

//Prepend a copy of another list to the beginning of this list.
 //A list cannot be appended to itself
bool Slist::prepend(Slist& other) //finds the tail of the new list and sets its next to the first element of the original list. new lists head is now the originals head
{
    if(other.empty()==true)
        return true;
    if (this->head->next==other.head->next)
        return false;
    other.tail->next=head->next;
    head=other.head;
    return true;
}

//Rest of the functions

//Rotate Left
bool Slist::rotateLeft(unsigned n) //finds first and second elements. second becomes new heads next. then uses temp to find the last item whose next becomes the first
{                                   //with the first becoming the tail and its next being null
    if(n>=length())
    {
        if(length()%n==0)
        {
            return false;
        }
        else
        {
            n=length() % n;
        }
    }
    Node *temp = head;
    Node *moved=head;
    int x=0;
    while(x<n)
    {
        temp=head;
        moved=temp->next;
        head->next=moved->next;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=moved;
        moved->next=NULL;
        tail=moved;
        x++;
    }
    return true;
}
//Rotate Right
bool Slist::rotateRight(unsigned n)//finds the last and second to last elements in list. sets the second to last element to the new last and the
{                                   //old last is pointed to head's next and then becomes head's new next
    if(n >=length())
    {
        if(length() % n == 0)
            return false;
        else
            n = Slist::length() % n;
    }
    int x=0;
    Node *temp=head;
    Node *moved=head;
    while (x<n)
    {
        temp=head;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        moved=temp;
        temp=temp->next;
        tail=moved;
        tail->next=NULL;
        temp->next=head->next;
        head->next=temp;
        x++;
    }
    return true;
}

//Length to find the length of the linked list
int Slist::length() //simple. cursor at head, move to skip dummy. move cursor to tail counting each loop and then one more cause it doesnt count when cursor becomes tail
{
    int x=0;
    reset();
    move();
    if (cursor==tail)
        return 0;
    while(cursor != tail)
    {
        x++;
        move();
    }
    x++;
    return x;
}

//Truncate
bool Slist::truncate(const dataType& item) //The main test ask for anything after the first instance to be deleted but the handout says to include the first instance
{                                          //I decided to follow the main test. Can be changed to follow handout by having i<n-1 in for loop
    Node *temp=head;
    bool present = false;
    unsigned n = 1;
    while(temp!=NULL && present == false)
    {
        if(item == temp->dataItem)
           {
               present = true;
               break;
           }
        n++;
        temp = temp->next;
    }
    if (present == false)
    {
        return false;
    }
    reset();
    for (int i=1;i<n;i++)
    {
        move();
    }
    tail=cursor;
    tail->next=NULL;
    return true;
}

//Reverse
void Slist::reverse()//Make a new linkedlist with the cursor staying at the head. Then run through the original inserting in new list. Because cursor
{                   // doesnt move then the new item each iteration will be inserted before the element before it. automatic reverse
    Node *temp = head->next;
    Slist hold;
    while(temp!=NULL)
    {
        hold.insert(temp->dataItem);
        temp = temp->next;
    }
    clean();
    append(hold);

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
