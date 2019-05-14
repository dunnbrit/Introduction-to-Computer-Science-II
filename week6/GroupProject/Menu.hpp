/***********************************************************************************
** Program name: Menu.hpp
** Author: Samantha Schrock
** Date: 4/8/18
** Description: This is the class specification file for the menu class. It represents
a menu and has functions to set a menu title, add an option to the menu, and build the menu.
****************************************************************************************/


#ifndef MENU_HPP
#define MENU_HPP


#include <string>
#include <vector>
#include <iostream>


class Menu
{
	private:
		std::vector<std::string> menuOptions;
		std::string menuTitle;

	public:
		Menu();
		Menu(std::string);
		void setTitle(std::string);
		void addOptions(std::string);
		int buildMenu();
};
#endif