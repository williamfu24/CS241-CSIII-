/***************
William Fu
CS 241
Project 2: Linked List
Professor Sanders
***************/

#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;

#include "node.h";

class slist
{
public:
    slist();
    ~slist();
    void printMe() const;
    void slistAppend(dataType data);
    void processionAdd(dataType data);
    void directoryAdd(dataType data);

private:
    node*head;
    void printAux(node*curr)const;
};



#endif // SLIST_H_INCLUDED
