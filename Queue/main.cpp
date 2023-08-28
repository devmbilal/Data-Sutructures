// Queue Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include"queue.h"
using namespace std;
int main()
{
	CircularQueue cq(5);
		try
		{
			cq.push(5);
			cq.push(5);
			cq.push(5);
			cq.push(5);
			cq.push(5);
			cq.push(5);
		}
		catch (const char*msg)
		{
			cout << msg << endl;
		}
		try
		{
			cq.pop();
			cq.pop();
			cq.pop();
			cq.pop();
			cq.pop();
			cq.pop();
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
}
