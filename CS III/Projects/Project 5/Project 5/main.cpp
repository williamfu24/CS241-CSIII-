/****************
William Fu
Comp Sci 241
Project 5
Betsy Sanders
****************/
#include <iostream>
#include <string>
#include <fstream>
#include<cstring>
using namespace std;
using std::ifstream;

#define _CRT_SECURE_NO_WARNINGS
#include "BST.h"


const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";

int main()
{
    BST ignoreTree; //Make ignore tree
    ifstream ignoreIn;
    ignoreIn.open("ignore.txt");//open ignore file
    if (!ignoreIn.good())
    {
        return 1; //exit if not found
    }
    while (!ignoreIn.eof())
    {
        //read each line of the file in
        char buf[MAX_CHARS_PER_LINE];
        ignoreIn.getline(buf, MAX_CHARS_PER_LINE);

        // parse the line into blank-delimited tokens
        int n = 0; // a for-loop index

        // array to store memory addresses of the tokens in buf
        const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

        // parse the line
        token[0] = strtok(buf, DELIMITER); // first token
        if (token[0]) // zero if line is blank
        {
            for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
            {
                token[n] = strtok(0, DELIMITER); // subsequent tokens
                if (!token[n])
                {
                    break;//no more tokens
                }
            }
        }

        // process (print) the tokens
        for (int i = 0; i < n; i++) // n = #of tokens
        {
            ignoreTree.add(token[i]); // add token to ignore tree
        }
    }
    ignoreTree.print(cout);


    // create a file-reading object
    BST tree; //make BST tree
    ifstream infile;
    string filename; //filename input for file of choosing
    cout<< "Please enter file name: " << endl;
    cin>>filename;
    infile.open(filename); // open a file
    if (!infile.good())
    {
        cout<< "File not found";
        return 1; // exit if file not found
    }

    // read each line of the file
    while (!infile.eof())
    {
        // read an entire line into memory
        char buf[MAX_CHARS_PER_LINE];
        infile.getline(buf, MAX_CHARS_PER_LINE);

        // parse the line into blank-delimited tokens
        int n = 0; // a for-loop index

        // array to store memory addresses of the tokens in buf
        const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

        // parse the line
        token[0] = strtok(buf, DELIMITER); // first token
        if (token[0]) // zero if line is blank
        {
            for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
            {
                token[n] = strtok(0, DELIMITER); // subsequent tokens
                if (!token[n])
                {
                    break;//no more tokens
                }
            }
        }

        // process (print) the tokens
        for (int i = 0; i < n; i++) // n = #of tokens
        {
            if(ignoreTree.find(token[i])==0) //if not found in ignore tree
            {
                tree.add(token[i]); //add to BST tree
            }
        }
    }
    cout<<endl;
    tree.print(cout); //prints tree
    int num; //number for minimum frequency
    cout<< "Please enter a minimum frequency number: ";
    cin>> num; //input
    tree.printAlph(num); //prints all words with frequency requirements
    ignoreTree.~BST(); //deconstructor
    tree.~BST(); //deconstructor
    return 0;
}
