/* hashNode.cpp
 * Author: Hansen Shi
 * TA: Lauren Olson
 */

#include "hashNode.hpp"
#include <time.h>

hashNode::hashNode(){

	keyword = " ";
	valuesSize = 0;
	currSize = 0;
	values = NULL;
}

hashNode::hashNode(string s){
	keyword = s;
	valuesSize = 100;
	currSize = 0;
	values = new string[valuesSize];
}

hashNode::hashNode(string s, string v){
	keyword = s;
	valuesSize = 100;
	currSize = 1;
	values = new string[valuesSize];
	values[0] = v;
}

void hashNode::addValue(string v){
	values[currSize + 1] = v;
	currSize++;

	if (currSize >= valuesSize * .7 ){
		cout<<"Size increase |^|"<<endl;
		dblArray();
	}
}

void hashNode::dblArray(){
	string *arr = new string[valuesSize *= 2];
	for (int i = 0; i < currSize; i++){
		arr[i] = values[i];
	}
	values = arr;
}

string hashNode::getRandValue(){
	string n = "";

	if (currSize != 0){
		n = values[rand()%currSize];
	}
	return n;

}

void hashNode::printNode() {
	cout << keyword << " : ";
	if (currSize == 0)
		cout << "NULL" << endl;
	else {
		for (int i = 0; i < currSize; i++)
			cout << values[i] << ", ";
		cout << endl;
	}
}
