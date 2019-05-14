/*************************************************************************
 * Program Name: Die.hpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Description: This is the header file for the class Die.
 *************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <string>

class Die
{
	protected:
		int N;
	
	public:
		Die();
		Die(int);
		virtual int rollDie();
};
#endif 
