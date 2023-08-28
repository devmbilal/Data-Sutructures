#pragma once
#include<iostream>
using namespace std;
class CircularQueue
{
	int size;
	int r_ind;
	int f_ind;
	int* data;
	int n_elements;
public:
	CircularQueue(int size = 100);
	~CircularQueue();
	CircularQueue(const CircularQueue&);
	void push(int val);
	void pop();
	bool empty() const;
	bool full() const;
	void make_emty();
	int front() const;
	int rare() const;
	const CircularQueue& operator=(const CircularQueue&);
};