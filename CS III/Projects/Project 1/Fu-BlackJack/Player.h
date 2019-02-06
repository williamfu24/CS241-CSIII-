/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include "Deck.h"

using namespace std;

class Player: public Hand /*allows the inheritance of Hand class*/
{
private:
    string Name;
    bool Busted;
    int Bank;

public:
    Player();
    Hand h;
    bool Decision; //the players decision
    bool isBusted(); //checks if player has busted
    void hitMe(); //Does the player want to get hit?
    void hit(); //Hit the player
    void who(); //who is the player and how much money do they start with?
    void myName(); //cout's the name of the player
    int Bet(); //asks the player how much they want to bet
    void winBet(int x); //the winnings go into player bank
    void showBank(); //shows the players bank


};



#endif // PLAYER_H_INCLUDED
