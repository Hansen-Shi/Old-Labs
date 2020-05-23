
 /* LL.hpp
 *
 *
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *
 */
#ifndef LL_HPP_
#define LL_HPP_

#include "NodeL.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class LL {
	friend class Game;
	NodeL *first;
	NodeL *last;
	int size;

public:

	LL();
	void printList();
	void push(string c);
	void addFirst(string c);





};

#endif /* LL_HPP_*/
