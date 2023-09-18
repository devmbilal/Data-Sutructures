// Hashing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
#include"hash.h"
int main()
{
	HashChain<int> h(10);
	h.insert(50);
	h.insert(30);
	h.insert(40); 
	h.insert(70);
	h.insert(10);
	if (h.find(50))
		cout << "Value Found" << endl;
	else
    	cout << "Value not Found" << endl;
	
}

