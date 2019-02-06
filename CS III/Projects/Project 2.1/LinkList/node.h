/***************
William Fu
CS 241
Project 2: Linked List
Professor Sanders
***************/

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
using namespace std;


struct facType //allows the node to store new dataType facType so it holds both a string and an int
{
    string name;
    int years=0;
};

typedef facType dataType;

class node
{
public:
    node (dataType);

    void     setData (dataType);
    void     setNext (node*);

    dataType getData () const;
    node*    getNext () const;

    dataType data;
    node*    next;
};



#endif // NODE_H_INCLUDED
