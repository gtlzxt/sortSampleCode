#include "mytools.h"
#include <iostream>
#include <random>
using namespace  std;

void showData(int* vec, int length)
{
    if(vec == nullptr)
        return;
    for(int i = 0 ; i < length; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void randData(int* vec, int length, int limit)
{
    if(vec == nullptr)
        return;
    if(limit == 0)
        limit = 10000;
    random_device rd;
    for(int i = 0; i < length; i++)
    {
        vec[i] = rd()%limit;
    }
}

bool isDataSorted(int* unSorted, int* sorted, int length)
{
    if(unSorted == nullptr || sorted == nullptr)
        return false;
    int unSortedSum = 0;
    int sortedSum = 0;
    for(int i = 0; i< length; i++)
    {
        unSortedSum += unSorted[i];
        sortedSum += sorted[i];
    }
    if(unSortedSum != sortedSum)
    {
        cout << "numers changed!!!" << endl;
        return false;
    }
    for(int i = 1; i< length; i++)
    {
        if(sorted[i-1] > sorted[i])
        {
            cout << "not sorted!!!" << endl;
            return false;
        }
    }
    return true;
}

void copyData(int* dest, int* src, int length)
{
    if(dest == nullptr || src == nullptr)
        return;
    while(length--)
    {
        dest[length] = src[length];
    }
}
