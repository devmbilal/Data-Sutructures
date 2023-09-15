// List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
//#include"list.h"              //checked ok
//#include"linklist.h"          //checked ok
//#include"slinklist.h"         //checked ok
#include"clinklist.h"        
//#include"dlinklist.h"         // checked ok

int main()
{
	// Objects of List and Linked List

	CLlist<int> list;

	int choice;
	int val;
	cout << endl;
	cout << "                Menu options" << endl;
	cout << endl;
	cout << "To Find               Press 1" << endl;
	cout << "To Insert             Press 2" << endl;
	cout << "To Erase              Press 3" << endl;
	cout << "To Update             Press 4" << endl;
	cout << "To Print              Press 5" << endl;
	cout << "To Exist              Press 0" << endl;
	cout << endl;
	cout << "Enter the choice : ";
	cin >> choice;
	cout << endl;
	do
	{
		try
		{
			switch (choice)
			{
			case 1:
				cout << "Enter the value which you want to search : ";
				cin >> val;
				if (list.find(val))
					cout << "Value Found" << endl;
				else
					cout << "Value not Found" << endl;
				break;
			case 2:
				cout << "Enter the value which you want to Insert : ";
				cin >> val;
				list.insert(val);
				break;
			case 3:
				cout << "Enter the value which you want to Delete : ";
				cin >> val;
				if (list.erase_all(val))
					cout << "Values Deleted" << endl;
				else
					cout << "Value not Found" << endl;
				break;
			case 4:
				int old_val;
				cout << "Enter the value which you want to update : ";
				cin >> val;
				cout << "Enter the value with which you want to update : ";
				cin >> old_val;
				if (list.update_all(old_val, val))
					cout << "Value Updated" << endl;
				else
					cout << "Value not Found" << endl;
				break;
			case 5:
				list.reset();
				while (!list.is_last())
				{
					val = list.get_next();
					cout << val << " ";
				}
				break;
			}
		}
		catch (const char*msg)
		{
			cout << msg << endl;
		}
		cout << endl;
		cout << "                Menu options" << endl;
		cout << endl;
		cout << "To Find               Press 1" << endl;
		cout << "To Insert             Press 2" << endl;
		cout << "To Erase              Press 3" << endl;
		cout << "To Update             Press 4" << endl;
		cout << "To Print              Press 5" << endl;
		cout << "To Exist              Press 0" << endl;
		cout << endl;
		cout << "Enter the choice : ";
		cin >> choice;
		cout << endl;
	} while (choice != 0);
}