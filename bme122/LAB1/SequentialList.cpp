#include "SequentialList.hpp"
#include <iostream>
#include <string>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
	data_ = new DataType[cap]; 
	capacity_ = cap; 
	size_ = 0;
}

SequentialList::~SequentialList()
{
	delete data_;
	data_ = NULL;
}

bool SequentialList::empty() const
{
	if(size_== 0) return true;
	else return false;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	if(size_ == capacity_) return true;
	else return false;
}

void SequentialList::print() const
{
	for(int i = 0; i < size_; i ++)
	{
		cout << data_[i];
	}
}

bool SequentialList::insert_front(DataType val)
{
	if(full() == false)
	{ 	
		for(int i = size_; i > 0; i --)
		{
			data_ [i] = data_ [i-1];
		}
		data_ [0] = val;
		size_ = size_ + 1;
		return true;
	}
}

bool SequentialList::remove_front()
{
	if(empty() == true)return false;
	else{
	
		for(int i = 0 ; i < size_-1; i++)
		{
			data_[i] = data_ [i+1];
		}
		size_ --;
		return true; 
	}	
}

bool SequentialList::insert_back(DataType val)
{
	if(full() == false)
	{
		data_[size_] = val;
		size_ ++;
		return true;	
	} 
	return false; 
}

bool SequentialList::remove_back()
{
	if(empty() == false)
	{
		size_ --; 
		return true;
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if (full() == false && index <= size_)
	{
		for (int i = size_; i > index ; i--)
		{
			data_ [i] = data_[i-1];	
		}
		data_ [index] = val;
		size_++;
		return true;
	}
	return false;
}

bool SequentialList::remove(unsigned int index)
{
	if (index < size_)
	{
		for (int i = index; i < size_ ; i++)
		{
			data_ [i] = data_ [i+1];
		}
		size_--;
		return true;
	}
	return false;
}

unsigned int SequentialList::search(DataType val) const
{
	for(int i = 0; i < size_; i ++)
	{
		if(data_[i] == val) return i;
	}
	return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (index < size_)
	{
		return data_ [index];
	}
	return data_ [size_-1];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if (index < size_)
	{
		data_ [index] = val;
		return true;
	}
	return false;
}
