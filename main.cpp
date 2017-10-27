/*
Branden Lee
CIS 22B
Fall 2017
Assignment A
Problem A1

Used Microsoft Visual Studio 2017

Prompts user for the size of an array and takes inputs to the array, then displays them back one line at a time.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

/***************************************************
global functions
***************************************************/
void getSize (int& stringNum);
void getSpace (string*& stringArray, int stringNum);
void inputData (string*& stringArray, int stringNum);
void printData (string*& stringArray, int stringNum); 
void destroy (string*& stringArray);

int main ()
{
	int stringNum = 0;
	string* stringArray = NULL;  // pointer to a string, intialize to nothing.
	getSize (stringNum);
	getSpace (stringArray, stringNum);
	inputData (stringArray, stringNum);
	printData (stringArray, stringNum);
	destroy (stringArray);
	//system("pause");
	return 0;
}

/* ******************** getSize ********************
which asks the user how many strings they want
*/
void getSize (int& stringNum)
{
	cout << "How many strings do you want?" << endl;
	cin >> stringNum;
}

/* ******************** getSpace ********************
which gets an array in the heap of the size requested by the user
*/
void getSpace (string*& stringArray, int stringNum)
{
	stringArray = new string[stringNum];
}

/* ******************** inputData ********************
which allows the user to input the strings and stores them in the array
*/
void inputData (string*& stringArray, int stringNum)
{
	cout << "Start inputing strings. Press enter after each line to save the string." << endl;
	std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); //ignore newline

	for (int i = 0; i < stringNum; i++)
	{
		//cout << "Line: " << i << endl;
		getline (cin, stringArray[i]);
	}
}

/* ******************** printData ********************
which prints all the strings, one string per line
*/
void printData (string*& stringArray, int stringNum)
{
	cout << endl << "These are the strings you inputed:" << endl;
	for (int i = 0; i < stringNum; i++)
	{
		cout << stringArray[i] << endl;
	}
}

/* ******************** destroy ********************
which returns all the space to the heap
*/
void destroy (string*& stringArray)
{
	delete[] stringArray;
	cout << endl << "Memory returned to the heap. Goodbye." << endl;
}

/* Execution results
How many strings do you want?
5
Start inputing strings. Press enter after each line to save the string.
Hello this is an exmample.
This is the second line I am inputing.
I like this third line very much.
Do you link the number four?
Line Five! We are finally done...

These are the strings you inputed:
Hello this is an exmample.
This is the second line I am inputing.
I like this third line very much.
Do you link the number four?
Line Five! We are finally done...

Memory returned to the heap. Goodbye.
*/