#include <iostream>
#include"avl.h"
using namespace std;
template<typename T>
void print(AVL<T>);
int main()
{
	AVL<int> avl;
	try
	{
		avl.insert(4);
		avl.insert(2);
		avl.insert(7);
		avl.insert(8);
		avl.insert(9);
		avl.insert(3);
		avl.insert(6);
		print(avl);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

}
template<typename T>
void print(AVL<T> b)
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