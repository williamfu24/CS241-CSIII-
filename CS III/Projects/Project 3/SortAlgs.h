/****************
William Fu
Comp Sci 241
Project 3
Betsy Sanders
****************/

#ifndef SORTALGS_H_INCLUDED
#define SORTALGS_H_INCLUDED

#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
using namespace std;

template <class T>
void nSqSort(vector <T> &a, unsigned count);// insert sort

template <class T>
void nLgNSort( vector<T> &a, unsigned count);

template <class T>
void merge(vector<T> &a, int*L1, int n1, int *L2, int n2, int *z, int n);

template<class T>
void mergeSort(vector<T> &a, int z[], int n);

#endif // SORTALGS_H_INCLUDED
