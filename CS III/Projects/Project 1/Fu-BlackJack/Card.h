/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include<iostream>
using namespace std;

enum Rank{Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
/*Enum allows you to define a group of constants to integer values. Default is 0 unless otherwise */
const Rank START_RANK=Ace; /*Use for iterating*/
const Rank END_RANK=King;
enum Suit{Clubs, Diamonds, Spades, Hearts};
const Suit START_SUIT=Clubs;
const Suit END_SUIT=Hearts;

class Card{
private: /*Private aspects of a card. Suit and Rank*/
    Rank r;
    Suit s;

public:
    Card();
    int getValue() const; /*const used to make sure function doesnt change private values*/
    void setRank(Rank x);
    void setSuit(Suit y);

    //Friend output stream operator
    friend ostream & operator<<(ostream & out, const Card & c);
};


#endif // CARD_H_INCLUDED
