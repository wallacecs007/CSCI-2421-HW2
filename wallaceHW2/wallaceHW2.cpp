#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "ArrayBag.h"
//#include "ArrayBag.cpp"

using namespace std;

int main()
{

	ifstream myFile;
	myFile.open("setInput.txt");
	string tempHold;
	ItemType stringHold;

	ArrayBag bag1;
	ArrayBag bag2;

	getline(myFile, tempHold);
	//Used this to makesure getline was reading in correctly
	//cout << tempHold;

	/*
	===================================================================
	I couldn't find a way to seperate the lines in the file into individual
	items by spaces so I found this on stackoverflow on google.
	It helped me to come up with a solutions to divide the strings once
	I read them in using getline.

	https://stackoverflow.com/questions/29441675/splitting-strings-separately-by-line-and-by-blank-space-using-getline
	===================================================================
	*/
	stringstream ss1;
	ss1.str(tempHold);

	while (ss1 >> stringHold)
	{
		bag1.add(stringHold);
		//Used this to test if ss was splitting the string properly
		//cout << stringHold << endl;
	}

	stringstream ss2;
	getline(myFile, tempHold);
	//Used this to test to make sure it was reading in the second line
	//cout << tempHold << endl;
	ss2.str(tempHold);

	while (ss2 >> stringHold)
	{
		bag2.add(stringHold);
	}

	cout << "ArrayBag Number One:" << endl;
	cout << bag1 << endl << endl;
	cout << "ArrayBag Number Two:" << endl;
	cout << bag2 << endl << endl;

	cout << "Calling addition between arrayBags: " << endl;
	ArrayBag addition = bag1 + bag2;
	cout << addition << endl << endl;

	cout << "Calling subtraction between arrayBags: " << endl;
	ArrayBag subtraction = bag1 - bag2;
	cout << subtraction << endl;

}


