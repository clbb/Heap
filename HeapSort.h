#include<assert.h>
#include<iostream>
using namespace std;

void AdjustDown(int *a,int parent,int n)
{
	int child = 2*parent+1;
	while(child < n)
	{
		if(child+1 < n && a[child+1] > a[child])
			child++;
		if(a[child] > a[parent])
		{
			swap(a[child],a[parent]);
			parent = child;
			child = 2*parent+1;
		}
		else
			break;
	}
}
int* HeapSort(int *a,int n)
{
	assert(a);
	//1 建堆
	for(int i = (n-2)/2; i>=0; --i)
	{
		AdjustDown(a,i,n);
	}
	//2.向下调整
	for(int i = 0; i <= n; ++i)
	{
		swap(a[0],a[n-i-1]);
		AdjustDown(a,0,n-i-1);
	}
	return a;

}
void Print(int *a,int n)
{
	for(int i = 0; i<n;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
void TestSort()
{
	int a[] = {10,16,18,12,11,13,14,17,15,19};
	HeapSort(a,sizeof(a)/sizeof(a[0]));
	Print(a,10);
}
