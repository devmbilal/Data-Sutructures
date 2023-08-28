#include"queue.h"
CircularQueue::CircularQueue(int size)
{
	this->size = size + 1;
	data = new int[size];
	r_ind = f_ind =n_elements= 0;
}
CircularQueue::~CircularQueue()
{
	//delete [] data;
}
CircularQueue::CircularQueue(const CircularQueue& q)
{
	data = NULL;
	operator=(q);
}
void CircularQueue::push(int val)
{
	if (full())
		throw("CircularQueue Overflow");
	r_ind = (r_ind + 1) % size;
	data[r_ind] = val;
}

void CircularQueue::pop()
{
	if (empty())
		throw("CircularQueue Underflow");
	f_ind = (f_ind + 1) % size;
}
bool CircularQueue::empty() const
{
	return f_ind == r_ind;
}

bool CircularQueue::full() const
{
	return (r_ind+1)%size == f_ind;
}


void CircularQueue::make_emty()
{
	r_ind = f_ind = 0;
	// r_ind = f_ind;
	// r_ind = f_ind = size- 1;
}


int CircularQueue::front() const
{
	if (empty())
		throw("CircularQueue Underflow");
	return data[(f_ind + 1) % size];
}
int CircularQueue::rare() const
{
	if (empty())
		throw("CircularQueue Underflow");
	return data[r_ind];
}

const CircularQueue& CircularQueue::operator=(const CircularQueue& q)
{
	if (this != &q)
	{
		size = q.size;
		r_ind = q.r_ind;
		f_ind = q.f_ind;
		n_elements = q.n_elements;
		if (data!=NULL)
			delete [] data;
		data = new int[size];
		int f = f_ind + 1;
		while (f_ind!=r_ind+1)
		{
			data[f] = q.data[f];
			f = (f + 1) % size;
		}
	}
	return*this;
}