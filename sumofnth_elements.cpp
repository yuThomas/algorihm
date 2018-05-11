#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::sort;

/*
	给定一个数组，取其中N个元素，其和为target，找出所有的唯一组合
*/
class Solution
{
public:
	vector<vector<int> > sumOfNthElements(vector<int> &v, int target, int n)
	{
		vector<vector<int> > res;
		vector<int> candicate;
		sort(v.begin(), v.end());
		dfs(v, 0, candicate, target, res, n);
		return res;
	}

	void dfs(const vector<int> &v, int curIndex, vector<int> &candicate, int target, vector<vector<int> > &res, int count)
	{
		//已经取得四个元素，求和，如果满足条件，则加入结果集然后退出，否者直接退出
		if( candicate.size() == count )
		{
			if( getSum(candicate) == target )
			{
				res.push_back(candicate);
			}
			return;
		}

		//已经遍历完数组元素
		if( curIndex >= v.size() )
		{
			return;
		}

		for( int index=curIndex; index<v.size(); ++index )
		{
			//关键步骤，用于去除回溯工程中可能出现的重复结果集
			if( index>curIndex && v[index]==v[index-1] )
				continue;
			
			candicate.push_back(v[index]);
			if( getSum(candicate)>target && v[index]>0 )
			{
				candicate.pop_back();
				return;
			}
			dfs(v, index+1, candicate, target, res, count);
			if( !candicate.empty() )
			{
				candicate.pop_back();
			}
		}
	}

	int getSum(const vector<int> &v)
	{
		int sum=0;
		for( auto num : v )
		{
			sum += num;
		}
		return sum;
	}
};


int main(int argc, char **argv)
{
	int arr[]={0,0,0,1,-2,-1,3,2};
	vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
	Solution s;
	vector<vector<int> > res =s.sumOfNthElements(v, 1, 4);
	for( auto v : res )
	{
		for( auto num : v )
		{
			cout << num << ' ';
		}
		cout << endl;
	}
}
