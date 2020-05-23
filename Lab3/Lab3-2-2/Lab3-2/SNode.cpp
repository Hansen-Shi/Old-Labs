/*
 * SNode.cpp
 *
 *  Created on: March 13, 2019
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *  Lab 3 File 2, SNode and SLL
 */
#include "SNode.hpp"

SNode::SNode(){

	cout<<"Please rate the book: "<<endl;
	int r;
	cin>>r;
	rating = r;

	cout<<"Any comments? Leave them here: "<<endl;
	string c;
	cin>>c;
	comments = c;

	next = NULL;
}

SNode::SNode(int r, string c){

	rating = r;
	comments = c;
	next = NULL;
}

void SNode::printNode(){
	cout<<"Rating: "<<rating<<"Comments: "<<comments<<endl;
}

SNode::~SNode(){

}
