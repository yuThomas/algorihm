#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

/*
	将字符串中的所有字符以单词为单位反转，新的字符串首尾不包含空格，单词之间只能有一个空格
*/
class Solution
{
public:
	string reverseWords(string &str, bool reverse=false)
	{
		if( str.empty() )	
			return str;

		string res;
		blkRemove(str, res);

		if( reverse )
		{
			string tmp;
			size_t lastPos = res.length()-1;
			size_t pos = res.rfind(' ');
			while( pos != string::npos )
			{
				tmp.append(res, pos+1, lastPos-pos);
				tmp.push_back(' ');
				lastPos = pos-1;
				pos = res.rfind(' ', lastPos);
			}
			tmp.append(res, 0, lastPos);	
			res = tmp;
		}
		return res;
	}
private:
	void blkRemove(const string &str, string &res)
	{
		int startIndex=0, nblkIndex=startIndex, endIndex=str.length()-1;
		while( startIndex<=endIndex )
		{
			while( str[startIndex]==' ' && startIndex<=endIndex ) ++startIndex;
			if( startIndex<=endIndex )
			{
				nblkIndex=startIndex;
				while( str[startIndex] != ' ' && startIndex<=endIndex ) ++startIndex;
				res.append(str, nblkIndex, startIndex-nblkIndex);
				res.push_back(' ');
			} 
		}	
		if( !res.empty() )
			res.pop_back();
	}
};

int main(int argc, char **argv)
{
	string s("kadfj akdfj kadjf    akdfjaldjad       alsdkfjals");
	Solution ss;
	string res= ss.reverseWords(s, true);
	cout << res << endl;
}
