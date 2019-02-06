#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
using namespace std;


struct facType
{
    string name;
    int years;
};

typedef facType dataType; //i need away to store both int and string

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
