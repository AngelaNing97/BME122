#include "DynamicStack.hpp"
#include <iostream>
#include <string>
using namespace std;
typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	capacity_=16;
	items_=new StackItem[capacity_];
	size_=0;
	init_capacity_=16;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	capacity_=capacity;
	items_=new StackItem[capacity_];
	size_=0;
	init_capacity_=capacity;
}

DynamicStack::~DynamicStack()
{
	delete items_;
	items_=NULL;
}

bool DynamicStack::empty() const
{
	if(size_==0) return true;
	else return false; 
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if(size_<capacity_)
	{
		items_[size_]=value;
		size_++;
	}
	else
	{
		StackItem* temp = new StackItem [capacity_*2];
		capacity_=capacity_*2;
		for(int i=0;i<size_;i++)
		{
			temp[i]=items_[i];
		}
		delete items_;
		items_=temp;
		temp=NULL;
		items_[size_]=value;
		size_++;
	}
}

StackItem DynamicStack::pop()
{
	if(empty()==true) return EMPTY_STACK;
	else
	{	
		size_--;
		StackItem popItem = items_[size_];
		if(size_<= capacity_/4 && capacity_/2>=init_capacity_)
		{
			capacity_=capacity_/2;
			StackItem* temp = new StackItem [capacity_];
			for(int i=0;i<size_;i++)
			{
				temp[i]=items_[i];
			}
			delete items_;
			items_=temp;
			temp=NULL;	
		}
		return popItem;	
	}	
}

StackItem DynamicStack::peek() const
{
	if(empty()==true) return EMPTY_STACK;
	else
	{
		return items_[size_-1];
	}
}

void DynamicStack::print() const
{
	for(int i=size_-1; i>=0;i--)
	{
		cout<<items_[i]<<endl;
	}
}
