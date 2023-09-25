#pragma once
#include<queue>
#include<iostream>
using namespace std;
template<typename T>
struct bnode
{
	T data;
	bnode<T>* left;
	bnode<T>* right;
};
enum Traversal_Types { IN_ORDER, PRE_ORDER, POST_ORDER, LEVEL_ORDER };
template<typename T>
class BST
{
private:
	bnode<T>* root;
	int n;
	queue<int> in_queue,pre_queue, post_queue,level_queue;
	//Member Functions 
	void insertR(bnode<T>*& ptr, const T& val)
	{
		if (ptr == NULL)
		{
			ptr = new bnode<T>;
			ptr->data = val;
			ptr->left = ptr->right = NULL;
			n++;
		}
		else if (val < ptr->data)
			insertR(ptr->left, val);
		else if (val > ptr->data)
			insertR(ptr->right, val);
		else
			throw("Duplicate Values are not Allowed in BST");
	}
	bool eraseR(bnode<T>*& ptr, const T& val)
	{
		if (ptr == NULL)
			return false;
		else if (val < ptr->data)
			return eraseR(ptr->left, val);
		else if (val > ptr->data)
			return eraseR(ptr->right, val);
		else
		{
			removeNode(ptr);
			return true;
		}
	}
	T pred(bnode<T>* ptr)
	{
		bnode<T>* temp;
		temp = ptr;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		return temp->data;
	}
	void removeNode(bnode<T>*& ptr)
	{
		// leaf node
		if (ptr->left == NULL && ptr->right == NULL)
		{
			delete ptr;
			ptr = NULL;
			n--;
		}
		// node with only left child
		else if (ptr->right == NULL)
		{
			bnode<T>* temp;
			temp = ptr;
			ptr = ptr->left;
			delete temp;
			n--;
		}
		// node with only right child
		else if (ptr->left == NULL)
		{
			bnode<T>* temp;
			temp = ptr;
			ptr = ptr->right;
			delete temp;
			n--;
		}
		// node with two children
		else
		{
			T pred_val = pred(ptr->left);
			ptr->data = pred_val;
			eraseR(ptr->left, pred_val);
		}
	}
	void copy_tree(bnode<T>*& dest,const bnode<T>& src)
	{
		if (src = NULL)
		{
			dest = NULL;
		}
		else
		{
			dest = new bnode<T>;
			dest->data = src->data;
			copy_tree(dest->left, src->left);
			copy_tree(dest->right, src->right);
		}
	}
public:
	BST()
	{
		root = NULL;
		n = 0;
	}
	~BST()
	{
		clear();
	}
	void operator=(const BST<T> &src)
	{
		if (root!=NULL)
		{
			clear();
		}
		copy_tree(root,src.root);
	}
	void clear()
	{
		// T.C O(nlog(n))
		while (root != NULL)
		{
			erase(root->data);
		}
	}
	void insert(const T& val)
	{
		insertR(root,val);
		//bnode<T>* temp, * parent, * ptr;
		//temp = new bnode<T>;
		//temp->data = val;
		//temp->left = temp->right = NULL;
		//n++;
		//// check if tree is empty
		//if (root == NULL)
		//{
		//	root = temp;
		//}
		//else
		//{
		//	ptr = root;
		//	while (ptr != NULL)
		//	{
		//		parent = ptr;
		//		if (val < ptr->data)
		//			ptr = ptr->left;
		//		else if (val > ptr->data)
		//			ptr = ptr->right;
		//		else
		//		{
		//			n--;
		//			delete temp;
		//			throw("Duplicate Values are not Inserted in BST");
		//		}
		//	}
		//}
		//if (val < parent->data)
		//{
		//	parent->left = temp;
		//}
		//else
		//{
		//	parent->right = temp;
		//}
	}
	bool find(T& val)
	{
		bnode<T>* temp;
		temp = root;
		while (temp != NULL)
		{
			if (val < temp->data)
				temp = temp->left;
			else if (val > temp->data)
				temp = temp->right;
			else
			{
				val = temp->data;
				return true;
			}
		}
		return false;
	}
	int  size() const
	{
		return n;
	}
	bool findR(const bnode<T>* ptr, T& val)
	{
		if (ptr == NULL)
			return false;
		if (val == ptr->data)
		{
			val = ptr->data;
			return true;
		}
		else if (val < ptr->data)
			findR(ptr->left, val);
		else
			findR(ptr->right, val);
	}
	bool erase(const T& val)
	{
		return eraseR(root, val);
	}
	bool update(const T& old_val, const T& new_val)
	{
		if (erase(old_val))
		{
			insert(new_val);
		}
	}
	// Traversal Functions
	void in_order(bnode<T>* ptr)
	{
		if (ptr != NULL)
		{
			in_order(ptr->left);
			in_queue.push((ptr->data));
			in_order(ptr->right);
		}
	}
	void pre_order(bnode<T>* ptr)
	{
		if (ptr != NULL)
		{
			pre_queue.push((ptr->data));
			pre_order(ptr->left);
			pre_order(ptr->right);
		}
	}
	void post_order(bnode<T>* ptr)
	{
		if (ptr != NULL)
		{
			post_order(ptr->left);
			post_order(ptr->right);
			post_queue.push((ptr->data));
		}
	}
	void level_order(bnode<T>* ptr)
	{
		queue<bnode<T>*> tempQ;
		if (root != NULL)
			tempQ.push(root);
		while (!tempQ.empty())
		{
			bnode<T>* ptr;
			ptr = tempQ.front();
			tempQ.pop();
			level_queue.push(ptr->data);
			if (ptr->left!=NULL)
				tempQ.push(ptr->left); 
			if (ptr->right != NULL)
				tempQ.push(ptr->right);
		}
	}
	void reset(Traversal_Types trav = IN_ORDER)
	{
		switch (trav)
		{

		case IN_ORDER:
		{
			while (!in_queue.empty())
				in_queue.pop();
			in_order(root);
			break;
		}
		case PRE_ORDER:
		{
			while (!pre_queue.empty())
				pre_queue.pop();
			pre_order(root);
			break;
		}
		case POST_ORDER:
		{
			while (!post_queue.empty())
				post_queue.pop();
			post_order(root);
			break;
		}
		case LEVEL_ORDER:
		{
			while (!level_queue.empty())
				level_queue.pop();
			level_order(root);
			break;
		}

		}

	}
	T get_next(Traversal_Types trav = IN_ORDER)
	{
		switch (trav)
		{

		case IN_ORDER:
		{
				T val;
				val = in_queue.front();
				in_queue.pop();
				return val;
				break;
			}
		case PRE_ORDER:
		{
				T val;
				val = pre_queue.front();
				pre_queue.pop();
				return val;
				break;
			}
		case POST_ORDER:
	    {
				T val;
				val = post_queue.front();
				post_queue.pop();
				return val;
				break;
			}
		case LEVEL_ORDER:
		{
			T val;
			val = level_queue.front();
			level_queue.pop();
			return val;
			break;
		}	
				
		}
	}
	bool is_last(Traversal_Types trav = IN_ORDER) const
	{
		switch (trav)
		{
		case IN_ORDER:
		{
			return in_queue.empty();
			break;
		}
		case PRE_ORDER:
		{
			return pre_queue.empty();
			break;
		}
		case POST_ORDER:
		{
			return post_queue.empty();
			break;
		}
		case LEVEL_ORDER:
		{
			return level_queue.empty();
			break;
		}
		}
	}
};
