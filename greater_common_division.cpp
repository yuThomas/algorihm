/******************最大公约数**********************
*1.辗转相除法(欧几米德算法)
 原理:
	两个正整数a,b(a>b)，它们的最大公约数等于a%b的余c与b的最大公约数
 缺点:
	取模运算效率低
 */
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

size_t gcd(size_t num1, size_t num2)
{
	if(num1%num2 == 0)
	{
		return num2;
	}
	return gcd(num2, num1%num2);
}
size_t getGreaterCommonDivison(size_t num1, size_t num2)
{
	size_t result=0;
	if(num1 > num2)
	{
		result = gcd(num1, num2);
	}
	else
	{
		result = gcd(num2, num1);
	}
	
	return result;
}

/*更相减算术
原理:
	两个正整数a,b(a>b)，它们的最大公约数等于a-b的差值c与b的最大公约数
缺点:
	a,b相差太大时，递归次数太多
*/

size_t getGreaterCommonDivison(size_t num1, size_t num2)
{
	if(num1 == num2)
	{
		return num1;
	}
	else if(num1 > num2)
	{
		return getGreaterCommonDivison(num1-num2, num2);
	}
	else
	{
		return getGreaterCommonDivison(num2-num1, num1);
	}
}

/************最优算法******************************/
size_t getGreaterCommonDivison(size_t num1, size_t num2)
{
	if(num1 == num2)
		return num1;
	if(num1 < num2)
		return getGreaterCommonDivison(num2, num1);//保证参数1始终大于参数2,减少代码量
	else if(!num1&1 && !num2&1)//num1,num2均为偶数
		return getGreaterCommonDivison(num1>>1, num2>>1) << 1;
	else if(!num1&1 && num2&1) //num1为偶数,num2为奇数
		return getGreaterCommonDivison(num1>>1, num2);
	else if(num1&1 && !num2&1)//num1为奇数,num2为偶数
		return getGreaterCommonDivison(num1, num2>>1);
	else
		return getGreaterCommonDivison(num2, num2-num1);//两个奇数相减必为偶数
}