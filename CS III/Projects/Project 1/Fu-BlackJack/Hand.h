/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include<iostream>
using namespace std;

#include "Card.h"
#include<vector>

class Hand{
protected: /* protected is usually used for base class; For protected inheritance (access from friends of class*/
    vector<Card> vectorhand; /* Creates an empty vector "Card"=ElementType, "vectorhand"=objectName*/
public:
    Hand();
    void clear(); //clears the hand
    void add(Card c); //adds a card to hand
    int getTotal() const; //gets the total of hand
    void printHand(int a) const; //prints out the hand
};


#endif // HAND_H_INCLUDED
