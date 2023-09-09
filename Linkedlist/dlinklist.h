#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct node
{
	T info;
	node<T>* previous;
	node<T>* next;
	node() 
	{
		previous = NULL;
		next = NULL;
	}
};
template<typename T>
class DLlist
{
	node<T>* head;
	node<T>* tail;
	int n;
	node<T>* t_ptr;
public:
	DLlist();
	DLlist(const DLlist<T>& l);
	~DLlist();
	const DLlist& operator=(const DLlist& l);
	void insert(const T& val);
	bool find(const T& val) const;
	bool update(const T& old_val, const T& new_val);
	int update_all(const T& old_val, const T& new_val);
	bool erase(const T& val);
	int erase_all(const T& val);
	bool empty() const;
	bool full()  const;
	int size() const;
	void clear();
	// Traversal Functions
	T get_next();
	bool is_last();
	void reset();
};
template<typename T>
DLlist<T>::DLlist()
{
	head = tail = t_ptr = NULL;
	n = 0;
}
template<typename T>
DLlist<T>::DLlist(const DLlist<T>& l)
{
	head = tail = t_ptr = NULL;
	operator=(l);
}
template<typename T>
DLlist<T>::~DLlist()
{
	clear();
}
template<typename T>
const DLlist<T>& DLlist<T>::operator=(const DLlist<T>& l)
{
	if (this != &l)
	{
		if (head != NULL)
		{
			clear();
		}
		node*temp;
		temp = l.head;
		while (temp != NULL)
		{
			insert(temp->info);
			temp=temp.next;
		}
	}
	return*this;
}
template<typename T>
void DLlist<T>::insert(const T& val)
{
	node<T>* ptr;
	ptr = new node<T>;
	ptr->info = val;
	ptr->previous = NULL;
	ptr->next = NULL;
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		//insert at the start of the list
		if (val < head->info)
		{
			ptr->next = head;
			ptr->previous = NULL;
			head = ptr;
		}
		// insert at end or middle of the list
		else
		{
			node<T>* temp;
			temp = head;
			while (temp->next != NULL)
			{
				if (val < temp->next->info)
				{
					ptr->next = temp->next;
					ptr->previous = temp;
					temp->next = ptr;
                 	n++;
					return;
				}
				temp = temp->next;
			}
			// insert at the end
			if (temp->next == NULL)
			{
				tail->next = ptr;
				ptr->previous = tail;
				tail = ptr;
			}
		}
	}
	n++;
}
template<typename T>
bool DLlist<T>::find(const T& val) const
{
	node<T>* p;
	p = head;
	while (p != NULL)
	{
		if (p->info == val)
			return true;
		p = p->next;
	}
	return false;
}
template<typename T>
bool DLlist<T>::update(const T& old_val, const T& new_val)
{
	if (erase(old_val))
	{
		insert(new_val);
		return true;
	}
	return false;
}
template<typename T>
int DLlist<T>::update_all(const T& old_val, const T& new_val)
{
	int up = 0;
	while (update(old_val, new_val))
	{
		up++;
	}
	return up;
}
template<typename T>
bool DLlist<T>::erase(const T& val)
{
	if (head == NULL)
	{
		throw("List is Empty");      // if list is empty
	}
	node<T>* temp;
	temp = head;
	if (head->info == val)    // Deleting First Node
	{

		head = head->next;
		delete temp;
		if (head == NULL)    //if there is only one node
		{
			tail = NULL;
			n--;
			return true;
		}
		head->previous = NULL;
		n--;
		return true;
	}
	node<T>* pre;
	pre = temp;
	temp = temp->next;
	while (temp != NULL)          // Deleting Last or Middle Node
	{
		if (temp->info == val)
		{
			pre->next = temp->next;
			delete temp;
			n--;
			if (pre->next == NULL)
			{
				tail = pre;   // Last Node
				return true;
			}
			pre->next->previous = pre;
			return true;
		}
		pre = pre->next;
		temp = temp->next;
	}
	return false;
}
template<typename T>
int DLlist<T>::erase_all(const T& val)
{
	int er = 0;
	while (erase(val))
	{
		er++;
	}
	return er;
}
template<typename T>
bool DLlist<T>::empty() const
{
	return head == NULL;
}
template<typename T>
int DLlist<T>::size() const
{
	return n;
}
template<typename T>
bool DLlist<T>::full()  const
{
	node<T>* p;
	p = new node<T>;
	if (p == NULL)
	{
		return true;
	}
	else
	{
		delete p;
		return p;
	}
}
template<typename T>
void DLlist<T>::clear()
{
	node<T>*temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	tail = NULL;
	n = 0;
}

// Implementation of Traversal Functions

template<typename T>
void DLlist<T>::reset()
{
	t_ptr = head;
}
template<typename T>
T DLlist<T>::get_next()
{
	if (empty())
		throw("List is empty");
	T val = t_ptr->info;
	t_ptr = t_ptr->next;
	return val;
}
template<typename T>
bool DLlist<T>::is_last()
{
	return t_ptr == NULL;
}