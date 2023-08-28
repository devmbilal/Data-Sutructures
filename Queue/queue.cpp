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