//Fibonacci函数适用于以下问题的分析
/*上台阶问题：
	上台阶有两种方式，1.一次一台阶，2.一次二台阶，则只有一台阶时，一种方法，二台阶时两种方法，
	当台阶数大于2时，则上台阶方法为f(n)=f(n-1)+f(n-2)
*/

#include <cstdlib>
#include <stdexcept>
#include <iostream>
using std::logic_error;
using std::cout;
using std::endl;

class CFibonacci
{
public:
	static int Fibonacci(int n)
	{
		if( n<0 )
			throw logic_error("Invalid Parameter");

		int fibons[2]={0,1};
		/*
		if( n==0 )
			return fibons[0];

		if( n==1 )
			return fibons[1];
		*/
		if( n>=0 )
		{
			cout << fibons[0] << ' ';
		}
		if( n>=1 )
		{
			cout << fibons[1] << ' ';
		}
		int fibonsOne = 0;
		int fibonsTwo = 1;
		int fibonsN = 0;
		for( int i=2; i<=n; ++i )
		{
			fibonsN = fibonsOne + fibonsTwo;
			fibonsOne = fibonsTwo;
			fibonsTwo = fibonsN;
			cout << fibonsN << ' ';
		}
		cout << endl;
		return fibonsN;
	}
};

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	CFibonacci::Fibonacci(n);
	return 0;
}