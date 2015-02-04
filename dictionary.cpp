#include "dictionary.h"
#include <stdlib.h>
#include <locale>

dictionary::dictionary() {
	wordList = new word[1000];
	p = -1;
	length = 0;
}

dictionary::~dictionary() {
	delete[] wordList; //Clean up our wordList array
}

void dictionary::Iterate() {
	p++;
	return;
}

void dictionary::ResetP() {
	p = -1;
	return;
}

word dictionary::Read() {
	return wordList[p];
}

void dictionary::DeleteSorted() {
	if (!IsPSet())
		return;

	int q = p;
	p++;
	while (p < length) {
		wordList[p - 1] = wordList[p];
		p++;
	}
	length--;
	p = q;
	return;
}

void dictionary::InsertSorted(string wordToAdd) {
	//catch duplicates
	p = 0;
	while (p < length) {
		if (wordToAdd == wordList[p].letters){
			wordList[p].count++;
			return;
		}
		p++;
	}

	p = 0;
	while (p < length && wordToAdd > wordList[p].letters) 
		p++;
	int q = length;
	while (q > p) {
		wordList[q].letters = wordList[q - 1].letters;
		q--;
	}
	wordList[p].letters = wordToAdd;
	length++;
	return;
}

bool dictionary::IsPSet() {
	if (p < 0 || p > length - 1)
		return false;
	return true;
}

word::word() {
	letters = "";
	count = 1;
}