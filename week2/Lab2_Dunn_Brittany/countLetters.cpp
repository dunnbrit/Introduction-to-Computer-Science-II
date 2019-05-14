/*************************************************************************
 * Program Name: countLetters.cpp
 * Author: Brittany Dunn
 * Date: April 15 2018
 * Description: This is the implementation file for the function 
 * count_letters.
 *************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "countLetters.hpp"
#include "outputLetters.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::ofstream;

//This function reads the user file. While it is reading it checks for one
//letter in the alphabet and records each time it is used in the array. It
//loops 26 times for each letter
void count_letters(ifstream& file, int* counter) 
{
//	do
//	{
	//varible holds last character read
	char lastChar = ' ';
	//varible to count letter
	int frequency = 0;
	//varible to read file characters
	char ch;
	//varibles to go through each letter 
	char upperletter = 65;
	char lowerletter = 97;
	//Intialize array to 0
	for(int i = 0; i < 26; ++i)
	{
		counter[i] = 0;
	}

	//Loops once for each letter 
	for(int i = 0; i < 26; ++i)
	{
		//Loop until EOF or paragraph reached
		do
		{
			file.get(ch);
			//If the letter is found add one to counter
			if(ch == upperletter || ch == lowerletter)
			{
				++frequency;
			}
		}
		while(ch != '\n' || !EOF );
		
		//When new papragraph or EOF reached
		
		//Store frequency in array
		counter[i] = frequency;

		//prepare varibles for next letter
		++upperletter;
		++lowerletter;
		frequency = 0;
		//On last loop do not return to beginning of file
		if(i != 25)
		{
			file.clear();	
			file.seekg(0L, std::ios::beg);
		}
	}
	
	string tempFile;
	ofstream outputFile;

	//Prompt user for output file name
	cout << "Please enter the name of the file you would";
	cout << " like the frequencies of letters written." << endl;
	cin >> tempFile;
	
	//Open outpuyt file
	outputFile.open(tempFile, std::ios::out);

	//if error opening file
	if(outputFile.fail())
	{
		cout << "Error opening file.";
	}

	// call output letter function to add letter frequency to file
	else
	{
		output_letters(outputFile, counter);
	}

	//Loop until EOF is reached (all paragraphs read)
//	}while(!file.eof());

	//Close file
	file.close();
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
