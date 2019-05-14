/*************************************************************************
 * Program Name: QueueNode.hpp
 * Author: Brittany Dunn
 * Date: May 20 2018
 * Description: This is the implementation file for the struct QueueNode
 *************************************************************************/

#include "QueueNode.hpp"
#include <iostream>
//This is the constructor for node
QueueNode::QueueNode(int value, QueueNode* prev1, QueueNode* next1)
{
	val = value;
	prev = prev1;
	next = next1;
}
