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
class Linklist
{
private:
	int n;
	node<T>* head, * tail;
	node<T>* t_ptr;
public:
	Linklist();
	Linklist(const Linklist<T>& l);
	~Linklist();
	const Linklist& operator=(const Linklist& l);
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

// Implementation of Class Linklist

template<typename T>
Linklist<T>::Linklist()
{
	head = tail = t_ptr = NULL;
	n = 0;
}
template<typename T>
Linklist<T>::Linklist(const Linklist<T>& l)
{
	head = tail = t_ptr = NULL;
	operator=(l);
}
template<typename T>
Linklist<T>::~Linklist()
{
	clear();
}
template<typename T>
const Linklist<T>& Linklist<T>::operator=(const Linklist<T>& l)
{
	if (this != &l)
	{
		if (head != NULL)
		{
			clear();
		}
		node* temp;
		temp = l.head;
		while (temp != NULL)
		{
			insert(temp->info);
			temp = temp->link;
		}
	}
	return*this;
}
template<typename T>
void Linklist<T>::insert(const T& val)
{
	node<T>* ptr;
	ptr = new node<T>;
	ptr->info = val;
	ptr->link = NULL;
	if (head == NULL)
	{
		head = ptr;
	}
	else
	{
		tail->link = ptr;
	}
	tail = ptr;
	n++;
}
template<typename T>
bool Linklist<T>::find(const T& val) const
{
	node<T>* p;
	p = head;
	while (p != NULL)
	{
		if (p->info == val)
			return true;
		p = p->link;
	}
	return false;
}
template<typename T>
bool Linklist<T>::update(const T& old_val, const T& new_val)
{
	node<T>* p;
	p = head;
	while (p != NULL)
	{
		if (p->info == old_val)
		{
			p->info = new_val;
			return true;
		}
		p = p->link;
	}
	return false;
}
template<typename T>
int Linklist<T>::update_all(const T& old_val, const T& new_val)
{
	node<T>* p;
	int update = 0;
	p = head;
	while (p != NULL)
	{
		if (p->info == old_val)
		{
			p->info = new_val;
			update++;
		}
		p = p->link;
	}
	return update;
}
template<typename T>
bool Linklist<T>::erase(const T& val)
{
	if (head == NULL)
	{
		throw("List is Empty");          // if list is empty
	}
	node<T>* temp, * pre;
	temp = head;
	if (head->info == val)     // Deleting First Node
	{
		head = head->link;
		delete temp;
		if (head == NULL)
		{
			tail = NULL;    //if there is one node
		}
		n--;
		return true;
	}
	pre = temp;            //Deleting Last or Middle Node
	temp = temp->link;
	while (temp != NULL)
	{
		if (val == temp->info)
		{
			pre->link = temp->link;
			n--;
			if (temp->link == NULL)
			{
				tail = pre;        // Last Node
			}
			delete temp;
			return true;
		}
		pre = pre->link;
		temp = temp->link;
	}
	return false;
}
template<typename T>
int Linklist<T>::erase_all(const T& val)
{
	int er = 0;
	while (erase(val))
	{
		er++;
	}
	return er;
}
template<typename T>
bool Linklist<T>::empty() const
{
	return head == NULL;
}
template<typename T>
int Linklist<T>::size() const
{
	return n;
}
template<typename T>
bool Linklist<T>::full()  const
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
void Linklist<T>::clear()
{
	node<T>* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->link;
		delete temp;
	}
	tail = NULL;
	n = 0;
}

// Implementation of Traversal Functions

template<typename T>
void Linklist<T>::reset()
{
	t_ptr = head;
}
template<typename T>
T Linklist<T>::get_next()
{
	if (empty())
		throw("List is empty");
	T val = t_ptr->info;
	t_ptr = t_ptr->link;
	return val;
}
template<typename T>
bool Linklist<T>::is_last()
{
	return t_ptr == NULL;
}
