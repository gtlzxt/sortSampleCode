#include "sorttestenv.h"
#include "mytools.h"

void sortTestEnv::SetUp()
{
    length = 10;
    dataSorted = new int[length];
    dataUnsorted = new int[length];
    randData(dataSorted,length,100);
    copyData(dataUnsorted,dataSorted,length);
}

void sortTestEnv::TearDown()
{
    delete[] dataSorted;
    delete[] dataUnsorted;
}

bool sortTestEnv::IsDataSorted()
{
    return ::isDataSorted(dataUnsorted,dataSorted,length);
}
