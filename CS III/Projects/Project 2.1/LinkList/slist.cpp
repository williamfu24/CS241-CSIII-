/***************
William Fu
CS 241
Project 2: Linked List
Professor Sanders
***************/

using namespace std;
#include <iostream>
#include "slist.h";


slist::slist(){ //sets new linked list to NULL
    head = NULL;
};

slist::~slist(){ // deletes elements within link list until head is left at NULL
    node*temp;
    while (head!=NULL)
    {
        temp=head;
        head= temp->next;
        delete temp;
    }
    head = NULL;
};

void slist::printMe()const{ // prints out the linked list through recursion
    node*temp=head;
    printAux(temp);
};

void slist::printAux(node*curr)const{ //the recursive Aux function
if(curr!=NULL)
   {
       cout<<curr->data.name<< " "<< curr->data.years<<endl;
       printAux(curr->next);
   }
}

void slist::slistAppend(dataType data){ //adds elements in the order of the user
    node*inserttemp= new node(data);
    node*temp=head;
    if (head==NULL)
    {
        head=inserttemp;
        inserttemp->next=NULL;
        return;
    }
    else
    {
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=inserttemp;
        inserttemp->next=NULL;
    }

}

void slist::processionAdd(dataType data) //adds elements in the order of seniority for faculty
{
    node*inserttemp = new node(data);
    node*temp=head;
    if (head==NULL) //adds to linked list if linked list is enpty to begin with
    {
        head=inserttemp;
        inserttemp->next=NULL;
        return;
    }
    else if (head->getData().years < inserttemp->getData().years) //if inserttemp needs to be the new head this is where it would happen
    {
        inserttemp->setNext(head);
        head=inserttemp;
    }
    else
    {
        while (temp->getNext() != NULL){
            if (temp->getNext()->getData().years < inserttemp->getData().years) //goes through the linked list comparing the years to find insettemps proper position
                {
                inserttemp->setNext( temp->getNext());
                temp->setNext(inserttemp);
                return;
                }
        temp=temp->getNext();

        }

        //adds element at the very end of the list
        temp->setNext(inserttemp);


    }



}

void slist::directoryAdd(dataType data) //adds in order of alphabetical order. Similar logic to processionAdd()
{
    node*inserttemp = new node(data);
    node*temp=head;
    if (head==NULL)
    {
        head=inserttemp;
        inserttemp->next=NULL;
        return;
    }
    else if (head->getData().name.compare(inserttemp->getData().name) > 0 )
    {
        inserttemp->setNext(head);
        head=inserttemp;
    }
    else
    {
        while (temp->getNext() != NULL){
            if ( temp->getNext()->getData().name.compare(inserttemp->getData().name)> 0)
                {
                inserttemp->setNext( temp->getNext());
                temp->setNext(inserttemp);
                return;
                }
        temp=temp->getNext();

        }//end while

        //add the element to the end of the list
        temp->setNext(inserttemp);


    }



}
