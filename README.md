# store_word_list
Book practice project from Problem Solving With C++ Chapter 11. Project 5 (combined with 4).

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	complex-number-representation-using-class.cpp (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 11. Project 5 (combined with 4).
Defining a class to store lists of words.   

Written using Microsoft Visual Studio. 

## Algorithm

- Copy class StringVar from Display 11.11 & 11.12, and include:
			- Member function CopyPiece which returns specified substring;
			- Member function oneChar which returns a single char;
			- Member function setChar which changes a single char in the string;
			- Overloaded == operator
			- Overloaded + which performs string concatenation
			- Overloaded >> which reads one word
		- Create class Text which consists of a dynamic array of StringVar objects and include:
		 - Enforce no spaces within a StringVar element
		 - Member functions corresponding to all member functions of StringVar
		 - A default constructor, and a constructor which takes a const char a[] argument (ends program with error if this argument contains newline char)
		 - Member function inputLine which stores each blank-separated word separately in a StringVar object
		 - Overloaded >> which fills only one element of the dynamic array
	#Additional Note:
    Nothing about a max size for the dynamic array, so it must be able to expand forever. Therefore, program it like a vector and increase the max size by multiples each time rather than recreate the array each time one entry is added
	
    

## Requirements
No requirements or modules needed for running this program. 
