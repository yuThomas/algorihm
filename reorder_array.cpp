//给定一个非空数组，按条件将数组重排序
//重点在于定义一个条件函数bool (*void)(int),用于函数的扩展

#include <stdexcept>

using std::logic_error;

void ReorderArray(int *arr, int length, bool (*func)(int))
{
	if( arr==NULL || length<=0 )
		throw logic_error("Invalid Input");

	int forwardIndex = 0;
	int postwardIndex = arr + length - 1;

	while( forwardIndex<postwardIndex )
	{
		while( forwardIndex<postwardIndex && !func(arr[forwardIndex]) )
			++forwardIndex;

		while( forwardIndex<postwardIndex && func(postwardIndex) )
			++postwardIndex;

		if( forwardIndex<postwardIndex )
		{
			int temp = *arr[forwardIndex];
			arr[forwardIndex] = arr[postwardIndex];
			arr[postwardIndex] = temp;
		}
	}
}