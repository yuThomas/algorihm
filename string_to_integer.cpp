/*
	字符串转换乘对应的整型
	规定如下：
		1.如果是空字符串，返回0,并且置全局变量g_status=kInvalid;
		2.如果字符串带特殊字符(开头出现的”+” “-”除外),返回第一个非数字字符之前的转换
		3.如果转换后字符益出，返回益出数字，并且置全局变量g_status=kInvlid;
*/
#include <iostream>
using std::endl;
using std::cout;

enum Status {kValid, kInvalid};
bool g_status=kValid;

long stringToIntegerCore(const char* , bool);
int stringToInteger(const char *str)
{
	g_status = kInvalid;
	long num=0;

	if( str!=NULL && *str!='\0' )
	{
		bool minus=false;
		if( *str == '+' )
			str++;
		else if( *str == '-' )
		{
			str++;
			minus = true;
		}

		if( *str != '\0' )
		{
			num = stringToIntegerCore(str, minus);			
		}
	}

	return (int)num;
}

long stringToIntegerCore(const char* str, bool minus)
{
	long num=0;
	int flag = minus ? -1 : 1;

	while( *str != '\0' )
	{
		if( *str >= '0' && *str <= '9' )
		{
			num = num*10 + flag*(*str - '0');
			if( (!flag && num>0x7FFFFFFF) || (flag && num<(signed)0x80000000) )
			{
				break;
			}
			++str;
		}
		else
		{
			break;
		}
	}

	if( *str == '\0' )
		g_status = kValid;

	return num;
}

int main(int argc, char const *argv[])
{
	std::cout << stringToInteger(argv[1]) << endl;

	cout << 0x80000000 << endl;
	return 0;
}
