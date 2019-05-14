/*************************************************************************
 * Program Name: QueueNode.hpp
 * Author: Brittany Dunn
 * Date: May 20 2018
 * Description: This is the header file for the struct QueueNode
 *************************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

struct QueueNode
{
	int val;
	QueueNode *next;
	QueueNode *prev;
	QueueNode(int, QueueNode*, QueueNode*);
};

#endif
