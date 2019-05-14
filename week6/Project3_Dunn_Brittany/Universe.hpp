/*************************************************************************
 * Program Name: Universe.hpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is header file for the class Universe
 *************************************************************************/

#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

#include <memory>
#include "Character.hpp"

class Universe
{
	private:
		std::shared_ptr<Character> characterA;
		std::shared_ptr<Character> characterB;		
	public:
		Universe(std::shared_ptr<Character>& a,std::shared_ptr<Character>& b);
		void firstRoundResults();
		void secondRoundResults();
		bool gameOver();
};

#endif 
