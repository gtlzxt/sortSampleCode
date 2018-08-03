#include "mysort.h"
#include "gtest/gtest.h"
#include "sorttestenv.h"
#include "mytools.h"

TEST_F(sortTestEnv, myBubbleSort)
{
    myBubbleSort(dataSorted,length);
    bool result = IsDataSorted();
    ASSERT_TRUE(result);
    if(!result)
        showData(dataUnsorted,length);
}

TEST_F(sortTestEnv, myInsertSort)
{
    myInsertSort(dataSorted,length);
    bool result = IsDataSorted();
    ASSERT_TRUE(result);
    if(!result)
        showData(dataUnsorted,length);
}

TEST_F(sortTestEnv, myChooseSort)
{
    myChooseSort(dataSorted,length);
    bool result = IsDataSorted();
    ASSERT_TRUE(result);
    if(!result)
        showData(dataUnsorted,length);
}

TEST_F(sortTestEnv, myQuickSort)
{
    myQuickSort(dataSorted,length);
    bool result = IsDataSorted();
    ASSERT_TRUE(result);
    if(!result)
        showData(dataUnsorted,length);
}

TEST_F(sortTestEnv, myMergeSort)
{
    myMergeSort(dataSorted,length);
    bool result = IsDataSorted();
    ASSERT_TRUE(result);
    if(!result)
        showData(dataUnsorted,length);
}

TEST_F(sortTestEnv, myHeapSort)
{
    myHeapSort(dataSorted,length);
    bool result = IsDataSorted();
    ASSERT_TRUE(result);
    if(!result)
        showData(dataUnsorted,length);
}
