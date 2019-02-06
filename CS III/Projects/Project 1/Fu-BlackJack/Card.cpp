/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#include<iostream>
#include "Card.h"

/*Lower part defines the functions from header*/
Card::Card(){
    r=Ace;
    s=Clubs;
}

int Card::getValue() const /*accessor; basically if Rank is Jack, Queen or King the value returned is 10 while all others are its numerical value*/
{
    if (r == Jack)
        return 10;
    if (r == Queen)
        return 10;
    if (r == King)
        return 10;
    if (r == Ace)
        return 11;
    return int(r);
}

void Card::setRank(Rank x) /*mutator; changes the rank of a card C*/
{
    r = x; /*r for Rank*/
}

void Card::setSuit(Suit y) /*mutator; changes the suit of a card C*/
{
    s = y; /*s for suit*/
}

/* friend output stream operator; overloads the << operator to print out the rank and suit of a card*/
ostream & operator<<(ostream & out, const Card & c)
{
    if (c.r==1)
        out<<"[A";
    else if (c.r==2)
        out<<"[2";
    else if (c.r==3)
        out<<"[3";
    else if (c.r==4)
        out<<"[4";
    else if (c.r==5)
        out<<"[5";
    else if (c.r==6)
        out<<"[6";
    else if (c.r==7)
        out<<"[7";
    else if (c.r==8)
        out<<"[8";
    else if (c.r==9)
        out<<"[9";
    else if (c.r==10)
        out<<"[10";
    else if (c.r==11)
        out<<"[J";
    else if (c.r==12)
        out<<"[Q";
    else if (c.r==13)
        out<<"[K";

    if (c.s == 0)
        out << "C]";
    if (c.s == 1)
        out << "D]";
    if (c.s == 2)
        out << "S]";
    if (c.s == 3)
        out << "H]";
    return out;
}
