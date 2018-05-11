/*
	给定一个数组，每个元素被除自身的其余所有元素乘积代替
	空间复杂度： 0(1)
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void ReplaceWithProductExceptSelf(vector<int> &v)
{
	if( v.size()==0 )
		return;
	int len = v.size();
	vector<int> res(len,1);
/*
	//第一次遍历，每个元素被其左边元素乘积代替
	for( int i=0, temp=1; i<len; ++i )				
	{
		res[i] *= temp;
		temp *= v[i];
	}

	//第二次遍历，每个元素被其本身*(其右边元素乘积)代替
	for( int i=len-1, temp=1; i>=0; --i )
	{
		res[i] *= temp;
		temp *= v[i];
	}
*/
	int lproduct=1;
	for( size_t i=0; i<len; ++i )
	{
		res[i] *= lproduct;
		lproduct *= v[i];
	}

	int rproduct=1;
	for( size_t j=len-1; j>=0; --j )
	{
		res[j] *= rproduct;
		rproduct *= v[j];
	}

	for( size_t i=0; i<len; ++i )
		cout << res[i] << ' ';
}

int main(int argc, char **argv)
{
	int arr[] = {1,2,3,4,5,6};
	vector<int> v(arr, arr+6);
	ReplaceWithProductExceptSelf(v);

	cout << endl;
	return 0;	
}
