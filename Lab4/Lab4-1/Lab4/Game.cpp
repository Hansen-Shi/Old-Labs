/*
 * Game.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Debra
 */

#include <iostream>
#include "BSTY.hpp"
#include "Game.hpp"
#include "LL.hpp"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

Game::Game(){
	readTreeFromFile("usanoswears.txt");

	numletters = 0;
	numright = 0;
	totalwords = 0;
}

Game::Game(string filen){
	readTreeFromFile(filen);

	numletters = 0;
	numright = 0;
	totalwords = 0;
	//wordlist = new LL();
}

void Game::startGame() {
	cout << "How many letters do you want?" << endl;
	cin >> numletters;
	currletters = getLetters(numletters);
	cout << "Your letters are: " << endl;
	for (int i = 0; i < numletters; i++) {
		cout << currletters[i] << " ";
	}
	cout << endl;
	cout << "Start generating words: " << endl;
	getWords();
	checkWordsForScore();
	int score = numright * 3 - (totalwords-numright) * 6;
	cout << "Number of valid words: " << numright << " Invalid words: " << (totalwords - numright) << endl;
	cout << "Final Score is: "  << score << endl;
}

void Game::getWords() {
	string s;
	cin >> s;
	while (s != "-1") {
		wordlist.push(s);
		cin >> s;
		cout << endl;
	}
	wordlist.printList();
}

char * Game::getLetters(int x) {
	char vowel[5] = {'a','e','i','o','u'};
	char conso[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
	char *curr = new char[x];
 	int v = rand() %(x-2) + 1;

	for (int i = 0; i < v; i++) {
		int y = rand() %5;
		curr[i] = vowel[y];
	}
	for (int i = v; i < x; i++) {
		int y = rand() %21;
		curr[i] = conso[y];
	}
	for (int i = 0; i < x; i++) {
		cout << curr[i] << endl;
	}
	return curr;
}
bool Game::checkWLetters(string s) {
	char tempchar[numletters];
	for (int i = 0; i < numletters; i++) {
		tempchar[i] = currletters[i];
	}
	for (int i = 0; i < s.size(); i++) {
		int j = 0;
		while ((j < numletters) && (s[i] != tempchar[j] )) {
			j++;
		}
		if (j == numletters) {
			return false;
		}
		tempchar[j] = '1';
	}
	if (dict->find(s)== NULL){
		return false;
	}
	return true;
}
void Game:: checkWordsForScore() {
	NodeL *tmp = wordlist.first;
	while (tmp != NULL) {
		if (checkWLetters(tmp->word) ) {
			cout << tmp->word << " is okay " << endl;

			numright++;
		}
		else {
			cout << tmp->word << " is invalid " << endl;
		}
		totalwords++;
		tmp = tmp->next;
	}
}

void Game::readTreeFromFile (string dictfile) {
	dict = new BSTY();
	ifstream file(dictfile.c_str());
	string word;
	while (!file.eof()) {
		file >> word;
		if (!file.eof()) {
			dict->insertit(word);
		}
	}
	return;
}

	//=



