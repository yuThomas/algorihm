#include "alg_common.h"

using namespace std;
class Solution
{
public:
	void moveZeroes(vector<int> &nums)
	{
		if(nums.empty())
			return;

		int len = nums.size();
		int zindex=-1, nzindex=0;
		while(1)
		{

			while( nums[++zindex]!=0 && zindex<len) {}

			nzindex = zindex<nzindex ? nzindex : zindex;
			while( nums[++nzindex]==0 && nzindex<len ) {}

			if( nzindex >= len )
				break;

			//连续非零长度
			int k=nzindex;
			while(nums[++k] != 0 && k<len) {}

			for( ; nzindex<k ; )
			{
				nums[zindex++] = nums[nzindex];
				nums[nzindex++] = 0;
			}
			--zindex;
		}

	}
};

int main(int argc, char **argv)
{
	int arr[] = {0,1,0,1,0,1,0,1,0,1};
	vector<int> vec(arr, arr+(sizeof arr / sizeof arr[0]));

	Solution sol;
	sol.moveZeroes(vec);
	for(int i=0; i<vec.size(); ++i)
	{
		cout << vec.at(i) << ' ';
	}
	cout << endl;
}