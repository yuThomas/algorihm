//根据输入值N，打印从1到N位的所有数值
//陷阱:
//	考虑N特别大的情况

#include <string.h>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using std::logic_error;
using std::cout;
using std::endl;

class CNumberPrinter
{
public:
	CNumberPrinter(int N);
	~CNumberPrinter();
	void Print();

private:
	int m_arrLength;
	char *m_arr;

	bool IsOverflow();
	void PrintNumber();
	CNumberPrinter(const CNumberPrinter&);
	CNumberPrinter& operator=(const CNumberPrinter&);
};

CNumberPrinter::CNumberPrinter(int N):m_arrLength(N),m_arr(NULL)
{
	if( N<= 0 )
		throw logic_error("Invalid Input");

	m_arr = new char[m_arrLength+1];
	memset(m_arr, '0', m_arrLength+1);
	m_arr[m_arrLength] = '\0'; 
}

CNumberPrinter::~CNumberPrinter()
{
	delete [] m_arr;
}

void CNumberPrinter::Print()
{
	while( !IsOverflow() )
		PrintNumber();
}

bool CNumberPrinter::IsOverflow()
{
	bool overFlow = false;
	int carry = 0;
	int nSum = 0;
	for( int i=m_arrLength-1; i>=0; --i )
	{
		nSum = m_arr[i] - '0' + carry;
		if( i==m_arrLength-1 )
			++nSum;

		//累计加如果超过10，则考虑是否益出
		if( nSum>=10 )
		{
			if( i==0 ) //最高位溢出
				overFlow = true;
			else
			{
				nSum -= 10;
				carry = 1;
				m_arr[i] = nSum + '0';
			}
		}
		else
		{
			m_arr[i] = nSum + '0';
			break;	
		}
	}

	return overFlow;
}

void CNumberPrinter::PrintNumber()
{
	int zeroCount=0;
	int i=0;
	while( m_arr[i++] == '0' )
		++zeroCount;

	cout << m_arr+zeroCount << endl;	
}

int main(int argc, char **argv)
{
	try
	{
		CNumberPrinter  printer(atoi(argv[1]));
		printer.PrintRecursive();	
	}
	catch(logic_error &e)
	{
		cout << e.what() << endl;
	}

	return 0;
}