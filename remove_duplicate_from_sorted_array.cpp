#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

/*算法原理：
	应用双指针，数组已排序
	1. 初始两个指针p1指向v[0], p2指向p[1]
	2. 如果v[p2]==v[p1]，则指针p2向前移动，指针p1静止不动，直到v[p2]>v[p1]，执行v[++p1] = v[p2]
	3. 指针p2遍历指向v.end()，此时p1之前的子数组为不重复数组
*/
int  removeDuplicate(vector<int> &v)
{
	int  x=0;
	size_t size = v.size();
	for(int i=1; i<size; ++i)
	{
		if(v[i] > v[x])
		{
			v[++x] = v[i];
		}
	}
	v.erase(v.begin()+x+1, v.end());
	return x;
}

int main(int argc, char **argv)
{
	int arr[] = {1,1,2,3,4,4,4,5,5,6};
	vector<int> v(arr, arr+10);
	removeDumplicate(v);
	cout << v.size() << endl;
	for(int i = 0 ; i<v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;
}