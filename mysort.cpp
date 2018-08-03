#include "mysort.h"
#include "mytools.h"

void myBubbleSort(int* vec, int length)
{
    for(int i = length-1; i > 0; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            if(vec[j-1] > vec[j])
            {
                int tmp = vec[j-1];
                vec[j-1] = vec[j];
                vec[j] = tmp;
            }
        }
    }
}
void myInsertSort(int* vec, int length)
{
    for(int i = 1; i< length; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(vec[j] < vec[j-1])
            {
                int tmp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = tmp;
            }
            else
            {
                break;
            }
        }
    }
}
void myChooseSort(int* vec, int length)
{
    for(int i = 0; i < length; i++)
    {
        int index = i;
        for(int j = i; j < length; j++)
        {
            if(vec[index] > vec[j])
                index = j;
        }
        if(i != index)
        {
            int tmp = vec[i];
            vec[i] = vec[index];
            vec[index] = tmp;
        }
    }
}

int partition(int* vec, int begin, int end)
{
    int pivot = vec[begin];
    while(begin < end)
    {
        while(vec[end] > pivot && begin < end) end--;
        if(begin < end) vec[begin++] = vec[end];
        while(vec[begin] < pivot && begin < end) begin++;
        if(begin < end) vec[end--] = vec[begin];
    }
    vec[begin] = pivot;
    return begin;
}
void myRecuriveQuickSort(int* vec, int begin, int end)
{
    if(begin >= end)
        return;
    int middle = partition(vec,begin, end);
    myRecuriveQuickSort(vec, begin, middle-1);
    myRecuriveQuickSort(vec,middle+1, end);
}
void myQuickSort(int* vec, int length)
{
    myRecuriveQuickSort(vec, 0, length-1);
}

void myHeapify(int* vec, int index, int length)
{
    if(2*index +1 >= length)
        return;
    int largestIndex = index;
    if(vec[index] < vec[2*index+ 1]) largestIndex = 2*index + 1;
    if(2*index +2 < length && vec[largestIndex] < vec[2*index + 2]) largestIndex = 2*index + 2;
    if(largestIndex != index)
    {
        int tmp = vec[index];
        vec[index] = vec[largestIndex];
        vec[largestIndex] = tmp;
        myHeapify(vec,largestIndex,length);
    }
}
void buildHeap(int* vec,int length)
{
    for(int i = length/2 -1; i >=0; i--)
        myHeapify(vec,i,length);
}
void myHeapSort(int* vec, int length)
{
    buildHeap(vec,length);
    for(int i = length-1; i>=0 ;i--)
    {
        int tmp = vec[i];
        vec[i] = vec[0];
        vec[0] = tmp;
        myHeapify(vec,0,i);
    }
}
static void merge(int* vec, int begin, int middle, int end)
{
    if(begin > middle || middle > end)
        return;
    int firstLength = middle-begin;
    int secondLength = end-middle;
    int* first = new int[firstLength];
    int* second = new int[secondLength];
    int i = 0, j = 0;
    copyData(first,vec+begin,firstLength);
    copyData(second,vec+middle,secondLength);

    while(i < firstLength && j < secondLength)
    {
        if(first[i] <= second[j])
            vec[begin + i + j] = first[i++];
        else
            vec[begin + i + j] = second[j++];
    }
    if(i == firstLength)
        copyData(vec+begin+i+j,second+j,secondLength-j);
    else
        copyData(vec+begin+i+j, first +i, firstLength-i);

}
static void myRecuriveMergeSort(int* vec, int begin, int end)
{
    if(end - begin <= 1)
        return;
    int middle = (begin + end)/2;
    myRecuriveMergeSort(vec,begin, middle);
    myRecuriveMergeSort(vec,middle,end);
    merge(vec,begin, middle,end);
}
void myMergeSort(int* vec, int length)
{
    myRecuriveMergeSort(vec,0,length);
}
