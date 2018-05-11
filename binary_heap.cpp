#include <iostream>
#include <string.h>
#include <cassert>

class BinaryHeap
{
public:
	BinaryHeap():m_size(0), m_capacity(0), m_heap(nullptr){}
	BinaryHeap(int *arr, int size): m_size(0), m_capacity(0), m_heap(nullptr)
	{
		assert(arr != nullptr);
		m_capacity = size << 1;
		m_heap = new int[m_capacity];
		for(int i=0; i<size; ++i)
			Push(arr[i]);
	}

	void Push(int val)
	{
		if(m_size >= m_capacity)
		{
			m_capacity <<= 1;
			int *temp = new int[m_capacity];
			memcpy(temp, m_heap, m_size);
			delete m_heap;
			m_heap = temp;
			temp = 0;
		}
		++m_size;
		m_heap[m_size-1] = val;
		ShiftUp(m_size-1);
	}

	int Pop()
	{
		int temp = m_heap[0];
		m_heap[0] = m_heap[m_size-1];
		--m_size;
		ShfitDown(0);
		return temp;
	}

	inline int Peek()
	{
		assert(m_size != 0);
		return m_heap[0];
	}

	~BinaryHeap()
	{
		delete [] m_heap; 
	}

private:
	void ShiftUp(int index)
	{
		int key = m_heap[index];
		for( ; index>0; ) 
		{
			int parent = (index-1)>>1;
			if(m_heap[parent] <= key)//大于其父节点
			{
				break;
			}
			m_heap[index] = m_heap[parent]; //小于其父节点
			index = parent;
		}
		m_heap[index] = key;
	}

	void ShfitDown(int index)
	{
		int key = m_heap[index];
		for( ; index<(m_size-1)/2; )
		{
			int child = (index<<1)+1;
			if(child+1<m_size && m_heap[child]>m_heap[child+1])
				++child;
			if(m_heap[child]<=key)
				break;
			m_heap[index] = m_heap[child];
			index = child;
		}
		m_heap[index] = key;
	}
private:
	int  m_size;
	int  m_capacity;
	int  *m_heap;
};