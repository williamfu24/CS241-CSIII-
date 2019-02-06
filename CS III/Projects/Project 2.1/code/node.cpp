#include "node.h"

node::node (dataType it)
{
//pre-condition:  it is the datum to be stored in the node
//post-condition:  it gets stored in the node

    data = it;
    next = NULL;
}

void node::setData (dataType it)
{
//pre-condition:  it is the datum to be stored in the node
//post-condition:  it gets stored in the node

    data = it;
}

void node::setNext (node* aNode)
{
//pre-condition:  aNode is the address of any existing node
//post-condition:  this node points to aNode

    next = aNode;
}

dataType node::getData () const
{
    return data;
}

node* node::getNext () const
{
//Returns the address of the node that this node points to.

    return next;
}
