#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "profiler.h"

using std::cout;
using std::endl;
using std::logic_error;

class CQuickSort
{
public:
	static void QuickSort(int *arr, int length, int start, int end);	

private:
	static int RandomInRange(int start, int end);
	static int Partiton(int *arr, int length, int start, int end);
	static void Swap(int *lhs, int *rhs);
};

void CQuickSort::QuickSort(int *arr, int length, int start, int end)
{
	if( start >= end )
		return;

	int index = Partiton(arr, length, start, end);
	if( index>start )
		QuickSort(arr, length, start, index-1);
	if( index<end )
		QuickSort(arr, length, index+1, end);
}

void CQuickSort::Swap(int *lhs, int *rhs)
{
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

int CQuickSort::Partiton(int *arr, int length, int start, int end)
{
	if( arr==NULL || start<0 || start>end || end>=length )
		throw logic_error("Invalid Parameters");

	int index = RandomInRange(start, end);
	Swap(&arr[index], &arr[end]);

	int small = start - 1;
	for( index=start; index<end; ++index)
	{
		if( arr[index]<arr[end] )
		{
			++small;
			if( index != small )
				Swap(&arr[index], &arr[small]);
		}
	}
	++small;
	Swap(&arr[small], &arr[end]);

	return small;
}

int CQuickSort::RandomInRange(int start, int end)
{
	if( start>end )
		Swap(&start, &end);

	srandom(time(NULL));
	if( start==end )
		return random()%start;

	return random()%(end-start) + start;
}

int main(int argc, char **argv)
{
	long N = atol(argv[1]);

	int arr1[N];

	for(long i=0; i<N; ++i)
	{
		srandom(i);
		arr1[i] = random()%N;
	}
	PROFILER;
	CQuickSort::QuickSort(arr1, N, 0, N-1);
/*
	for(int i=0; i<N; ++i)
	{
		cout << arr1[i] << endl;
	}
*/
	return 0;
}