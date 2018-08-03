#ifndef MYTOOLS_H
#define MYTOOLS_H

void showData(int* vec, int length);
void randData(int* vec, int length, int limit = 0);
bool isDataSorted(int* unSorted, int* sorted, int length);
void copyData(int* dest, int* src, int length);

#endif // MYTOOLS_H
