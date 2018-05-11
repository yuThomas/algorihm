#include "alg_common.h"

using std::cout;
using std::endl;

/*give two integers and return the sum, operator '+' and '-' are forbidden*/

class Solution
{
public:
	int getSum(int a, int b)
	{
		if( a==0 ) return b;
		if( b==0 ) return a;

		int carry=0;
		while( b!=0 )
		{
			/*是否有进位*/
			carry = ( a&b ) << 1;
			/*无需进位的总和*/
			a ^= b;
			b = carry;
		}

		return a;
	}
};

int main(int argc, char const *argv[])
{
	Solution sol;
	cout << sol.getSum(atoi(argv[1]), atoi(argv[2])) << endl;
	return 0;
}