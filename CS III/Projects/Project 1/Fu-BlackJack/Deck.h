/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include<iostream>
using namespace std;

#include<vector>
#include "Hand.h"

class Deck: public Hand{
private:
    vector <Card> vectordeck;
public:
    //Deck();
    void initDeck(); /*Initialized deck of 52 cards*/
    void shuffle(); //shuffles
    Card deal(); //deals

    /* friend outstream operator to verify deck?*/
    void verifyDeck();
};


#endif // DECK_H_INCLUDED
