/*
 * SLL.cpp
 *
 *  Created on: March 13, 2019
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *  Lab 3 File 2, SNode and SLL
 */
#include "SLL.hpp"

SLL::SLL(){ //sets fields first and last to null, and size to 0
	first = NULL;
	last = NULL;
	size = 0;
} //constructor

SLL::~SLL(){ //loops through and deletes the list until first is null, last is set to null, and size is set to 0
	SNode *tmp;
	while (first != NULL){
		tmp = first->next;
		cout<<"deleting "<<first->rating<<","<<first->comments<<endl;
		delete first;
		first = tmp;
	} //while
	last = NULL;
	size = 0;
} //destructor

void SLL::printSLL(){ //loops through the list, calls printNode to print out the data in each node

	SNode *tmp = first;
	while (tmp != NULL){
		tmp->printNode();
		tmp = tmp->next;
	} //while
	cout<<endl;
} //printSLL

void SLL::insertInOrder(int r, string c){ //inserts nodes to form a sorted list

	if (size == 0){
		addFirst(r,c);

	} //else if
	else if (r <= first->rating){
		addAtFront(r,c);

	} //else if
	else if (r >= last->rating){
		push(r,c);

	} //else if
	else{
		size++;
		SNode *s = first;
		SNode *n = new SNode(r,c);
		SNode *tmp = NULL;
		while ( s->next != NULL && r > s->rating){
			tmp = s;
			s = s->next;
		} //while
		tmp->next = n;
		n->next = s;
	} //else
} //insertInOrder

void SLL::push(int r, string c){ //adds a node to the end of the list, if list is empty calls addFirst
	SNode *n = new SNode(r,c);
	if (first == NULL){
		addFirst(r,c);
	} //if
	else {
	last->next = n;
	last = n;
	} //else
	size ++;
} //push

void SLL::addAtFront(int r, string c){ //adds a node to the front of the list

	SNode *n = new SNode(r,c);
	n->next = first;
	first = n;
	size ++;
} //addAtFront


void SLL::addFirst(int r, string c){ //adds a node to an empty list

	first = new SNode(r,c);
	last = first;
	size ++;
} //addFirst

int SLL::pop(){ //removes the last node in the list
	SNode *tmp = first;
		for (int i = 1; i<size-1; i++){
			tmp = tmp->next;
		} //for

		int r = last->rating;
		delete last;
		last = tmp;
		last->next = NULL;
		size --;
		return r;
}//pop

double SLL::getAve(){ //traverses the list and returns the average rating

	SNode *n = first;
	double sum = 0;

	while (n != NULL){
		sum += n->rating;
		n = n->next;
	} //while
	return sum/size;
} //getAve


