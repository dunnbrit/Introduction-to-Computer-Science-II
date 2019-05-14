/*************************************************************************
 * Program Name: outputLetters.cpp
 * Author: Brittany Dunn
 * Date: April 15 2018
 * Description: This is the implementation file for the function 
 * output_letters.
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "outputLetters.hpp"

using std::cin;
using std::cout;
using std::ofstream;
using std::endl;
using std::string;

void output_letters(ofstream& file, int* letters)
{
	char lowerletter = 97;
	int frequency;

	//output letter frequency to file
	for(int i = 0; i < 26; ++i)
	{
		frequency = letters[i];
		file << lowerletter;
		file << ": ";
		file << frequency;
 		file << endl;
		++lowerletter;
	}
	
	//Close file
	file.close();
}
