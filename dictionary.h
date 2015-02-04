#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include <iostream>
#include <string>

using namespace std;

class dictionary; //To use friend class in our word class

class word {
public:
	string letters;
	int count;
	word();

	friend class dictionary;
};

class dictionary {
private:
	word *wordList;
	int p;
	int length;
public:
	//
	//	dictionary
	//	dictionary contstructor
	//	creates a new word array of size 1000, sets p to 0
	//
	dictionary();
	
	//dictionary deconstructor
	~dictionary();

	// sets p to point to the next element in the list
	// always call ResetP prior to the initial call to Iterate
	// always call IsPSet after each call to Iterate
	void Iterate(); 

	// sets p to -1
	void ResetP();

	// checks whether p points to an element in the list
	bool IsPSet();

	// returns the value of the element pointed to by p
	// p must be set prior to calling Read
	// always call IsPSet prior to calling Read
	word Read();

	// inserts a new element into the list in sorted order
	// always call IsFull prior to calling InsertSorted
	// p will point to where the new element should be inserted
	// moves all elements to the right of p one element to the right to make space for the new element
	// sets p
	void InsertSorted(string wordToAdd);

	// deletes element pointed to by p
	// p must be set prior to calling DeleteSorted
	// always call IsPSet prior to calling DeleteSorted
	// all elements following the one pointed to by p are moved one element to the left
	// sets p
	void DeleteSorted();
};

#endif