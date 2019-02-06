/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#include<iostream>
using namespace std;
#include "Dealer.h"


void Dealer::dealerHit() //determines if dealer wants to hit or not
{
    if(h.getTotal() >= 16) //for some reason when i had it as <=17 it would hit at 17 and above and stay at 16 and below
        {
         Decision = false;
         cout<<"The Dealer stays at "<<h.getTotal()<<" points"<<endl;
        }
    else
        {
         Decision = true;
         cout<<"The dealer will hit.";
         cout<<endl;
         }
};
