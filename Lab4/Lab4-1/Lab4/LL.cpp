/*
 * LL.cpp
 *
 *
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *
 */
#include "LL.hpp"

LL::LL(){
	first = NULL;
	last = NULL;
	size = 0;

} //constructor

void LL::printList(){

	NodeL *tmp = first;
	while (tmp != NULL){
		tmp->printNode();
		tmp = tmp->next;
	} //while
	cout<<endl;
} //printSLL

void LL::push(string c){ //adds a node to the end of the list, if list is empty calls addFirst
	if (first == NULL){
		addFirst(c);
	} //if
	else {
		NodeL *n = new NodeL(c);
		last->next = n;
		last = n;
	} //else
	size ++;
} //push

void LL::addFirst(string c){ //adds a node to an empty list

	first = new NodeL(c);
	last = first;
	size ++;
} //addFirst








