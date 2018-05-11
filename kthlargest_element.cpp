#include <iostream>
#include <vector>
#include <stdlib.h>

using std::vector;
using std::cout;
using std::endl;

class Solution
{
public:
	void swap(vector<int> &v, int lhs, int rhs)
	{
		if( v[lhs] != v[rhs] )
		{
			v[lhs] = v[lhs] + v[rhs];
			v[rhs] = v[lhs] - v[rhs];
			v[lhs] = v[lhs] - v[rhs];
		}
	}

	void show(vector<int> &v)
	{
		for( size_t i=0; i<v.size(); ++i )
			cout << v[i] << ' ';
		cout << endl;
	}

	int kthLargestElement(vector<int> &v, int k)
	{
		if ( k<1 || k>v.size() || v.empty() )
			return -1;

		int startIndex=0, endIndex=v.size()-1;
		srandom(time(NULL));
		
		while(startIndex<endIndex)
		{
			int pivot = startIndex + random()%(endIndex-startIndex+1);
			swap(v, pivot, endIndex);
			int small = startIndex-1;
			for( pivot=startIndex; pivot<endIndex; ++pivot )
			{
				if( v[pivot] > v[endIndex] )
				{
					++small;
					swap(v, small, pivot);
				}
			}
			++small;
			swap(v, small, endIndex);
/*
			int lIndex=startIndex, rIndex=endIndex;
			while(lIndex<rIndex)
			{
				while(v[lIndex]>=v[endIndex] && lIndex<rIndex) ++lIndex;
				while(v[rIndex]<=v[endIndex] && lIndex<rIndex) --rIndex;
				if( lIndex<rIndex )
					swap(v, lIndex, rIndex);
			}
			swap(v, lIndex, endIndex);
			if( lIndex == k-1 )
			{
				startIndex = lIndex;
				break;
			}
			else if( lIndex < k-1 )
				startIndex = lIndex+1;
			else
				endIndex = lIndex-1;
*/
			if( small == k-1 )
			{
				startIndex = small;
				break;
			}
			else if( small < k-1 )
				startIndex = small+1;
			else
				endIndex = small-1;
		}
		return v[startIndex];
	}
};

int main(int argc, char **argv)
{
	int arr[] = {1,3,6,2,9,5,4};
	vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
	Solution s;
	int res = s.kthLargestElement(v, 3);
	cout << res << endl;
}
