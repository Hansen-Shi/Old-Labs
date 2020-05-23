/*
 * TreePuzzle.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: Debra
 */

#include "treePuzzle.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
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
	else if (k ==1){
		runMine2();
	}
}
treePuzzle::treePuzzle(string fname,int k) {
	tree = new BSTY();
	readFile2(fname,k);
	cout << "*******************************"<<endl<<"INORDER " << endl;
	tree->printTreeIO();
	cout <<endl << "*******************************FIND" << endl;
	tree->find("pichiciego");
	tree->find("falanouc");
	tree->find("blauwbok");
	tree->find("dibatag");
	tree->find("gharial");
	tree->find("duarf");
	tree->find("kinkajou");
	tree->find("zyzzyva");
	tree->find("tucutucu");
	tree->find("tabanid");
	tree->find("solenodon");
	tree->find("axolotl");
}
void treePuzzle::readFile2(string fname, int size) {
	ifstream file(fname.c_str());
	string word;
	string def;
	int ct = 0;
	while (!file.eof() && ct < size) {
		file >> word;
		cout << word << endl;
		getline(file,def);
		def = def.substr(2);
		tree->insertit(word);

		cout << def << endl;
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


