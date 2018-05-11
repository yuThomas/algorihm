/*
	八皇后问题，使用回溯法;以此可以类推到N皇后问题
*/

#include <cstdlib>
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class CQueen
{
public:
	CQueen(int row , int column);
	vector<vector<int> >  findAllSorts();
	void printAllSorts();

private:
	int m_row;
	int m_column;
	vector<vector<int> > m_data;
	void findAllSortsCore(int rowIndex, int colIndex, vector<int> &candicate);
	bool isConflict(int rowIndex, int colIndex, const vector<int> &v);
};

CQueen::CQueen(int row, int column):m_row(row), m_column(column)
{
//	m_arr[m_row][m_column] = {0};
}

vector<vector<int> > CQueen::findAllSorts()
{
	vector<int> candicate;
	findAllSortsCore(0,0, candicate);
	return m_data;
}

void CQueen::findAllSortsCore(int rowIndex, int colIndex, vector<int> &candicate)
{
	if( rowIndex>=m_row || rowIndex>=m_column )
	{
		return;
	}
	if( !isConflict( rowIndex, colIndex, candicate ) )	
	{
		candicate.push_back(colIndex);
		if( candicate.size() == m_column )
		{
			m_data.push_back(candicate);
			return;
		}
		findAllSortsCore(rowIndex+1, 0, candicate);
	}
	//如果当前行列与前面的产生冲突，则依次遍历列索引，找到合适的位置
	for( int index=colIndex+1; index<m_column; ++index )
	{
		if( candicate.size()==m_column )
		{
			candicate.pop_back();
		}
		findAllSortsCore(rowIndex, colIndex, candicate);
	}
	//向上层回溯的时候，去掉上层已经匹配的列，开始新的列匹配
	if( !candicate.empty() )
	{
		candicate.pop_back();
	}
}
	
bool CQueen::isConflict(int rowIndex, int colIndex, const vector<int> &v)
{
	/*
		容器V中是按行从上到下的顺序插入数据的，存储的是各行中列的值，因此v的大小
		即已分配位置的最大行
	*/
	size_t len=v.size();
	for( size_t rindex=0; rindex<len; ++rindex )
	{
		if( colIndex==v[rindex] || abs(colIndex-v[rindex])==abs(rowIndex-rindex) )
			return true;
	}	
	return false;
}

void CQueen::printAllSorts()
{
	for( auto v : m_data )
	{
		for( auto num : v )
		{
			cout << num << ' ';
		}
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	CQueen  q(8,8);
	q.findAllSorts();
	q.printAllSorts();
}
