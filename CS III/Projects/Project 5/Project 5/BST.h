/****************
William Fu
Comp Sci 241
Project 5
Betsy Sanders
****************/
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

struct Node //struct for node
{
    string word;
    int frequency;
    Node * right;
    Node * left;

    Node(string item, int freq)
    {
        word = item;
        frequency = freq;
        left = right = NULL;
    }
};

class BST
{
public:
    BST();
    ~BST();
    void add(string s);
    void print(ostream & out) const;
    int find(string s);
    void printAlph(int n);


private:
    BSTAux(Node*subroot);
    void addAux(Node *& subroot, string word);
    void printAux(ostream & out, int indent, Node * subtreeRoot) const;
    void alphAux(Node *subroot, int n);
    Node * root; //all bst have roots
};

#endif // BST_H_INCLUDED
