/*********************
William Fu
Comp Sci 241
Project 1- BlackJack
Due: 1/26
Betsy Sanders
*********************/



#include <iostream>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Player.h"
#include "BlackJackPlayer.h"
#include "Player.h"
#include "Dealer.h"
#include <algorithm>
#include <time.h>

using namespace std;

int main()
{
    srand (time(NULL)); //for true random
    //Start of Main: Introduces rules and players+their bank
    cout <<"Welcome to BlackJack. Here are the rules:"<<endl;
    cout <<"BlackJack is a comparing card game between a player and dealer, meaning players compete with the dealer but not against other players. ";
    cout << "The objective of the game is to beat the dealer in one of the following ways:"<<endl;
    cout <<" - Get 21 points on the player's first two cards (called a 'blackjack') without a dealer blackjack"<<endl;
    cout <<" - Reach a final score higher than the dealer without exceeding 21"<<endl;
    cout <<" - Let the dealer draw additional cards until his or her hand exceeds 21"<<endl;
    Player one, two;
    one.who();
    two.who();
    Dealer z;
    Deck d;
    d.initDeck();
    string play;
    play="y";
    while (play == "y")//Starts game. Continues as long as play is yes
    {
        //Declaring used dataTypes
        int a;
        a=0;
        int total;

        int v1 = rand()%5;
        for (int q=0;q<v1;q++)
            d.shuffle();

        //Betting
        cout<<endl;
        one.myName();
        int onebet = one.Bet();
        cout<<endl;
        two.myName();
        int twobet = two.Bet();
        cout<<endl;

        d.shuffle();
        one.h.clear();
        two.h.clear();
        z.h.clear();

        //Dealing to player classes
        one.h.add(d.deal());
        two.h.add(d.deal());
        z.h.add(d.deal());
        one.h.add(d.deal());
        two.h.add(d.deal());
        z.h.add(d.deal());

        //Initial Starting
        cout<<"Starting cards:\n";
        one.myName();
        cout<<"'s current hand: ";
        one.h.printHand(a);
        cout<<endl;

        two.myName();
        cout<<"'s current hand: ";
        two.h.printHand(a);
        cout<<endl;

        cout<<"Dealer's current hand: ";
        z.h.printHand(a); //z=dealer
        cout<<endl;
        cout<<endl;

        //Now that a !=0 the first card will be shown instead of [??]
        a+=1;

        //Start of player one turn
        one.myName();
        cout<<"'s turn!"<<endl;
        one.myName();
        cout<<"'s current hand: ";
        one.h.printHand(a);
        cout<<endl;
        one.hitMe();
        cout<<endl;
        while (one.Decision == true && one.isBusted()!=true)
        {
            one.myName();
            cout<<"'s current hand: ";
            one.h.printHand(a);
            total=one.h.getTotal();
            cout<< "\n -Hand worth:";
            cout<<total<<"\n"<<endl;

            one.hitMe();
            cout<<endl;
        }

        if(one.isBusted()== true)
        {
            one.myName();
            cout<<"'s current hand: ";
            one.h.printHand(a);
            total=one.h.getTotal();
            cout<< "\n -Hand worth:";
            cout<<total<<"\n"<<endl;

            one.myName();
            cout<<" is out!"<<endl;
            cout<<endl;
        }


        //Start of player two turn
        two.myName();
        cout<<"'s turn!"<<endl;
        one.myName();
        cout<<"'s current hand: ";
        two.h.printHand(a);
        cout<<endl;
        two.hitMe();
        cout<<endl;
        while (two.Decision == true && two.isBusted()!=true)
        {

            two.myName();
            cout<<"'s current hand: ";
            two.h.printHand(a);
            total=two.h.getTotal();
            cout<< "\n -Hand worth:";
            cout<<total<<"\n"<<endl;

            two.hitMe();
            cout<<endl;
        }

        if(two.isBusted()== true)
        {
            two.myName();
            cout<<"'s current hand: ";
            two.h.printHand(a);
            total=two.h.getTotal();
            cout<< "\n -Hand worth:";
            cout<<total<<"\n"<<endl;
            two.myName();
            cout<<" is out!"<<endl;
            cout<<endl;
        }


        //Dealers turn
        while (z.isBusted() != true)
        {
            cout<<"Dealer's current hand: ";
            z.h.printHand(a);
            cout<<endl;
            z.dealerHit();
            if(z.Decision == true)
            {
                z.hit();
            }
            else
                break;
        }
        if (z.isBusted()==true)
        {
            z.h.printHand(a);
            cout<<endl;
            cout<< "Dealer has busted\n"<<endl;
        }




        //Win conditions (I tried to put these in BlackJackPlayer class but couldn't make it work in Main
        if (one.isBusted() == true && two.isBusted() == true) //works
        {
            cout<<"The house wins."<<endl;
            one.winBet(0);
            two.winBet(0);
        }

        if (z.isBusted()==true)
        {
            if (one.isBusted()==false && two.isBusted()==true)
            {
                one.myName();
                cout<<" is the winner. You win "<<onebet<<" dollars!"<<endl;
                one.winBet(onebet*2);
            }
            if (one.isBusted()==true && two.isBusted()==false)
            {
                two.myName();
                cout<<" is the winner. You win "<<twobet<<" dollars!"<<endl;
                two.winBet(twobet*2);
            }
            if (one.isBusted()==false && two.isBusted()==false)
            {
                cout<<"You both beat the house!"<<endl;
                one.myName();
                cout<<", you win "<<onebet<<" dollars!"<<endl;
                two.myName();
                cout<<", you win "<<twobet<<" dollars!"<<endl;
                one.winBet(onebet*2);
                two.winBet(twobet*2);
            }
        }


        if(z.isBusted()==false)
        {
            if(z.getTotal()==21)
                cout<<"The house has won"<<endl;

            else if(one.isBusted()==true)
            {
                one.myName();
                cout<<" busted out"<<endl;
            }
            else if(one.isBusted()==false)
            {
                if(one.getTotal() < z.getTotal())
                {
                    one.myName();
                    cout<<" you lost to the house"<<endl;
                }
                else if(one.getTotal() > z.getTotal())
                {
                    one.myName();
                    cout<<" you beat the house! You win "<<onebet<<" dollars!"<<endl;
                    one.winBet(onebet*2);
                    break;
                }
                else if(one.getTotal()==z.getTotal())
                {
                    cout<<"Sorry, ";
                    one.myName();
                    cout<<" ties go to the house"<<endl;
                }
            }
            else if(two.isBusted()==true)
            {
                two.myName();
                cout<<" busted out"<<endl;
            }
            else if(two.isBusted()==false)
            {
                if(two.getTotal() < z.getTotal())
                {
                    two.myName();
                    cout<<" you lost to the house"<<endl;
                }
                else if(two.getTotal() > z.getTotal())
                {
                    two.myName();
                    cout<<" you beat the house! You win "<<twobet<<" dollars!"<<endl;
                    two.winBet(twobet*2);
                    break;
                }
                else if(two.getTotal()==z.getTotal())
                {
                    cout<<"Sorry, ";
                    two.myName();
                    cout<<" ties go to the house"<<endl;
                }
            }
        }

        //Shows winnings
        cout<< "\nHere are the standings:"<<endl;
        one.myName();
        cout<<": ";
        one.showBank();
        cout<<endl;

        two.myName();
        cout<<": ";
        two.showBank();
        cout<<endl;

        //Asks to play again
        cout<< "\nDo you want to play again? y/n"<<endl;
        cin>> play;
    }




}
