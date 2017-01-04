#include"Heap.h"

template <class T ,class compare=Greater<T> > 
class Priority_Queue
{
public:
	void Push(const T& x)
	{	
		_hp.Push(x);
	}
	void Pop()
	{
		_hp.Pop();
	}
	const T& Top()
	{
		return _hp.Top();
	}
	size_t Size()
	{
		return _hp.Size();
	}
	bool Empty()
	{
		return _hp.Empty();
	}
	void Print()
	{
		_hp.Print();
	}
protected:
	Heap<T,compare> _hp;
};
void TestPQ()
{
	Priority_Queue<int,Less<int> > q;
	q.Push(10);
	q.Push(11);
	q.Push(12);
//	q.Push(11);
	q.Push(2);
	//cout<<q.Top()<<endl;
	q.Print();	
	q.Pop();
	q.Print();	
	q.Pop();
	q.Print();	
	
	
}
