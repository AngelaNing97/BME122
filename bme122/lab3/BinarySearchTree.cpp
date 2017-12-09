#include "BinarySearchTree.hpp"
#include <iostream>
#include <string>

using namespace std;
typedef int DataType;

// Implement the functions here.
BinarySearchTree :: BinarySearchTree()
{
	root_ = NULL;
	size_ = 0;
}

//destructor
BinarySearchTree :: ~BinarySearchTree()
{
	if(root_ == NULL) return;
	int end = 1; 
	int temp = 0; 
	Node* list[size_+1];
	list[0] = root_; 
	
	while(size_> end)
	{
		if(list[temp]->left != NULL)
		{
			list[end] = list[temp]->left;
			end++;
		}
		if(list[temp]->right != NULL)
		{
			list[end] = list[temp]->right;
			end++;
		}
		temp++;
	} 
	
	for(int i = 0; i < end; i++)
	{
		delete list[i];
	}
}

BinarySearchTree :: Node :: Node(DataType newval)
{
	val = newval;  // value of the node
    left=NULL;    // left child
    right=NULL; 
}

// Inserts value "val" into the tree. Returns false if failed (i.e., "val"
// already exists in the tree), and true otherwise.
bool BinarySearchTree::insert(DataType val)
{
	Node* temp = new Node(val);
	if(size_==0)
	{
		root_ = temp;
		size_++;
		return true;
	}
	else
	{
	Node* visitor = root_;
	while(visitor!=NULL)
	{ 
		if(visitor->val == val)
		{
			return false;
		}
		else if(val<visitor->val)
		{
			if(visitor->left==NULL) 
			{
				visitor->left = temp;
				size_++;
				return true;
			}
			else visitor= visitor->left;
		}
		else if(val>visitor->val)
		{
			if(visitor->right ==NULL) 
			{
				visitor->right = temp;
				size_++;
				return true;
			}
			else visitor = visitor->right;
		}
	}
	//temp=NULL;
}
	
} 


// Removes the node with value "val" from the tree. Returns true if successful,
// false otherwise.
bool BinarySearchTree::remove(DataType val) //recursive
{
	if(size_==0) return false;
	if(exists(val)==false) return false; 
	if(size_ ==1)
	{
		delete root_;
		root_=NULL;
		size_--;
		return true;
	}
	
	Node* visitor = root_;
	Node* prev=visitor;
	while(visitor!=NULL && visitor->val!=val)
	{
		if(visitor->val <val)
		{
			prev = visitor;
			visitor=visitor->right;
		}
		else if(visitor->val > val)
		{
			prev = visitor;
			visitor = visitor->left;
		}
	}
	
	if(visitor->left==NULL&& visitor->right==NULL)
	{
		size_--;

		if(val> prev->val) prev->right=NULL;
		else prev->left=NULL;
		delete visitor;
		visitor=NULL;
		return true;
	}
	else if(visitor->left==NULL && visitor->right!=NULL)
	{
		size_--;
		if(val> prev->val) prev->right = visitor->right;
		else prev->left = visitor ->right; 
		delete visitor;
		visitor=NULL;
		return true;
	}
	else if(visitor->left!=NULL && visitor->right ==NULL)
	{
		size_--;
		if(val> prev->val) prev->right = visitor->left;
		else prev->left = visitor ->left; 
		delete (visitor);
		visitor=NULL;
		return true;
	}
	else if(visitor->left!=NULL && visitor->right !=NULL)
	{
		Node* subtreeMax=visitor->left;
		Node* prev=visitor;
		while(subtreeMax->right!= NULL)
		{
			prev =subtreeMax;
			subtreeMax=subtreeMax->right; 
		}
		DataType temp = subtreeMax->val;
		subtreeMax->val = visitor->val;
		visitor->val = temp;
		//print();
		
		if(subtreeMax->left==NULL && subtreeMax->right ==NULL)
		{
			
			size_--;
	
			if(prev->val==visitor->val)prev->left=NULL;
			else prev->right=NULL;
			delete subtreeMax;
			subtreeMax=NULL;

			return true;
		}

		else if(subtreeMax->left!=NULL && subtreeMax->right ==NULL)
		{
			size_--;
			 prev->right = subtreeMax->left;
			delete (subtreeMax);
			subtreeMax=NULL;
			return true;
		}
		
	}
		
}

// Returns true if a node with value "val" exists in the tree; false otherwise.
bool BinarySearchTree::exists(DataType val) const
{
	if(size_==0) return false;
	else if(size_==1)
	{
		if(root_->val ==val) return true;
		else return false;
	}
	else 
	{
		Node* temp = root_;
		while(temp!=NULL)
		{
			if(temp->val==val) return true;
			else if(temp->val > val)
			{
				if(temp->left !=NULL)
				{
					temp=temp->left;
				} 
				else
				{
					temp==NULL;
					return false;
				}
			}
			else if(temp->val < val)
			{
				if(temp->right!=NULL)
				{
					temp=temp->right;
				}
				else
				{
					temp==NULL;
					return false;
				}
			}
		}
		return false;
	}
}

// Returns the minimum value of the tree. You can assume that this function
// will never be called on an empty tree.
DataType BinarySearchTree::min() const
{
	Node* visitor = root_;
	while(visitor->left!=NULL)
	{
		visitor=visitor->left;
	}
	return visitor->val;
}

// Returns the maximum value of the tree. You can assume that this function
// will never be called on an empty tree.
DataType BinarySearchTree::max() const
{
	Node* visitor = root_;
	while(visitor->right!=NULL)
	{
		visitor=visitor->right;
	}
	return visitor->val;
}

// Returns the number of nodes in the tree.
unsigned int BinarySearchTree::size() const
{
	return size_;
}

// You can print the tree in which ever manner you like, however methods such
// as in-order, level-order, etc. might be the most useful for debugging
// purposes.
void BinarySearchTree::print() const
{
	Node* queue[size_];
	queue[0]=root_;
	int count=1;
	int index=0;
	int temp = 0;
	while(count!=0)
	{
		cout<<queue[temp]->val<<endl;
		
		if(queue[temp]->left!=NULL)
		{
			index=index+1;
			queue[index]=queue[temp]->left;
			count++;
		}
		if(queue[temp]->left!=NULL && queue[temp]->right!=NULL)
		{
			index=index+1;
			queue[index]=queue[temp]->right;
			count++;
		}
		if(queue[temp]->left==NULL && queue[temp]->right!=NULL)
		{
			index=index+1;
			queue[index]= queue[temp]->right;
			count ++;
		}
		count--;
		temp++; 
	}
//	delete queue;
//	queue=NULL;

}

// Optional function.
// Recursively get the maximum depth from a given node. Call on root_ first.
// This might be of great value to you in depth().
int BinarySearchTree::getNodeDepth(Node* n) const //recursive
{
	
}
