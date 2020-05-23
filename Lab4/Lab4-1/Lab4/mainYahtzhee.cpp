/*
 * mainYahtzee.cpp
 *
 *  Created on: Apr 11, 2019
 *  Lab 4
 *  Lauren Olson
 *  Hansen Shi, Matt Novosel
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Game.hpp"
#include "TreePuzzle.hpp"

using namespace std;
int main() {
	 //PART 1
	string sarr[10] = {"run","tuxedo","ocelot","vast","bark","punctilios","hello","is","sibylic","go"};
	treePuzzle(10,sarr,0);

	//PART 2
	cout << endl << "A LOT OF LEFT ROTATIONS " << endl;
	string sarr3[10] = {"a","b","c","d","e","f","g","h","i","j"};
	treePuzzle(10,sarr3,3);

	cout << endl << endl << "A LOT OF RIGHT ROTATIONS " << endl;
	string sarr4[10] = {"j","i","h","g","f","e","d","c","b","a"};
	treePuzzle(10,sarr4,3);

	cout << endl << endl << "A LOT OF RIGHT-LEFT ROTATIONS " << endl;
	string sarr5[10] = {"g","j","i","c","f","h","e","d","a","b"};
	treePuzzle(10,sarr5,3);

	cout << endl << endl << "A LOT OF LEFT-RIGHT ROTATIONS " << endl;
	string sarr6[10] = {"a","p","d","g","f","e","k","j","v","b"};
	treePuzzle(10,sarr6,3);

	//FOR EXTRA CREDIT
	string sarr2[13] = {"xray","jack","superthriller","fa","noon","muddle","kindergartener","zoogeographical","window","dandelion","youthsploitation","byte","apple"};
	treePuzzle(13,sarr2 ,1);

//Part 3: WordHub
    //srand(time(NULL));
	//Game *game = new Game();
	//game->startGame();

}
