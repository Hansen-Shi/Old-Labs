/*
 * NodeL.cpp
 *
 *
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *
 */
#include "NodeL.hpp"



NodeL::NodeL(string c){

	word = c;

	next = NULL;
}

void NodeL::printNode(){
	cout<<word<<endl;
}


