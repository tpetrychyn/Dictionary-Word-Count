#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

#include "dictionary.h"

using namespace std;

int main() {
	ifstream inData;
	inData.open("textFile.txt");
	if (!inData.is_open()) {
		cout << "Indata not found. Terminating." << endl;
		return 0;
	}
	dictionary dict;
	word word;
	
	dict.ResetP();
	dict.Iterate();

	while (inData >> word.letters) {
		int found = word.letters.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
		if (found == std::string::npos)
		{
			dict.InsertSorted(word.letters.substr(0, found));
			dict.Iterate();
		}
	}
	inData.close();

	//First print, sorted with duplicates
	dict.ResetP();
	dict.Iterate();
	while (dict.IsPSet()) {
		cout << "(" << dict.Read().letters << "," << dict.Read().count << ") ";
		dict.Iterate();
	}
	cout << endl << endl << endl;

	//Remove duplicates
	dict.ResetP();
	dict.Iterate();
	while (dict.IsPSet()) {
		while (dict.Read().count > 1) {
			dict.DeleteSorted();
		}
		dict.Iterate();
	}

	//Second print, sorted no duplicates
	dict.ResetP();
	dict.Iterate();
	while (dict.IsPSet()) {
		cout << "(" << dict.Read().letters << "," << dict.Read().count << ") ";
		dict.Iterate();
	}
	cout << endl;

	return 0;
}
