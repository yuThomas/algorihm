#include "alg_common.h"

using namespace std;

class Solution
{
public:
	vector<int> topkFrequent(const vector<int> &v, int k)	
	{
		assert(k<= v.size());

		/*使用无序map对数值出现的频率计数*/
		unordered_map<int ,int> mp;
		for(auto num : v)
		{
			++mp[num];
		}
/*
	//  最小堆思想可以解无重复数组的第topK和前topK问题
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

		for(auto it=mp.begin(); it != mp.end(); ++it)
		{
			{
				pq.push(make_pair(it->second, it->first));
			}
			else
			{
				if( pq.top().first < it->second)
				{
					pq.pop();
					pq.push(make_pair(it->second, it->first));
				}
				else if( pq.top().first == it->second)
			}
		}

		vector<int> res;
		while( !pq.empty() )
		{
			res.push_back(pq.top().second);
			pq.pop();
		}
*/
		/*按照桶排序的思想，将频率相同的数值放到同一组*/
		vector<set<int> > vec(mp.size()+1);
		for( auto it=mp.begin(); it != mp.end(); ++it)
		{
			vec[it->second].insert(it->first);
		}

		vector<int> res;
		for( int i=vec.size()-1; i>0; --i )
		{
			if( !vec[i].empty() && res.size()<k)
				res.insert(res.begin()+res.size(), vec[i].begin(), vec[i].end());
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6};	
	vector<int> v(arr, arr + (sizeof arr / sizeof arr[0]));

	Solution sol;
	vector<int> res = sol.topkFrequent(v, 3);
	for(auto it=res.begin(); it != res.end(); ++it)
	{
		cout << *it << ' ';
	}

	cout << endl;
	return 0;
}