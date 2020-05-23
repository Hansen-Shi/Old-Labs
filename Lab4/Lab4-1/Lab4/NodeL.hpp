/*
 *NodeL.hpp
 *Lauren Olson
 *Lab 4
 *Hansen Shi, Matt Novosel
 */
#ifndef NODEL_HPP_
#define NODEL_HPP_
#include <iostream>
using namespace std;

class NodeL {
	friend class LL;
	friend class Game;
	string word;
	NodeL *next;

public:

	NodeL(string c);


	void printNode();

};

#endif /* SNODE_HPP_ */
