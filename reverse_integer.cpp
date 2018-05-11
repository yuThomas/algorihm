#include <iostream>
#include <cassert>
#include <limits.h>

using std::cout;
using std::endl;

/*****************************************************************
提示：负整型数据求模或求商所得值均为负整型或0
重点：数据翻转后溢出的判断方法
******************************************************************/
int reverseInteger(int x)
{
	int result=0;
	while(x!=0)
	{
		int tail = x % 10;
		int newresult = result*10 + tail;

		//此处判断反转后数字是否益处
		if((newresult - tail) / 10 != result)
			return 0;
		result = newresult;
		x /= 10;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	cout <<	 reverseInteger(-12345);
	cout << endl;	
	return 0;
}