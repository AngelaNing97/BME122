#include "DoublyLinkedList.hpp"
#include "SequentialList.hpp"
#include <iostream>
#include <string>
using namespace std;


DoublyLinkedList::Node::Node(DataType data)
{
	value=data;
	next=NULL;
	prev=NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_=NULL;
	tail_=NULL;
	size_=0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if(size_==0) return;
	else{
		Node* visitor=head_;
		while(visitor->next!=NULL)
		{
			head_=head_->next;
			head_->prev=NULL;
			delete visitor;
			visitor=head_;
		}
		head_=NULL;
		tail_=NULL;
		delete visitor;
		visitor=NULL;
	}
}

bool DoublyLinkedList::empty() const
{
	if(size_==0) return true;
	else return false;	
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	Node* visitor = head_;
	while(visitor!=NULL)
	{
		cout<<visitor->value;
		visitor=visitor->next;
	}
}

bool DoublyLinkedList::insert_front(DataType value)
{
	Node* a = new Node(value);
	if(size_==0)
	{
		head_=a;
		tail_=a;
		size_++;
		return true;
	}
	else
	{
		head_->prev=a;
		a->next=head_;
		head_=a;
		size_++;
		return true;
	}
	
}

bool DoublyLinkedList::remove_front()
{
	if(size_==0) return false;
	if(size_==1) 
	{
		delete head_;
		head_=NULL;
		tail_=NULL;
		size_=0;
		return true;
	}
	else
	{
		Node* visitor=head_->next;
		visitor->prev=NULL;
		delete head_;
		head_=visitor;
		size_--;
		return true;		 
	}
}

bool DoublyLinkedList::insert_back(DataType value)
{
	Node* newNode= new Node(value);
	if(size_==0)
	{
		head_=newNode;
		tail_=newNode;
		size_++;
		return true;
	}
	else
	{
		newNode->prev=tail_;
		tail_->next=newNode;
		tail_=newNode;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove_back()
{
	if(size_==0)return false;
	if(size_==1)
	{
		delete (head_);
		head_=NULL;
		tail_=NULL;
		size_=0;
		return true;
	}
	else
	{
		Node* visitor = tail_;
		tail_=tail_->prev;
		delete visitor;
		tail_->next=NULL;
		size_--;
		visitor=NULL;
		return true; 
	}
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	Node* a = new Node(value);
	if(index>size_) return false;
	
	else if(size_==0) 
	{
		tail_=a;
		head_=a;
		size_++;
		return true;
	}
	else if(index==size_)
	{
		insert_back(value);
	}
	else if(index ==0)
	{
		insert_front(value);
	}
	else
	{
		Node* visitor = head_;
		for(int i=0; i<index; i++)
		{
			visitor=visitor->next;
		}
		visitor->prev->next=a;
		a->prev=visitor->prev;
		a->next=visitor;
		visitor->prev=a;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if(index==0) remove_front();
	if(index>=size_)return false;
	else if(size_>1 && index<size_-1)
	{
		Node* visitor = head_;
		for(int i=1; i<index;i++)
		{
			visitor=visitor->next;
		}
		Node* visitor2 = visitor->next;
		visitor->next = visitor2->next;
		visitor->next->prev=visitor;
		visitor2->next=NULL;
		visitor2->prev=NULL;
		delete visitor2;
		visitor2=NULL;
		size_--;
		return true;
	}
	else if(index==size_-1) remove_back();
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	if(size_==0) return size_;
	else
	{
		Node* visitor = head_;
		for(int i=0;i<size_;i++)
		{
			if(visitor->value==value) return i;
			visitor=visitor->next;
		}
		return size_;
	}
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if(index>=size_)
	{
		return tail_->value;
	}
	else 
	{
		Node* visitor = head_;
		for(int i=1; i<=index;i++)
		{
			visitor=visitor->next;
		}
		return visitor->value;
	}
	
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if(index>=size_) return false;
	
	else
	{
		Node* visitor = head_;
		for(int i=0; i<index;i++)
		{
			visitor = visitor->next;
		}
		visitor->value = value;
		return true;
	}

}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	Node* visitor = head_;
	for(int i =0; i<index;i++)
	{
		visitor=visitor->next;
	}
	return visitor;
}
bool DoublyLinkedList::full() const
{
	if(size_>=CAPACITY) return true;
}
