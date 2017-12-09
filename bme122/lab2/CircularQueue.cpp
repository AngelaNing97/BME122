#include<string>
#include<iostream>
#include "CircularQueue.hpp"
using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem [16];
	size_= 0;
	head_=0;
	tail_=0;
	capacity_=16; 
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	capacity_=capacity;
	size_=0;
	items_=new QueueItem [capacity];
	head_=0;
	tail_=0;
}

CircularQueue::~CircularQueue()
{
	delete items_;
	items_=NULL;
}

bool CircularQueue::empty() const
{  
	if(size_==0) return true;
	else return false;  
}

bool CircularQueue::full() const
{
	if(size_==capacity_) return true;
	else return false;
}

int CircularQueue::size() const
{  
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if(full()==true) return false;
	else
	{
		tail_=tail_ % capacity_;
		items_[tail_]=value;
		size_++;
		tail_ = (tail_+1) % capacity_;
		return true;
	}
}

QueueItem CircularQueue::dequeue()
{
	if(empty()==true) return EMPTY_QUEUE;
	else
	{
		int temp = head_;
		head_=(head_+1) % capacity_; 
		size_--;
		return items_[temp];
	}
}

QueueItem CircularQueue::peek() const
{
	if(empty()==true) return EMPTY_QUEUE;
	else return items_[head_];
}

void CircularQueue::print() const
{
	for(int i=0;i<size_;i++)
	{
		cout<<items_[i]<<endl;
	}
}
