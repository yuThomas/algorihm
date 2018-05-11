#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;


/*将数组进行排序： 数值=下标，排除负数，然后遍历数组，若数值！= 下标，此下标为所求值*/

size_t  fisrtMissingPositiveInteger(vector<int> &v)
{
	size_t  size = v.size();

	for(int i=0; i<size; ++i)
	{
		if((i+1) == v[i]) continue;

		int num = v[i];

		//数值大于0且数值不等于下标则调换数值到对应的下标位置*/
		while(num >=1 && (num != v[num-1]) && num<=size)
		{
			v[i] = v[num-1];
			v[num-1] = num;
			num = v[i];
		}
	}

	for(int i=0; i<size; ++i)
	{
		if((i+1) != v[i])
			return i+1;
	}

	return v.size()+1;
}


int main(int argc, char const *argv[])
{
	int arr[] = {1,3,2,2, -3, -4, 5, 9};
	vector<int> v(arr, arr+8);
	cout << "The first missing positive integer is " << fisrtMissingPositiveInteger(v);
	cout << endl;
	return 0;
}