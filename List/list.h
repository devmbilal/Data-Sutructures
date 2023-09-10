#pragma once
#include<iostream>
using namespace std;
template<typename T>
class List
{
private:
	T* data;
	int a_size;
	int n;
	int t;
public:
	List(int s = 100);
	List(const List<T>& l);
    ~List();
	const List& operator=(const List& l);
	void insert(const T& val);
	bool find(const T& val) const;
	bool update(const T& old_val, const T& new_val);
	int update_all(const T& old_val, const T& new_val);
	bool erase_all(const T& val);
	bool empty() const;
	bool full()  const;
	int size() const;
	void clear();
	// Traversal Functions
	T get_next();
	bool is_last();
	void reset();
};

// Implementation of Class List

template<typename T>
List<T>::List(int s)
{
	a_size = s;
	data = new T[a_size];
	n = 0;
	t = 0;
}
template<typename T>
List<T>::List(const List<T>& l)
{
	data = NULL;
	operator=(l);
}
template<typename T>
List<T>::~List()
{
	delete [] data;
}
template<typename T>
const List<T>& List<T>::operator=(const List<T>& l)
{
	if (this != &l)
	{
		if (data!=NULL)
		  delete[] data;
		a_size = l.size;
		n = l.n;
		data = new T[a_size];
		for (int i = 0; i < n; i++)
		{
			data[i] == l.data[i];
		}
	}
	return *this;
}
template<typename T>
void List<T>::insert(const T& val)
{
	if (full())
		throw("List Overflow");
	data[n] = val;
	n++;
}
template<typename T>
bool List<T>::find(const T& val) const
{
	for (int i=0;i<n;i++)
	{
		if (data[i] == val)
			return true;
	}
	return false;
}
template<typename T>
bool List<T>::update(const T& old_val, const T& new_val)
{
	bool update = false;
	for (int i = 0; i < n; i++)
	{
		if (data[i] == old_val)
		{
			data[i] = new_val;
			update = true;
		}    
	}
	return update;
}
template<typename T>
int List<T>::update_all(const T& old_val, const T& new_val)
{
	int update = 0;
	for (int i = 0; i < n; i++)
	{
		if (data[i] == old_val)
		{
			data[i] = new_val;
			update++;
		}
	}
	return update;
}
template<typename T>
bool List<T>::erase_all(const T& val)
{
	bool erase = false;
	for (int i = 0; i < n; i++)
	{
		if (data[i] == val)
		{
			data[i] = data[n-1];
			n--;
			i--;
			erase = true;
		}
	}
	return erase;
}
template<typename T>
bool List<T>::empty() const
{
	return n == 0;
}
template<typename T>
int List<T>::size() const
{
	return n;
}
template<typename T>
bool List<T>::full()  const
{
	return n == a_size;
}
template<typename T>
 void List<T>::clear()  
{
	n = 0;
}

// Implementation of Traversal Functions

 template<typename T>
 void List<T>::reset()
 {
	 t = 0;
 }
 template<typename T>
 T List<T>::get_next()
 {
	 if (empty())
		 throw("List Overflow");
	 return data[t++];
 }
 template<typename T>
 bool List<T>::is_last()
 {
	 return t == n;
 }
