#include <queue>

using std::queue;

template<typename T>
class CStack
{
public:
	CStack(){}
	~CStack(){}

	void push(T &);
	T  pop();
private:
	queue<T> m_queue1;
	queue<T> m_queue2;

	void _push(queue<T> &qdata, T &element);
	void _pop(queue<T> &qdata, queue<T> &qempty);
};

template<typename T>
void CStack::push(T &element)
{
	if( m_queue2.empty() || m_queue1.empty() )
	{
		if( m_queue1.empty() && m_queue2.emtpy() )
			_push(m_queue1, element);
		else if( m_queue1.empty() )
			_push(m_queue2, element);
		else 
			_push(m_queue1, element);
	}
	else
		throw logic_error("Invalid Stack Data");
}

template<typename T>
T CStack::pop()
{
	if( m_queue2.empty() && m_queue1.empty() )
		throw logic_error("Empty Stack");
	else if( m_queue1.emtpy() )
		return _pop(m_queue2, m_queue1);
	else if( m_queue2.empty() )
		return _pop(m_queue1, m_queue1);
	else
		throw logic_error("Invalid Stack Data");
}

template<typename T>
void CStack::_push(queue<T> &qdata, T &element)
{
	qdata.push(element);
}

template<typename T>
T CStack::_pop(queue<T> &qdata, queue<T> &qempty)
{
	while( qdata.size() != 1)
	{
		qempty.push(qdata.front());
		qdata.pop();
	}

	T head = qdata.front();
	qdata.pop():
	return head;
}