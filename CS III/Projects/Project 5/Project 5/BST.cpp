/****************
William Fu
Comp Sci 241
Project 5
Betsy Sanders
****************/
#include "BST.h"
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

BST::BST() //constructor
{
    root = NULL;
}

BST:: ~BST() //deconstructor
{
    Node*temp=root;
    BSTAux(temp);
}

BST:: BSTAux(Node * subroot) //recursively delete all nodes
{
    if (subroot->left == NULL && subroot->right ==NULL) //check if last node
    {
        delete subroot;
    }
    else
    {
        if (subroot->left !=NULL) //check for children
        {
            BSTAux(subroot->left); //travel to child
        }
        if (subroot ->right !=NULL)
        {
            BSTAux(subroot->right);
        }
        if (subroot->left == NULL && subroot->right ==NULL) //if last then delete
        {
            delete subroot;
        }
    }
}

void BST::add(string s) //add
{
    addAux(root, s);
}

void BST::addAux(Node *& subroot, string s) //recursive add
{
    if (subroot == NULL) //if null then new node is made
    {
        subroot = new Node(s, 1);
    }
    else if (s == subroot->word) //if word is found increase frequency
    {
        subroot->frequency++;
    }
    else if (s < subroot->word) //if word is less than node go to left child
    {
        addAux(subroot->left, s);
    }
    else if (s > subroot->word) //if word is greater than go to right child
    {
        addAux(subroot->right, s);
    }
}

void BST::print(ostream & out) const //print
{
    printAux(out, 0, root);
}


void BST::printAux(ostream & out, int indent, Node * subtreeRoot) const //in order print Left Visit Right
{
    if (subtreeRoot != 0)
    {
        printAux(out, indent + 2, subtreeRoot->right);
        out << setw(indent) << " " << subtreeRoot->word << endl;
        printAux(out, indent + 2, subtreeRoot->left);
    }
}

int BST::find(string s) //run through bst to find the word
{
    Node*temp=root;
    while (temp != NULL)
    {
        if (temp->word == s)
            break;
        if (s > temp->word)
            temp = temp->right;
        else
        if (s < temp->word)
            temp = temp->left;
    }

    if (temp == NULL) //if not then return 0
    {
        return 0;
    }

    if (temp->word == s) //if its there increase frequency
    {
        return temp->frequency;
    }

    return 0;
}

void BST::printAlph(int num) //print in order
{
    //inorder traversal = LeftPrintRight
    alphAux(root, num);
}

void BST::alphAux(Node * subroot, int n) //Left print right
{
    if (subroot !=NULL)
    {
        alphAux(subroot->left, n);
        if (subroot->frequency >= n)
        {
            cout<< subroot->word<< " - " << subroot->frequency<<endl;
        }
        alphAux(subroot->right, n);
    }
}

