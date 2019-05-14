/*************************************************************************
 * Program Name: Queue.cpp
 * Author: Brittany Dunn
 * Date: May 20 2018
 * Description: This is the implementation file for the class Queue
 *************************************************************************/

#include "Queue.hpp"
#include "QueueNode.hpp"
#include <iostream>

using std::cout;
using std::endl;

//This is the constructor for Queue
Queue::Queue()
{
	head = nullptr;
}

//This is the destructor for Queue
Queue::~Queue()
{	
	if(head == nullptr)
	{
		//do nothing
	}
	else
	{
		QueueNode *nodePtr = head->next;
		while(nodePtr != head)
		{
			QueueNode *deleteIt = nodePtr;
			nodePtr = nodePtr->next;
			delete deleteIt;
		}
		delete nodePtr;
		head = nullptr;
	}
}

//This function returns true if queue is empty
bool Queue::isEmpty()
{
	return head == nullptr;
}

//This function prints the queue
void Queue::printQueue()
{
	//If list is empty
	if(isEmpty())
	{
		cout << "\nYour queue is currently empty." <<endl;
	}
	//Print list until the end
	else
	{
		cout << "Your queue is: ";
		QueueNode *nodePtr = head;
		do
		{
			cout << nodePtr->val << " ";
			nodePtr = nodePtr->next;
		}
		while(nodePtr != head);
		cout << " " <<endl;
	} 
}

//This function adds a new queue node to the back of the queue
void Queue::addBack(int val)
{
	int value = val; 

	//If list is empty set prev and next to head ptr
	if(isEmpty())
	{
		head = new QueueNode(value,head,head);
		head->prev = head;
		head->next = head;
	}
	//If list is not empty make a new node and add it to the end of queue
	else
	{
		//If list has only 1 node
		if(head == head->prev && head == head->next)
		{
			head->next = new QueueNode(value,head,head);
			head->prev = head->next;
		}
		//If list has more than 1 node
		else
		{
			QueueNode *nodePtr = head->prev;
			head->prev = new QueueNode(value,nodePtr,head);
			nodePtr->next = head->prev;
		}
	}
}

//This function returns the value of the first node
int Queue::getFront()
{
	return head->val;
}

//This function deletes the first node of the queue
void Queue::removeFront()
{
	//If list is empty print warning
	if(isEmpty())
	{
		cout << "\nQueue is empty. Cannot proceed." <<endl;
	}
	//If not delete first node
	else
	{
		//If list has only 1 node
		if(head == head->prev && head == head->next)
		{
			delete head;
			head = nullptr;
		}
		//If list has more than one node
		else
		{
			QueueNode *nodePtr = head;
			head = nodePtr->next;
			head->prev = nodePtr->prev;
			(nodePtr->prev)->next = head;
			delete nodePtr;
		}	
	}
}
