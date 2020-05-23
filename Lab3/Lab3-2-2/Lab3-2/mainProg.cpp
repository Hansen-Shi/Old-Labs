/*
 * Main.cpp
 *
 *  Created on: March 13, 2019
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *  Lab 3 File 2, SNode and SLL
 */
#include <iostream>
using namespace std;
#include "SLL.hpp"

int main() {
	int r[10] = {9,8,4,5,11,10,3,6,8,2};
	string s[10] = {"really good!","loved it","mediocre", "okay, not great","best book ever!"
, "awesome!","boring","not bad","definitely worth reading", "terrible!"};
	SLL *list = new SLL();
	for (int i = 0; i < 10; i++) {
		list->insertInOrder(r[i],s[i]);
		list->printSLL();
	}
	cout << "Ave: "<< list->getAve() << endl;
	cout << "Popping " << list->pop() << endl;
	list->printSLL();
	cout << "Popping " << list->pop() << endl;
	list->printSLL();
	delete list;

	return 0;
}
