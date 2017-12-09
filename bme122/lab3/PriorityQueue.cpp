#include "PriorityQueue.hpp"
#include<iostream>
#include<string> 

using namespace std;
typedef int DataType;

 // Constructor initializes heap_ to an array of size "capacity + 1", so that
  // there are at most "capacity" elements in the heap.
  PriorityQueue::PriorityQueue(unsigned int capacity)
  {
  	capacity_=capacity+1;
  	size_=0;
	heap_= new DataType [capacity]; 
  }
  // Destructor.
  PriorityQueue::~PriorityQueue()
  {
  	delete heap_;
  	heap_=NULL;
  }
  
  // Enqueues "val" into the priority queue. Returns false if failed, true
  // otherwise. Assume no duplicate entries will be entered.
  bool PriorityQueue::enqueue(DataType val)
  {
  	if(size_==capacity_-1) return false;
  	else
  	{
  		//insert node to bottom-right-most
		heap_[size_+1]=val;
  		size_++;
  		
  		//if parent has a smaller value than node, switch
		unsigned int i = size_;
		while(heap_[i]>heap_[(i/2)]&&i>=0)
		{
			DataType temp = heap_[i];
			heap_[i]=heap_[(i/2)];
			heap_[(i/2)]=temp;
			
			i=(i/2);
		}
		return true;
  		
    }
  }
  
  // Dequeues the top element with the maximum value (priority) and rearranges
  // the resulting heap. Returns false if failed, true otherwise.
  bool PriorityQueue::dequeue()
  {
  	
  		if(empty())
		return false;
	if(size_ == 1)
	{
		size_--;
		return true;
	}
	heap_[1] = heap_[size_];
	size_--;
	int current = 1;
	DataType val = heap_[1];
	while(current*2 <= size_ && (heap_[current*2] > heap_[current] ||
				 heap_[current*2+1] > heap_[current] ))
	{
		if(current*2+1 <= size_)
		{
			if(heap_[current*2] < heap_[current*2+1])
			{
				heap_[current] = heap_[current*2+1];
				heap_[current*2+1] = val;
				current = current*2+1;
			}
			else
			{
			heap_[current] = heap_[current*2];
			heap_[current*2] = val;
			current = current*2;
			}
		}
		else
		{
			heap_[current] = heap_[current*2];
			heap_[current*2] = val;
			current = current*2;
		}
	}
	return true;	
  }
  
  // Returns the max element of the priority queue, but does not remove it.
  DataType PriorityQueue:: max() const
  {
  	
  	return heap_[1];	
  }
  
  // Returns true if the priority queue is empty; false otherwise.
  bool PriorityQueue::empty() const
  {
  	if(size_==0) return true;
  	else return false;
  }
  
  // Returns true if the priority queue is full; false otherwise.
  bool PriorityQueue::full() const
  {
  	if(size_==capacity_-1) return true;
  	else return false;
  }
  
  // Returns the number of elements in the priority queue.
  unsigned int PriorityQueue::size() const
  {
  	return size_;
  }
  
  // Print the contents of the priority queue.
  void PriorityQueue::print() const
  {
  	for(int i=1;i++;i<=size_)
  	{
  		cout<<heap_[i]<<endl;
	}
  }
  
  


