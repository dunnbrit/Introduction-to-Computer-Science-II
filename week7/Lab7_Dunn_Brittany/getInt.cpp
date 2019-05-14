/*************************************************************************
 * Program Name: getInt.cpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the implementation file for the getInt and
 * validInput and inputInvalid functions.
 *************************************************************************/
#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

//This fucntion accepts a string as a parameter and checks all characters
//are integers. If all integer then the value is returned. If not then
//"invalid" is returned
string inputValid(string temp)
{
	string input = temp;
	//Check each character of string to see if it is a digit	
	for(int i= 0; i < input.length(); ++i)
	{
		if(!isdigit(input[i]))
		{
			//If not a digit change input to "invalid"
			input = "invalid";
	
		}
	}
				
	return input;
}

//This function converts the string recieved to an integer and returns
//the integer.
int getInt(string input)
{
	//Convert string to an integer
	int output = std::stoi(input,nullptr,0);
	// return  integer
	return output;
}

// This function prompts the user to enter a new string because the previous
// string was found to be invalid. The new string is sent to inputValid to
// check it only has digits.Either "invalid" or the user entered string 
// is returned
string inputInvalid()	 
{
	string temp;
	
	cout << "Input invalid. Please enter an integer. \n";
	cin >> temp;
	temp = inputValid(temp);
	return temp;
}
