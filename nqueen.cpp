#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <tr1/memory>
#include <vector>

#include <pthread.h>
using namespace std;
class CQueen
{
public:
	CQueen(int qnum): m_qnum(qnum),m_sort(m_qnum,-1)
	{
	}
	void findAllSorts(int n)
	{
		if( n>=m_qnum )
			return;
		for( int index=0; index<m_qnum; ++index )
		{
			if( !isConflict(n, index) )
			{
				m_sort[n]=index;
				if( n==m_qnum-1 )
				{
					m_data.push_back(m_sort);
				}
				findAllSorts(n+1);
			}
		}
	}
	bool isConflict(int rowIndex, int colValue )
	{
		for( int index=0; index<rowIndex; ++index )
		{
			if( m_sort[index]==colValue || abs(colValue-m_sort[index])==abs(rowIndex-index) )
				return true;
		}
		return false;
	}
	void printAllSorts()
	{
		for( auto v : m_data )
		{
			for( auto num : v )
				cout << num << ' ';
			cout << endl;
		}
	}
private:
	int m_qnum;
	vector<int> m_sort;
	vector<vector<int> > m_data;
};

int main(int argc, char** argv)
{
	CQueen q(4);
	q.findAllSorts(0);
	q.printAllSorts();
	return 0;
}
