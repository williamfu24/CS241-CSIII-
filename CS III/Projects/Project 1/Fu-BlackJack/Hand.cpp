/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#include<iostream>
using namespace std;

#include "Hand.h"
#include<vector>

Hand::Hand(){ /*constructor of the hand class vector*/
    vectorhand.resize(0); /*dont want to do too much with constructor*/
}

void Hand::clear() /*mutator; empties the hand vector*/
{
    while (vectorhand.empty() != 1) /*while there is something in the hand vector, delete the last value*/
    {
        vectorhand.pop_back();
    }
}

void Hand::add(Card c) /*mutator; adds card to the hand vector*/
{
    vectorhand.push_back(c);
}

int Hand::getTotal() const /*accessor; finds the cards rank, sums them and returns the total*/
{
    int total=0;
    for (int i=0; i<vectorhand.size(); i++)
    {
        total = total + vectorhand[i].getValue();
    }
    return total;
}

void Hand::printHand(int a) const /*prints out the card from a hand*/
{
    int x = vectorhand.size();
    int i;
    for (i = 0; i < x; i++)
    {
        if (a==0)
            cout<<"[??]";
        else
            cout<< vectorhand[i];
        a++;
    }
}

