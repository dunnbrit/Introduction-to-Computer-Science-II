/*************************************************************************
 * Program Name: Queue.hpp
 * Author: Brittany Dunn
 * Date: May 20 2018
 * Description: This is the header file for the class Queue
 *************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"

class Queue
{
	protected:
	QueueNode *head;

	public:
	Queue();
	~Queue();
	bool isEmpty();
	void addBack(int);
	int getFront();
	void removeFront();
	void printQueue();

};

#endif	
