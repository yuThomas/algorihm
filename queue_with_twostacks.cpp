#include <stack>
#include <iostream>

using std::stack;
using std::cout;
using std::endl;

template<typename T>
clas CQueue
{
public:
	CQueue(){}
	~CQueue(){}
	void pushBack(const T &);
	T popFront();
private:
	stack<T> m_stackPush;
	stack<T> m_stackPop;
};

tempalte<T>
void CQueue<T>::pushBack(const T &value)
{
	m_stackPush.push(value);
}

tempalte<T>
T CQueue<T>::popFront()
{
	if( m_stackPop.empty() )
	{
		if( m_stackPush.empty() )
			throw logic_error("Empty Queue");
		while( !m_stackPush.emtpy() )
		{
			m_stackPop.push(m_stackPush.top());
			m_stackPush.pop();
		}
	}

	T head = m_stackPop.top();
	m_stackPop.pop();

	return head;
}