#include "alg_common.h"
#include <cassert>

using namespace std;
/*输出给定整数对应的字符串，从1到N，如果N % 3 == 0，输出fizz，
如果N % 5 == 0，输出buzz，如果 N % 15 == 0，输出fizzbuzz*/
class Solution
{
public:
	vector<string> fizzBuzz(int n)
	{
		assert(n > 0);
		vector<string> res;
		int i=0;
		for(int i=1, fizz=1, buzz=1; i<=n; ++i, ++fizz, ++buzz)
		{
			if( fizz==3 && buzz==5 )
			{
				res.push_back("FizzBuzz");
				fizz = 0;
				buzz = 0;
				continue;
			}
			if( fizz==3 )
			{
				res.push_back("Fizz");
				fizz = 0;
				continue;
			}
			if( buzz==5 )
			{
				res.push_back("Buzz");
				buzz = 0;
				continue;
			}
			res.push_back(to_string(i));
		}

		return res;
	}

	void show(vector<string> vec)
	{
		size_t len = vec.size();
		int i=0;
		while(i<len)
		{
			std::cout << vec.at(i) << endl;
			++i;
		}
	}
};


int main(int argc, char **argv)
{
	assert(argc == 2);
	vector<string> res;
	Solution sol;
	res = sol.fizzBuzz(atoi(argv[1]));
	sol.show(res);

	return 0;
}