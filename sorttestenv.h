#ifndef TESTENV_H
#define TESTENV_H
#include "gtest/gtest.h"

class sortTestEnv : public testing::Test
{
public:
protected:
    virtual void SetUp();
    virtual void TearDown();
    virtual bool IsDataSorted();
    int* dataUnsorted;
    int* dataSorted;
    int length;
};

#endif // TESTENV_H
