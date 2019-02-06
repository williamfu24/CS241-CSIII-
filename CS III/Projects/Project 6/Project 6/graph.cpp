/****************
William Fu
Comp Sci 241
Project 6
Betsy Sanders
****************/

#include "graph.h"
#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
#include<stdlib.h>
using namespace std;
using std::ifstream;

#define _CRT_SECURE_NO_WARNINGS

Graph::Graph(string f) //create the graph
{
    fstream file;
    file.open(f);
    if(!file.good())
    {
        cout<<"Cannot open file. \n";
    }
    file>>numV; //number of vertexs is read into the file
    for (int i=1;i<=numV;i++)
    {
        for(int j=1;j<=numV;j++)
        {
            adjM[i][j]=INF; //fills them to INF
        }
    }
    int i, j, cost;
    while (!file.eof()) //until end of file, rest of numbers are vertex and costs
    {
        file>>i>>j>>cost;
        adjM[i][j] = cost;
    }

    /*for (int i=1;i<=numV;i++)
    {
        for(int j=1;j<=numV;j++)
        {
            if (adjM[i][j]!=INF)
            {
                cout<< "Vertices: "<<i<<" , "<<j<<" | Cost: "<<adjM[i][j]<<endl;
            }
        }
    }*/ //Print out verticies and cost
    file.close();
}

void Graph::dijkstra(int start, string o)
{
    int dist[MAX_V]; //set array of distance visited and prev
    bool visited[MAX_V];
    int prev [MAX_V];
    for (int i = 1; i<=numV; i++) //set all to INF and not visited
    {

        dist[i] = INF;
        visited[i]=false;
        prev[i]=INF;
    }
    dist[start] = 0; //starting point distance is zero

    while (!empty(dist, visited)) //while not empty part of queue
    {
        //cout<<"please be working";
        int v;
        v=getLowestNotVisited(dist, visited);
        visited[v]=true;
        for(int w=1;w<=numV;w++)
        {
            if (adjM[v][w]!=INF)
            {

                if(!visited[w])
                {
                    int alt=dist[v]+adjM[v][w];
                    alt=alt-1000000; //need this cause line about makes it 1000000 + dist
                    if(alt<dist[w])
                    {
                        dist[w]=alt;
                        prev[w]=v;
                        visited[w]=true;
                    }
                }
            }
        }

    }
    print(start, dist, visited, prev, o);//crashing

}


void Graph::print(int start, int dist[], bool visited[], int prev[], string out) //print function
{
    ofstream myfile;
    myfile.open(out.c_str());
    for (int i=1; i<=numV; i++)
    {
        myfile<< i <<": ";
        myfile<< dist[i]<< " [";
        printAux(start, i, prev, myfile);
        myfile <<"]";
        myfile<<endl;
    }
    myfile.close();
}

ofstream& Graph::printAux(int start, int i, int prev[], ofstream &myfile) //aux print
{
    if (start==i)
    {
        myfile<<start;
        return myfile; //end recursion

    }
    if(prev[i]==INF)
    {
        myfile<< "No Path";
        return myfile;
    }
    printAux(start, prev[i], prev, myfile);
    myfile<<i;
    return myfile;
}


int Graph::getLowestNotVisited(int dist[], bool visited[]) //find the lowest and not visited vertex part of queue
{
    int minimum=MAX_V;
    int minpos;//?
    for (int k=1; k <numV; k++)
    {
        if (visited[k]==false && dist[k]==INF)
        {
            minimum=dist[k];
            minpos=k;
        }
    }
    return minpos;
}

bool Graph::empty(int dist[], bool visited[]) //check for empty graph or not
{
    for (int i = 1; i<=numV; i++)
    {
        if((dist[i]<INF)&& !(visited[i]))
        {
            return false;//its not empty
        }
    }
    return true;//it is empty
}
