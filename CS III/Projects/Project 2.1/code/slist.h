#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

#include <iostream>
using namespace std;

#include "node.h";

class slist
{
public:
    slist();
    ~slist();
    void printMe() const;
    void slistAppend(dataType data);

private:
    node*head;
    void printAux(node*curr)const;
};

#endif // SLIST_H_INCLUDED
