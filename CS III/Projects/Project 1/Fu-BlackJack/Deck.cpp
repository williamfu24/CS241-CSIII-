/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#include<iostream>
using namespace std;
#include "Deck.h"

#include <vector>
#include <algorithm> /*used for random shuffle*/


void Deck::initDeck() //initializes deck
{
    for(int i = 1; i <=13; i++)
            {
                for(int j=0; j <= 3; j++)
                {
                 Card c;
                 c.setRank(Rank (i));
                 c.setSuit(Suit (j));
                 vectordeck.push_back(c);
                }
            }
}

void Deck::shuffle() //shuffles deck
{
    random_shuffle(vectordeck.begin(), vectordeck.end());
}

Card Deck::deal() //deals to a hand
{
    Card temp;
    temp=vectordeck.back();
    vectordeck.pop_back();
    return temp;
}

void Deck::verifyDeck() //prints out deck
{
    int x = vectordeck.size();
    int i;
    for (i = 0; i < x; i++)
    {
        cout<< vectordeck[i];
    }
}
