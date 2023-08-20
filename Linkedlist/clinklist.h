#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct node
{
	T info;
	node<T>* link;
	
};
template<typename T>
class CLlist
{
	node<T>* head;
	node<T>* tail;
	int n,t;
	node<T>* t_ptr;
public:
	CLlist();
	CLlist(const CLlist<T>& l);
	~CLlist();
	const CLlist& operator=(const CLlist& l);
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
CLlist<T>::CLlist()
{
	head = tail = t_ptr = NULL;
	n = 0;
	t = 0;
}
template<typename T>
CLlist<T>::CLlist(const CLlist<T>& l)
{
	head = tail = t_ptr = NULL;
	operator=(l);
}
template<typename T>
CLlist<T>::~CLlist()
{
	clear();
}
template<typename T>
const CLlist<T>& CLlist<T>::operator=(const CLlist<T>& l)
{
	if (this != &l)
	{
		if (head != NULL)
		{  
			clear();     	           // if List is not empty
		}
		node* temp;
		temp = l.head;
		while (temp != tail)
		{
			insert(temp->info);
			temp = temp->link;
		}
		insert(temp->info);
	}
	return*this;
}
template<typename T>
void CLlist<T>::insert(const T& val)
{
	node<T>* temp;
	temp = new node;
	temp->info = val;
	temp->link = NULL;
	//if List is Empty
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		tail->link = head;
		n++;
		return;
	}
	// Insert at the start of the List
	if (val < head->info)
	{
		temp->link = head;
		head = temp;
		tail->link = head;
		n++;
		return;
	}
	//Insert at the end or middle of the list
	else
	{
		node<T>* ptr;
		ptr = head;
		while (ptr->link!=head)
		{
			if (val < ptr->link->info)
			{
				temp->link = ptr.link;
				ptr->link = temp;
				n++;
				return;
				
			}
			ptr = ptr->link;
		}
		// Insert at the End
		if (ptr->link==head)
		{
			tail->link = temp;
			tail = temp;
			tail->link = head;
			n++;
			return;
		}
		
	}
}
template<typename T>
bool CLlist<T>::find(const T& val) const
{
	node<T>* p;
	p = head;
	do
	{
		if (p.info == val)
			return true;
		p = p.link;
	}
	while (p != head && val > p->info);
	return false;
}
template<typename T>
bool CLlist<T>::update(const T& old_val, const T& new_val)
{
	if (erase(old_val))
	{
		insert(new_val);
		return true;
	}
	return false;
}
template<typename T>
int CLlist<T>::update_all(const T& old_val, const T& new_val)
{
	int up = 0;
	while (update(old_val,new_val))
	{
		up++;
	}
	return up;
}
template<typename T>
bool CLlist<T>::erase(const T& val)
{
	if (head == NULL)
	{
		throw("List is Empty");        // if list is empty
	}
	node<T>* temp;
	temp = head;
	if (head->info == val)    // Deleting First Node
	{
		if (tail == head)
		{
			delete temp;
			head = tail = NULL;     //if there is only one node
			n--;
			return true;
		}
		head = head->link ;
		tail->link = head;
		delete temp;
		n--;
		return true;
	}
	node<T>* pre;
	pre = temp;
	temp = temp.link;
	while (temp != head)          // Deleting Last or Middle Node
	{
		if (temp.info == val)
		{
			pre.link = temp.link;
			n--;
			if (temp.link == head)
			{
				tail = pre;          // Last Node
				                   
			}
			delete temp;
			return true;
		}
		pre = pre.link;
		temp = temp.link;
	}
	return false;
}
template<typename T>
int CLlist<T>::erase_all(const T& val)
{
	int er = 0;
	while (erase(val))
	{
		er++;
	}
	return er;
}
template<typename T>
bool CLlist<T>::empty() const
{
	return head == NULL;
}
template<typename T>
int CLlist<T>::size() const
{
	return n;
}
template<typename T>
bool CLlist<T>::full()  const
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
void CLlist<T>::clear()
{
	node<T>* temp;
	while (head!=tail)
	{
		temp = head; 
		head = head.link;
		delete temp;
	} 
	delete head;
 	head = tail = NULL;
	n = 0;
}

// Implementation of Traversal Functions

template<typename T>
void CLlist<T>::reset()
{
	t_ptr = head;
	t = 0;
}
template<typename T>
T CLlist<T>::get_next()
{
	if (empty())
		throw("List is empty");
	T val = t_ptr->info;
	t_ptr = t_ptr->link;
	t++;
	return val;
}
template<typename T>
bool CLlist<T>::is_last()
{
	return t == n;
}