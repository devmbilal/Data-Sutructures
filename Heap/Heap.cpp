// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
using namespace std;
#include"heap.h"
int main()
{
   PriorityQueue<int> pq(5);
	try
	{
		pq.push(10);
		pq.push(15);
		pq.push(20);
		pq.push(9);
		pq.push(4);
		pq.push(2);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	try
	{
		pq.pop();
		pq.pop();
		pq.pop();
		pq.pop();
		pq.pop();
		pq.pop();
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

