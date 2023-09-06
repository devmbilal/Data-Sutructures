#pragma once
#include"student.h"
using namespace std;
struct node
{
	Student info;
	node* link;
	node():info()
	{
		link = NULL;
	}
};
class Linklist
{
private:
	int n;
	node* head, *tail;
	node *t_ptr;
public:
	Linklist();
	Linklist(const Linklist& l);
	~Linklist();
	const Linklist& operator=(const Linklist&);
	void insert(const Student&);
	bool find(const int& ) const;
	bool updateid(const int& old_val,const int& new_val);
	bool upname(const string& new_val,const int& id);
	bool updep( const string& new_val,const int& id);
	bool upsmes(const int& new_val,const int& id);
	bool upmarks(const int& new_val,const int& id);
	bool updob(const dob& new_val,const int& id);
	bool erase(const int & val);
	int erase_all(const int& val);
	bool empty() const;
	bool full()  const;
	int size() const;
	void clear();
	friend ostream& operator<<(ostream& out, Linklist & l);
	// Traversal Functions
	Student get_next();
	bool is_last();
	void reset();
};


// Implementation of Class Linklist

Linklist::Linklist()
{
	head = tail = t_ptr = NULL;
	n = 0;
}
Linklist::Linklist(const Linklist& l)
{
	head = tail = t_ptr = NULL;
	operator=(l);
}
Linklist::~Linklist()
{
	clear();
}
const Linklist& Linklist::operator=(const Linklist& l)
{
	if (head != NULL)
	{
		clear();
	}
	node* temp;
	temp = l.head;
	while (temp!=NULL)
	{
		insert(temp->info);
		temp = temp->link;
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
	if (head==NULL)
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
	node<T>*p;
	p = head;
	while (p!=NULL)
	{
		if (p->info == val)
			return true;
		p = p->link;
	}
	return false;
}