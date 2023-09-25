// Binary-Search-Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include"bst.h"
using namespace std;
template<typename T>
void print(BST<T>);
int main()
{
	BST<int> b;
	try
	{
		b.insert(4);
		b.insert(2);
		b.insert(7);
		b.insert(8);
		b.insert(9);
		b.insert(3);
		b.insert(6);
		print(b);
	}
	catch (const char*msg)
	{
		cout << msg << endl;
	}
	
}
template<typename T>
void print(BST<T> b)
{
	cout << "PRE-ORDER" << endl;
	b.reset(PRE_ORDER);
	while (!b.is_last(PRE_ORDER))
	{
		int val; val = b.get_next(PRE_ORDER);
		cout << val << " ";
	}
	cout << endl;
	cout << "IN-ORDER" << endl;
	b.reset(IN_ORDER);
	while (!b.is_last(IN_ORDER))
	{
		int val; val = b.get_next(IN_ORDER);
		cout << val << " ";
	}
	cout << endl;
	cout << "POST-ORDER" << endl;
	b.reset(POST_ORDER);
	while (!b.is_last(POST_ORDER))
	{
		int val;
		val = b.get_next(POST_ORDER);
		cout << val << " ";
	}
	cout << endl;
	cout << "LEVEL-ORDER" << endl;
	b.reset(LEVEL_ORDER);
	while (!b.is_last(LEVEL_ORDER))
	{
		int val; val = b.get_next(LEVEL_ORDER);
		cout << val << " ";
	}
	cout << endl;
}
