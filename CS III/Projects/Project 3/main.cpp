/****************
William Fu
Comp Sci 241
Project 3
Betsy Sanders
****************/

#include <iostream>
#include "SortAlgs.h"

//random size of vector with random numbers within


using namespace std;

int main()
{
    int start_sq=clock(); //starts timer
    vector<int> nsq; //creates vectors for nsquare sort and nlogn sort
    vector<int> nlogn;
    srand((unsigned)time(NULL)); //allows for random size vector
    int x = rand() % 15 + 1;
    for(int i=0; i<x; i++)
    {
        int y = rand() % 100 + 1; //allows for random values
        nsq.push_back(y);
    }
    cout<< "Unsorted n squared sorting vector: ";
    for (int i=0; i<nsq.size();i++)
    {
        cout<<nsq[i]<< " ";
    }
    cout<<endl;
    nSqSort(nsq,nsq.size());
    cout<< "Sorted n squared vector: ";
    for (int i=0; i<nsq.size();i++)
    {
        cout<<nsq[i]<< " ";
    }
    cout<<endl;
    int stop_sq=clock();
    cout<<"Time for N^2 sorting algorithm: "<< (stop_sq-start_sq)/double(CLOCKS_PER_SEC)*1000 <<endl;

    //Now for nlogn sorting
    int start_log=clock();
    int m= rand() % 15 + 1;
    for(int i=0; i<m; i++)
    {
        int n = rand() % 100 + 1;
        nlogn.push_back(n);
    }
    cout<<"Unsorted nlogn sorting vector: ";
    for (int i=0; i<nsq.size();i++)
    {
        cout<<nlogn[i]<< " ";
    }
    cout<<endl;
    nLgNSort(nlogn, nlogn.size());
    cout<<"Sorted nlogn vector: ";
    for (int i=0; i<nsq.size();i++)
    {
        cout<<nlogn[i]<< " ";
    }
    cout<<endl;
    int stop_log=clock();
    cout<<"Time for NLogN sorting algorithm: "<< (stop_log-start_log)/double(CLOCKS_PER_SEC)*1000<<endl;
}

template <class T>
void nSqSort(vector<T> &a, unsigned count) //insert sort
{
    int j;
    for(int i=0; i<count; i++)
    {
        j = i;
        while(j > 0 && a[j] < a[j-1])
        {
            int k = a[j];
            a[j] = a[j-1];
            a[j-1] = k;
            j--;

        }
    }
}


template <class T>
void nLgNSort(vector<T> &a, unsigned count)
{
    mergeSort(a, 0, a.size() -1);
}


template <class T>
void mergeSort(vector<T> &a, int z[], int n)
{
    int *L1 = new int[n/2];
    int *L2 = new int [n-(n/2)];
    if (n>1)
    {
        int i;
        for (int i = 0; i<(n/2);i++)
            L1[i]=z[i];
        for (int j=0; i<n; i++, j++)
            L2[j]=z[i];
    }
    mergeSort(a, L1, (n/2));
    mergeSort(a, L2, n-(n/2));
    merge (a, L1, (n/2), L2, n-(n/2), z, n);
    delete []L1;
    delete []L2;
}


template <class T>
void merge(vector<T> &a, int*L1, int n1, int *L2, int n2, int *z, int n)
{
    int i=0;
    int j=0;
    int k=0;
    while (i<n1 && j<n2)
    {
        if (L1[i] <= L2[j])
        {
            a[k]=L1[i];
            i++;
        }
        else
        {
            a[k]=L2[j];
            j++;
        }
        k++;
    }
    if (i==n1)
    {
        while (j<n2)
        {
            a[k]=L2[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i<n1)
        {
            a[k]=L1[i];
            i++;
            k++;
        }
    }
}
