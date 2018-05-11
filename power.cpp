//实现库函数double power(double, double)

#include <iostream>
#include <cstdlib>
#include "log.h"

using std::cout;
using std::endl;

class CPower
{
public:
	static double Power(double, double);

private:
	static bool Equal(double, double);
	static double PowerWithUnsignedExponent(double, unsigned int);
};

double CPower::Power(double base, double exponent)
{
	if( Equal(base, 0.0) && exponent<0 )
		CLog::LoggerError("%s:%d %s: Invalid Input\n", __FILE__, __LINE__, __FUNCTION__); 

	unsigned int absExponent  = (unsigned int)exponent;
	if( exponent<0 )
	{
		absExponent = (unsigned int)(-exponent);
	}
	double result = PowerWithUnsignedExponent(base, exponent);
	if( exponent<0 )
		result = 1.0 / result;

	return result;
}

double CPower::PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if( exponent==0 )
		return 0.0;
	if( exponent==1 )
		return base;

	double result = PowerWithUnsignedExponent(base, exponent>>1);
	result *= result;
	if( exponent & 0x01 )
		result *= base;

	return result;
}

bool CPower::Equal(double v1, double v2)
{
	double diff = v1 - v2;
	if( diff>-0.0000001 && diff<0.0000001 )
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	double base = strtod(argv[1], NULL);
	double exponent = strtod(argv[2], NULL);

	cout << CPower::Power(base, exponent) << endl;
	return 0;
}