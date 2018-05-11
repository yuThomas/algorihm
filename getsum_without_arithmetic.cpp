/*
	不用加、减、乘、除计算两个数的和
*/

#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

int getSumWithoutArithmetic(int num1, int num2)
{
	int carry=0;
	int sum=0;
	do
	{
		sum = num1 ^ num2; //不计进位的二进制加法
		carry = (num1 & num2) << 1; //进位
		
		num1 = sum;
		num2 = carry;
	}while( num2 != 0 );

	return num1;
}


int main(int argc, char **argv)
{
	if( argc != 3 )
		exit(0);
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	cout << getSumWithoutArithmetic(num1, num2);

	cout << endl;
	return 0;
}
