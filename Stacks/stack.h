#pragma once
#include<string>
// Int Stack
class Stack
{
	int*arr;
	int size;
	int top_index;
public:
	Stack(int n = 100);
	~Stack();
	void pop();
	void push(const char& val);
	int top();
	bool empty();
};
// Implementation of Int Stack
Stack::Stack(int n)
{
	arr = new int[n];
	size = n;
	top_index = -1;
}
void Stack::pop()
{
	if (empty())
		throw("Stack  Underflow");
	top_index--;
}
void Stack::push(const char& val)
{

	if (top_index == size - 1)
		throw ("Stack  Overflow");
	top_index++;
	arr[top_index] = val;

}
Stack::~Stack()
{
	delete[] arr;
}
int Stack::top()
{
	if (empty())
		throw("Stack  is Empty");
	return arr[top_index];

}
bool Stack::empty()
{
	return top_index == -1;
}


// Char Stack

class CStack
{
	char *arr;
	int size;
	char top_index;
public:
	CStack(int n = 100);
	~CStack();
	void pop();
	void push(const char& val);
	char top();
	bool empty();
};
// Implementation of Char Stack
CStack::CStack(int n)
{
	arr = new char[n];
	size = n;
	top_index = -1;
}
void CStack::pop()
{
	if (empty())
		throw("Stack  Underflow");
	top_index--;
}
void CStack::push(const char& val)
{

	if (top_index == size - 1)
		throw ("Stack  Overflow");
	top_index++;
	arr[top_index] = val;

}
CStack::~CStack()
{
	delete[] arr;
}
char CStack::top()
{
	if (empty())
		throw("Stack  is Empty");
	return arr[top_index];
}
bool CStack::empty()
{
	return top_index == -1;
}


// String Stack

class SStack
{
	string*arr;
	int size;
	char top_index;
public:
	SStack(int n = 100);
	~SStack();
	void pop();
	void push(const string& val);
	string top();
	bool empty();
};
// Implementation of String Stack
SStack::SStack(int n)
{
	arr = new string[n];
	size = n;
	top_index = -1;
}
void SStack::pop()
{
	if (empty())
		throw("Stack  Underflow");
	top_index--;
}
void SStack::push(const string &val)
{

	if (top_index == size - 1)
		throw ("Stack  Overflow");
	top_index++;
	arr[top_index] = val;
}
SStack::~SStack()
{
	delete[] arr;
}
string SStack::top()
{
	if (empty())
		throw("Stack  is Empty");
	return arr[top_index];
}
bool SStack::empty()
{
	return top_index == -1;
}