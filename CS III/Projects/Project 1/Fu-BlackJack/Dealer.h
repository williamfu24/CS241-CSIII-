/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED

#include<iostream>
using namespace std;

#include "Player.h"

class Dealer: public Player
{
    public:
        void dealerHit(); //decides to hit or not for dealer

};



#endif // DEALER_H_INCLUDED
