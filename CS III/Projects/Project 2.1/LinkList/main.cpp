/***************
William Fu
CS 241
Project 2: Linked List
Professor Sanders
***************/

#include <iostream>
#include "slist.h";
#include "node.h";

using namespace std;

int main()
{
    //Creates 3 linked list for desired orders
    slist originalOrder;
    slist processionalOrder;
    slist directoryOrder;
    cout << "Rhodes Professor Procession Line Up"<<endl;
    //DataType facType
    facType fac;
    //Loop runs until professor name is X. Inputs name and years of service
    while (fac.name!="X")
    {
        cout<<"\nProfessor Name: ";
        cin>>fac.name;
        if (fac.name=="X")
        {
            cout<<endl;
            break;
        }
        cout<<"Years of service: ";
        cin>>fac.years;
        //The input functions that add each dataType in order desired
        originalOrder.slistAppend(fac);
        processionalOrder.processionAdd(fac);
        directoryOrder.directoryAdd(fac);
    }
    //couts the linklist with each order
    cout<< "Your original list:"<<endl;
    originalOrder.printMe();
    cout<< "\nYour processional list:"<<endl;
    processionalOrder.printMe();
    cout<< "\nYour directory list:"<<endl;
    directoryOrder.printMe();

    //deconstructs linklist at the end
    originalOrder.~slist();
    processionalOrder.~slist();
    directoryOrder.~slist();

}
