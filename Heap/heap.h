#pragma once
#include<iostream>
using namespace std;
template<typename T>
class PriorityQueue
{
private:
	T* data;
	int a_size;
	int n;
public:
	PriorityQueue(int s = 100)
	{
		a_size = s;
		n = 0;
		data = new T[a_size];
	}
	void ReheapUp(T* data, int root, int last)
	{
		// last is index of last element
	   // root is index of root node
		int parent = (last - 1) / 2;
		if (last>root && data[last] > data[parent])
		{
			swap(data[last], data[parent]);
			ReheapUp(data, 0, parent);
		}
	}
	void push(const T& val)
	{
		if (full())
			throw("Priority Queue Overflow ! ");
		data[n] = val;
		ReheapUp(data,0,n);
		n++;
	}
	bool empty() const
	{
		return n == 0;
	}
	bool full() const 
	{
		return n == a_size;
	}
	T top() const
	{
		if (empty())
			throw("Priority Queue Underflow !");
		return data[0];
	}
	void pop()
	{
		if (empty())
			throw("Priority Queue Underflow !");
		data[0] = data[n - 1];
		n--;
		ReheapDown(data, 0, n - 1);
	}
	void ReheapDown(T* data, int root, int last)
	{
		int left, right, max;
		left = (root * 2) + 1;
		right = (root* 2) + 2; //left+1
		max = left;
		if (left<=last) // check if left exist
		{
			if (right <= last)  // check if right exist
			{
				if (data[right] > data[left])
					max = right;
			}
		}
		// check if current is smaller than max node
		if (data[root] < data[max])
		{
			swap(data[root], data[max]);
			ReheapDown(data, max, last);
		}	
	}
	void heap_sort(T* data, int n)
	{
		// heapify
		for(int i=(n/2)-1;i>=0;i--)
		{
			ReheapDown(data,i,n-1);
		}
		// Sorting
		for (int i = n-1; i>0; i--)
		{
			swap(data[0], data[i]);
			ReheapDown(data, 0,i-1);
		}
	}
};
