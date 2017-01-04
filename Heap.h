#pragma once
#include<iostream>
using namespace std;
#include<vector>
//静态二叉树 堆
//
template <class T>
struct Less
{
	bool operator()(const T& l,const T& r)
	{
		return l < r;
	}
};
template <class T>
struct Greater
{
	bool operator()(const T& l,const T& r)
	{
		return l > r;
	}
};
template <class T,class Compare=Greater<T> >//
class Heap
{
public:
	Heap()
	{}

	Heap(T* a,int n)
	//	:_a(a,a+n)
	{
		_a.reserve(n);
		for(int i = 0; i<n;++i)
		{
			_a.push_back(a[i]);
		}
		for(int i = (_a.size()-2)/2; i>=0; --i)
		{
			AdjustDown(i);
		}
	}
	size_t Size()
	{
		return _a.size();
	}
	void Print()
	{
		for(int i = 0; i<Size();++i)
			cout<<_a[i]<<" ";
		cout<<endl;
	}
//	void Print()
//	{
//		vector<int>::iterator it = _a.begin();
//		while(it != _a.end())
//		{
//			cout<<*it<<" ";
//			it++;
//		}
//		cout<<endl;
//	}
	T& Top()
	{
		return _a[0];
	}
	bool Empty()
	{
		return _a.empty();
	}
	void Push(const T& x)
	{
		_a.push_back(x);
		AdjustUp(_a.size()-1);	
	}	
	void Pop()
	{
		if(Empty())
			return;
		swap(_a[0],_a[Size()-1]);
		_a.pop_back();
		AdjustDown(0);
	}
protected:
	void AdjustUp(int child)
	{
		int parent = (child-1)/2;
		while(child > 0)
		{
			if(Compare()(_a[child],_a[parent]))
			//if(_a[child] > _a[parent])
			{
				swap(_a[child] ,_a[parent]);
				child = parent;
				parent = (child-1)/2;
 			}
			else 
				break;
		}
	}
	void AdjustDown(int parent)
	{
		Compare com;
		int child = parent*2+1;
		while(child < _a.size())
		{
			if(child+1 < _a.size() && com(_a[child+1],_a[child])) //_a[child+1] > _a[child])
				child++;
			if(com(_a[child],_a[parent]))
		//	if(_a[child] > _a[parent])
			{
				swap(_a[child],_a[parent]);  
				parent = child; 
				child = parent*2+1;
			}
			else 
				break;
		}
	}
protected:	
	vector<T> _a;
};
void Test()
{
	int a[] = {10,16,18,12,11,13,14,17,15,19};
	
	Heap<int,Less<int> > h(a,sizeof(a)/sizeof(a[0]));
//	Print_(a,10);
	h.Print();
	h.Push(20);
	h.Push(0);
	h.Print();
	h.Pop();
	h.Print();
	h.Pop();
	h.Print();
}
