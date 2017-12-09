#include "SequentialList.hpp"
#include <iostream>
#include <string>

using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
	data_=new DataType[cap];
	capacity_=cap;
	size_=0;
}

SequentialList::~SequentialList()
{
	delete data_;
	data_= NULL;
}

bool SequentialList::empty() const
{
	if(size_==0) return true;
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
	if(size_==capacity_) return true;
	else return false;
}

void SequentialList::print() const
{
	for(int i=0;i<size_;i++)
	{
		cout<< data_[i]+" ";
	}
}

bool SequentialList::insert_front(DataType val)
{
	if(full()==false)
	{

			for(int i=size_;i>0;i--)
			{
				data_[i]=data_[i-1];
			}
			data_[0]=val;
			size_=size_+1;
			return true;

		
	}
	else return false;
}

bool SequentialList::remove_front()
{
	if(size_==0) return false;
	else if (size_==1)
	{
		size_=0;
		return true;
	}
	else{
		for(int i=0;i<size_-1;i++)
		{
			data_[i+1]=data_[i];
		}
		size_=size_-1;
		return true;
	}	
}

bool SequentialList::insert_back(DataType val)
{
	if(size_<capacity_)
	{
		data_[size_]=val;
		size_=size_+1;
		return true;
	}
	else return false;
}

bool SequentialList::remove_back()
{
	if(empty()==false) 
	{
		size_=size_-1;
		return true;
	}
	else return false;	
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if(full()==true) return false;
	else if(index>=capacity_) return false;
	else
	{
		for(int i=size_;i>index;i--)
		{
			data_[i]=data_[i-1];
		}
		data_[index]=val;
		size_++;
		return true;
	}
	
}

bool SequentialList::remove(unsigned int index)
{
	if(index>=size_) return false;
	else
	{
		for(int i=index;i<size_-1;i++)
		{
			data_[i]=data_[i+1];
		}
		size_=size_-1;
		return true;
	}
}

unsigned int SequentialList::search(DataType val) const
{
	for(int i=0;i<size_;i++)
	{
		if(data_[i]==val) return i; // multiple result??
	}
	return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if(index>=size_) return data_[size_-1];
	else return data_[index];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(index>=size_) return false;
	else
	{
		data_[index]=val;
		return true;
	}
}
