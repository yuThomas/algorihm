//把数组中开始的若干个元素搬到数组末尾，称为数组的旋转
//输入一个递增、可带重复元素的数组的一个旋转，输出旋转数组的最小值

#include <iostream>
#include <stdexcept>

using std::logic_error;
using std::cout;
using std::endl;


class CRotatedArray
{
public:
	static int MinNumber(int *arr, int length);

private:
	static int  MinNumberInOrder(int *arr, int startIndex, int endIndex);
};


int CRotatedArray::MinNumber(int *arr, int length)
{
	if( arr==NULL || length<=0 )
		throw logic_error("Invalid Input");

	int midIndex = 0;
	int endIndex = length - 1;
	int startIndex = 0;

	while( arr[startIndex]>=arr[endIndex] )
	{
		//若两元素索引相邻，则指针endIndex即为数组最小值
		if( endIndex==(startIndex+1) )
		{
			midIndex = endIndex;
			break;
		}

		int midIndex = (endIndex+startIndex)>>1;
		//若三指针值均相等，根据二分法无法判断最小值所在区间，只能顺序遍历
		if( arr[startIndex]==arr[midIndex] && arr[midIndex]==arr[endIndex] )
			return MinNumberInOrder(arr, startIndex, endIndex);

		//二分查找
		if( arr[midIndex]>=arr[startIndex] )
			startIndex=midIndex;
		else
			endIndex=midIndex;
	}

	return arr[midIndex];
}

int CRotatedArray::MinNumberInOrder(int *arr, int startIndex, int endIndex)
{
	int minNumber = arr[startIndex];
	for( int i=startIndex+1; i<=endIndex; ++i )
	{
		minNumber = minNumber>arr[i] ? arr[i] : minNumber;
	}

	return minNumber;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,1,1,1,0,1,1};
	cout << CRotatedArray::MinNumber(arr, sizeof(arr)/sizeof(arr[0]))
		<< endl;

	return 0;
}