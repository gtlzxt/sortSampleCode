#include <iostream>
#include "gtest/gtest.h"
#include "mytools.h"
#include "mysort.h"
using namespace std;

int myGoogleTest(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

void myTest()
{
    int length = 10;
    int limit = 100;
    int* vec = new int[length];
    int* copyVec = new int[length];
    randData(vec, length, limit);
    copyData(copyVec,vec,length);
    showData(vec, length);
    myHeapSort(vec,length);
    showData(vec,length);
    if(isDataSorted(copyVec,vec,length))
    {
        cout << "sorted" << endl;
    }
    else
    {
        cout << "unsorted" << endl;
    }
    delete[] vec;
}
int main(int argc, char* argv[])
{
    for(int i = 0; i< 100; i++)
    myGoogleTest(argc,argv);
    //myTest();
}
