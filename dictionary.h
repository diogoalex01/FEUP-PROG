#ifndef dictionary_h
#define dictionary_h

#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Dictionary
{
public:
	Dictionary(string thesaurusFile); //constructor of the vector with the valid words from the thesaurus
	bool isValid(string word, map<string, vector<string> > validWords); //validates the word inputed by the user by checking if it's in the vector containin the valid words
	map<string, vector<string> > validWords; //vector that will hold the valid header words from the thesaurus and its synonyms
	string caps(string word);

private:

	vector<string> synonyms;
};
#endif