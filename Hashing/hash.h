#pragma once
#include"list.h"
template<typename T>
class HashChain
{
private:
	Linklist<T>* HT;
	int m;
	int hash_div(int key)
	{
		return key % m;
	}
public:
	HashChain(const int s = 97)
	{
		m = s;
		HT = new Linklist<T>[m];
	}
	~HashChain()
	{
		delete[] HT;
	}
	void insert(const T& key)
	{
		int index = hash_div(key);
		HT[index].insert(key);
	}
	bool find(const T& key) 
	{
		int index = hash_div(key);
		return HT[index].find(key);
	}
};

