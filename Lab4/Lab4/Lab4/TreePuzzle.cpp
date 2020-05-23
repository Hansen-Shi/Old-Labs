
#include "treePuzzle.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

treePuzzle::treePuzzle(int x, string sarr[],int k) {
	tree = new BSTY();
	for (int i = 0; i < x; i++) {
		tree->insertit(sarr[i]);
	}
	if (k == 0) {
		runMine1(true);
	}
	cout << endl<<"*******************************"<<endl<<"PREORDER " << endl;
	tree->printTreePre();
	cout << "*******************************"<<endl<<"INORDER " << endl;
	tree->printTreeIO();
	cout << "*******************************"<<endl<<"POSTORDER " << endl;
	tree->printTreePost();
	cout << endl;

	if (k == 0) {
		runMine1(false);
	}
	else {
		runMine2();
	}
}
void treePuzzle::runMine1(bool flag) {
	if (flag) {
		cout << "Mine " << endl;
		tree->myPrint();
	}
	else {
		cout << endl << "PART TWO " << endl;
		tree->find("ocelot");
		tree->find("perforated");
		tree->find("sibylic");
		tree->find("go");
	}
}
void treePuzzle::runMine2() {
	cout << "Mine2 " << endl;
	cout << endl << "EXTRA CREDIT " << endl;
	tree->remove("apple");
	cout << "AFTER REMOVE:" << endl;
	tree->printTreeIO();
	cout <<endl << "NOW REMOVING " ;
	tree->remove("noon");
	cout << "AFTER REMOVE:" << endl;
	tree->printTreeIO();
	cout <<endl << "NOW REMOVING " ;
	tree->remove("jack");
	cout << "AFTER REMOVE:" << endl;
	tree->printTreeIO();
	cout <<endl << "NOW REMOVING " ;
	tree->remove("xray");
	cout << "AFTER REMOVE:" << endl;
	tree->printTreeIO();
	cout << endl << "MineEC: " << endl;
	tree->myPrintEC();
}
treePuzzle::~treePuzzle() {
	delete tree;
}


