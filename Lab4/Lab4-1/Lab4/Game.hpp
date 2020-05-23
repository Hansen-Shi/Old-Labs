/*
 * Game.hpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Debra
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "BSTY.hpp"
#include "LL.hpp"

class Game {
	BSTY *dict;
	int numletters;
	char *currletters;
	int numright;
	int totalwords;
	LL wordlist;
public:
	Game();
	Game(string infile);
	void startGame();
	void readTreeFromFile (string dictfile);
	char * getLetters(int x);
	void getWords();
	bool checkWLetters(string s);
	void checkWordsForScore();
};

#endif /* GAME_HPP_ */
