/*
 * SNode.hpp
 *
 *  Created on: March 13, 2019
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *  Lab 3 File 2, SNode and SLL
 */
#ifndef SNODE_HPP_
#define SNODE_HPP_
#include <iostream>
using namespace std;

class SNode {
	friend class SLL;
	int rating;
	string comments; 	// instead of int data, now the data is both the rating
						// and the accompanying comments – think of when you rate
						// a book or a song, and then are asked to share comments
						//about the book. Both are the data in this node.
	SNode *next;

public:

	SNode(); 	// this constructor takes no input. It then asks the user to input a
				// rating, then reads the rating into the rating field, and
				// then asks the user to input their comments, and reads in the
				// comments into the comments field.
	SNode(int r, string c);
				// this constructor takes as input an integer and a string, and
				// initializes the rating field to the integer, and the comment
				// field to the string.
	~SNode();
	void printNode();

};

#endif /* SNODE_HPP_ */
