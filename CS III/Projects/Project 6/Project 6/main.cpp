/****************
William Fu
Comp Sci 241
Project 6
Betsy Sanders
****************/

#include <iostream>
#include "graph.h"
#include <stdio.h>
#include<fstream>

#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
    string graphfile; //to file name to open
    cout<< "Enter name of graph file: ";
    cin>> graphfile;
    Graph mygraph(graphfile); //creates the graph reading in the text file
    cout<< "Enter a valid vertex id for the starting vertex: ";
    int startV; //starting vertex
    cin>>startV;
    while (startV< 0 || startV>mygraph.numV)
    {
        cout<< "The vertex must be part of the graph. Try again: ";
        cin>>startV;
    }

    cout<<"Enter name of output file: "; //for an output file
    string out;
    cin>>out;

    clock_t start;//start clock to measure the time to run function
    double duration;
    start = clock();

    mygraph.dijkstra(startV, out); //dijkstra's function

    duration = (clock()-start)/(double) CLOCKS_PER_SEC; //end clock
    cout<<"Total time (in seconds) to apply Dijkstra's algorithm: "<<duration<<endl;

}
