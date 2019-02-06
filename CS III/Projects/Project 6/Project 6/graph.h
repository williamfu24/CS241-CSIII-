/****************
William Fu
Comp Sci 241
Project 6
Betsy Sanders
****************/

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAX_V=99; //max size for array
const int INF=1000000; //extremely large number
class Graph
{
public:
    Graph(string filename);
    void dijkstra(int start, string file);
    void print (int start, int dist[], bool visited[], int prev[], string out);
    ofstream& printAux(int start, int i, int prev[], ofstream &file);
    bool empty(int dist[], bool visited[]);
    int getLowestNotVisited(int dist[], bool visited[]);


    int numV;

private:
    int adjM[MAX_V][MAX_V];

};


#endif // GRAPH_H_INCLUDED
