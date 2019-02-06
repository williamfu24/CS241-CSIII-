#include <iostream>
#include "slist.h";
#include "node.h";

using namespace std;

int main()
{
    slist originalOrder;
    slist procesionalOrder;
    slist directoryOrder;
    cout << "Rhodes Professor Procession Line Up"<<endl;
    facType fac;
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
        originalOrder.slistAppend(fac);
    }
    cout<< "Your original list:"<<endl;
    originalOrder.printMe();
}
