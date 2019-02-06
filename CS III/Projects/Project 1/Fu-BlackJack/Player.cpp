/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/

#include "player.h"
#include<stdlib.h>
#include<string>
using namespace std;


Player::Player()
{
    string Name= "Dealer";
    bool Busted= false;
    int Bank=1000000000;
}

bool Player::isBusted() //Checks to see if player has busted
{
    Busted == false;
    if (h.getTotal() >= 22)
    {
        Busted == true;
        return true;
    }
    else
    {
        Busted == false;
        return false;
    }
}

void Player::hitMe() //asks if players want to be hit
{
    string d;
    myName();
    cout << " do you want another card? y/n \n";
    cin >> d;
    if (d=="y")
    {
        hit();
        Decision= true;
    }
    else if (d=="n")
    {
        Decision= false;
    }
    else
    {
        cout << "That was an invalid response. So hit.\n";
        hitMe();
    }
}

void Player::hit() //hits player
{
    int v = rand() %10;
    Deck d;
    d.initDeck();
    for(int i =0; i < v;i++)
        {
            d.shuffle();
        }
    h.add(d.deal());
}

void Player::who() //asks who the player is and how much their starting bank is
{
    cout << "\nPlease enter your name:\n";
    cin >> Player::Name;
    cout << "How much money to start?\n";
    cin >> Player::Bank;
    Decision=true;
}

void Player::myName() //displays player name
{
    cout<< Name;
}

int Player::Bet() //asks how much player wants to bet and takes out of bank
{
    int bet;
    cout << " how much would you like to bet?\n";
    cin >> bet;
    Bank = Bank - bet;
    return bet;
}

void Player:: winBet(int x) //Banks the winnings x
{
    Bank = Bank + x;
}

void Player::showBank() //displays bank
{
    cout << Bank;
}
