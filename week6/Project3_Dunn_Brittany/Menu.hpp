/*************************************************************************
 * Program Name: Menu.hpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the header file for the Menu functions
 *************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <memory>
#include "Character.hpp"

void displayCharacterMenu();
void displayEndMenu();
std::shared_ptr<Character> characterChoice(int);

#endif
