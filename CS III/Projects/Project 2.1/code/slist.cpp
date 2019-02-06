using namespace std;
#include <iostream>
#include "slist.h";


slist::slist(){
    head = NULL;
};

slist::~slist(){
    node*temp;
    while (head!=NULL)
    {
        temp=head;
        head= temp->next;
        delete temp;
    }
    head = NULL;
};

void slist::printMe()const{
    node*temp=head;
    printAux(temp);
};

void slist::printAux(node*curr)const{
if(curr!=NULL)
   {
       cout<<curr->data.name<< " "<< curr->data.years<<endl;
       printAux(curr->next);
   }
}

void slist::slistAppend(dataType data){
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
