#include <vector>
#include <iostream>
using namespace std;

void swap( int *lhs, int *rhs )
{
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int partition(int *arr, int start, int end)
{
    //int pivot = random()%(end-start) + start;
    int pivot = ((end-start) >> 1) + start;
    int small = start - 1;
    swap(arr+pivot, arr+end);
    for( int i=start; i < end; ++i )
    {
        if( arr[i] < arr[end] )
        {
            ++small;
            if( i != small )
            {
                swap(arr+i, arr+small);
            }
        }
    }
    ++small;
    swap(arr+small, arr+end);
    return small;
}

void qsort(int *arr, int start, int end, int len)
{
    if( start <  0 || start >= end || end >= len )
    {
        return;
    }
    int pivot = partition(arr, start, end);
    if( start < pivot )
    {
        qsort(arr, start, pivot-1, len);
    }
    if( pivot < end )
    {
        qsort(arr, pivot+1, end, len);
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {9, 5, 1, 0, 3, 6, 2, 1, 8, 4};
    qsort(arr, 0, 9, 10);
    for( int i = 0; i < 10; ++i )
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}