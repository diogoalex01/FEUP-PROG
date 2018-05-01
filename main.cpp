#include "dictionary.h"
#include "Board.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//variables
	string thesaurusFile, //file that contains the dictionary
		   //wordFile; //file that will store the processed word list
		   position, //position of the word
		   word; //word to insert
	int rows, columns, option;

	//INTERFACE
	//-----------------------------------------------------------------

	cout << "CROSSWORDS PUZZLE CREATOR" << endl
		<< "=========================" << endl << endl
		<< "Position (RCD / CTRL-Z = STOP)" << endl
		<< " -RCD stands for Row, Column and Direction" << endl << endl
		<< "-------------------------" << endl
		<< "OPTIONS:" << endl
		<< " 1 -  Create Puzzle" << endl
		<< " 2 - Resume Puzzle" << endl
		<< " 0 - Exit" << endl << endl
		<< "Option? ";

	cin >> option;

	cout << endl
		 << "-------------------------" << endl
		 << "CREATE PUZZLE" << endl
		 << "-------------------------" << endl;

	//-----------------------------------------------------------------
	//END of INTERFACE

	cout << "Thesaurus file name? ";
	cin >> thesaurusFile;

	//vector with the valid words from the thesaurus
	Dictionary dict(thesaurusFile);

	cout << "Board size (rows, columns)? ";
	cin >> rows >> columns;

	//OPTION 1
	//-----------------------------------------------------------------
	Board brd(rows, columns);
	brd.make();
	brd.show();

	cout << "Position ( RCD / CTRL-Z = stop ) ? ";
	cin >> position;
	//+3 letras, erro
	//ordem MmV

	cout << endl;

	cout << "Word ( - = remove / ? = help ) ? ";
	cin >> word;
	
	//checks whether the chosen word is valid
	if (!dict.isValid(word))
	{
		cerr << "Invalid word. Try again!" << endl << endl;
		exit(1);
	}
	else
	{
		brd.insert(position, word);
		cout << endl;
		brd.show();
	}

	//-----------------------------------------------------------------
	//END of OPTION 1

	return 0;
}

/*
cwcreator
main.cpp
Extraction of a word list from a synonym dictionary

@author Diogo & Mafalda
@version 1.0 29/04/2018
*/