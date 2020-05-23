
//Lab 4a with extra credit
//Lauren Olson
//Hansen Shi, Matthew Novosel

#include "BSTY.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
	root = NULL;
}

// You write:  insert a new node with data x (a string) into the
// binary search tree
// This method should return true if a new node is inserted and
// false if the data x is already in the tree
// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.
// Note: Make sure you make the new node point to its parent!!!
// Note2: after you've inserted a new node, you should call the
// adjustHeights method that will update the heights of all the
// ancestors of the node that was just inserted.
bool BSTY:: insertit(string x ) {

	bool added = false;
	bool exists = false;

	NodeT* n = new NodeT(x);
	if (root == NULL){
		root = n;
	}
	else{
		NodeT* curr = root;

		while (!added){
			if (n->data < curr->data){
				if (curr->left != NULL){
					curr = curr->left;
				}
				else{
					curr->left = n;
					n->parent = curr;
					adjustHeights(n);

					added = true;
				}
			}
			else if (n->data > curr->data){
				if (curr->right != NULL){
					curr = curr->right;
				}
				else{
					curr->right = n;
					n->parent = curr;
					adjustHeights(n);

					added = true;
				}
			}
			else{
				exists = true;
			}
		}
	}
	if (exists == true){
		return false;
	}
	else{
		return true;
	}
}

// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have
// this working now.  It should be called whenever you change the height of a
// a particular node.  So, for instance, when a new node is inserted as a leaf,
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of
// the height of the left child and the height of the right child, plus 1).  If
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.
void BSTY::adjustHeights(NodeT *n) {

	NodeT* curr = n;
	bool run = true;


	while (run){

		if (curr->parent == NULL){ //checks for root
					break;
				}

		if (curr->left == NULL && curr->right == NULL){ //check if its the lowest leaf
			curr->height = 1;
		}

		if (curr->data < curr->parent->data){
			if (curr->parent->right != NULL){
				if (curr->parent->right->height >= curr->height){
					break;
				}
			}																	//checking if anything changes when adding n
		}
		else if (curr->data > curr->parent->data){
			if (curr->parent->left != NULL){
				if (curr->parent->left->height >= curr->height){
					break;
				}
			}
		}
		curr->parent->height = curr->height + 1; //changes parent size

		curr = curr->parent; //interates through parents

	}
}


void BSTY::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is
// traversed in order
void BSTY::printTreeIO(NodeT *n) {

	if (n->left != NULL){
		printTreeIO(n->left);
	}

	cout<< "|" << n->data << ", " << n->height << "|" <<endl;

	if (n->right != NULL){
		printTreeIO(n->right);
	}
}

void BSTY::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {

	NodeT *curr = n;
	cout<< "|" << curr->data << ", " << n->height << "| " <<endl;

	if (curr->left != NULL){
		printTreePre(curr->left);
	}

	if (curr-> right != NULL){
		printTreePre(curr->right);
	}
}

void BSTY::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {

	if (n->left != NULL){
		printTreePost(n->left);
	}

	if (n->right != NULL){
		printTreePost(n->right);
	}

	cout<< "|" << n->data << ", " << n->height << "| " <<endl;
}
void BSTY::myPrint() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrint(root);
		cout << endl;
	}
}
void BSTY::myPrint(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrint(n->left);
		cout << n->data.length()-1;
		if (mine) {
			cout <<".";
			mine = false;
		}
		myPrint(n->right);
	}
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.
NodeT *BSTY::find(string x) {

	bool run = true;
	bool exists = false;
	NodeT* n = root;

	if (root->data == x){
		root->printNode();
		return root;
	}
	else{
		while (run){
			if (x < n->data){
				if (n->left == NULL){
					run = false;
				}
				else{
					n = n->left;
				}
			}
			else if (x > n->data){
				if (n->right == NULL){
					run = false;
				}
				else{
					n = n->right;
				}
			}
			else{
				run = false;
				exists = true;
			}
		}
		if (exists){
			n->printNode();
			return n;
		}
		else{
			cout<< x << " can't be found" <<endl;
			return NULL;
		}
	}
}


/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
/* search tree.
/*
/* When removing a node, there are 3 conditions:
/* 1: when the node being removed has no children, in which case the node is deleted,
/* the node's parent is set to NULL, and the node's parent's height is adjusted (if
/* necessary) and heights on up are adjusted.
/* 2: when the node being removed has one child, in which case the node's parent points
/* to the node's child, and the node's child points to the node's parent, and the node
/* is deleted (and the height of the parent on up as necessary is adjusted)
/* 3: when the node has 2 children, in which case the left-most child of the node's
/* right child replaces the node.
/* A couple of notes about this one: you are replacing a node with a node that is lower
/* down in the tree.  That means that you are, in essence, removing the node from that
/* lower position and moving it up to the old node's location.  Thus the replacing node
/* must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after
/* the replacing node is removed from its old location but before it is inserted into its
/* new location.  Equally, the replacing node's height must be adjusted to be the larger of
/* its two children's heights before you adjust heights above that.
/*****************************************************************************************/
/* remove(): takes as input a string, uses the find method to find the node in the tree that
/* holds that string, and then calls replace1, replace2, or replace3 depending on what type
/* of replacing should be done.  It adjusts the heights, deletes teh node, and returns
/* true if the removal was successful.
*/
bool BSTY::remove(string s) {

	NodeT* n = find(s);
	if (n->left == NULL && n->right == NULL){
		remove1(n);
	}
	else if (n->left == NULL && n->right != NULL){
		remove2(n);
	}
	else if (n->left != NULL && n->right == NULL){
		remove2(n);
	}
	else if (n->left != NULL && n->right != NULL){
		remove3(n);
	}

	NodeT* check = find(s);

	if (check == NULL){
		return true;
	}
	else{
		return false;
	}
}


/* remove1(): called when the node to be removed has no children. Takes as input the
/* node to be removed, and sets the parent of the node to point to NULL.
/* helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
/* Make sure you check to whether n is the root or not.
*/
void BSTY::remove1(NodeT *n) {

	NodeT* dad = NULL;

	if (n->parent == NULL){
		delete root;
		cout<<"You killed the tree :c"<<endl;
	}

	else if (n->height == 1){
			dad = n->parent;
			if (dad->left == n){
				dad->left = NULL;
			}
			else{
				dad->right = NULL;
			}
			delete n;
		}
		adjustHeights(dad);
	}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
/* the node to be removed and bypasses it by making the parent point to the node's
/* one child, and makes the node's one child point to the node's parent.
/* This one needs a bunch of checking - you need to see if the node is the parent's
/* left or right child, and you need to see if the node's child is its left or its
/* right child.
/* Also, make sure you check that if the node to be removed is the root, then the
/* one child becomes the root.
*/
void BSTY::remove2(NodeT *n) {

	NodeT* holder;

	if (n == root){
		if (n->left == NULL){
			holder = n->right;
			delete n;
			root = holder;
		}
		else{
			holder = n->left;
			delete n;
			root = holder;
		}
		adjustHeights(holder);
	}

	if (n->parent->left == n){
		if (n->left == NULL){
			holder = n->right;
		}
		else{
			holder = n->left;
		}
		delete n;
		n->parent->left = holder;
	}
	else{
		if (n->left == NULL){
			holder = n->right;
		}
		else{
			holder = n->left;
		}
		delete n;
		n->parent->right = holder;
	}
	adjustHeights(holder);

}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
/* node to be removed.  The node to replace the node to be removed should be the
/* left-most descendent of the node's right child.  That way the binary search tree
/* properties are guaranteed to be maintained.
/* When replacing the node to be removed with the replacing node, the replacing node
/* is, in essence, being removed from its place in the tree, and thus replace1 or
/* replace2 methods should be used.
/* The new node's parent must be set to the removed node's parent, the removed node's
/* parent must point to the new node, the new node's left child must point to the
/* removed node's left child (and the child must point to the new node as a parent),
/* and the same for teh right child.
/* Remember to take into account that the node being removed might be the root.
*/
void BSTY::remove3(NodeT *n) {

	NodeT* holder;
	NodeT* holder2;

	if (n == root){
		holder = n->left;
		holder2 = n->right;
		delete n;
		root = holder2;
		holder->left = holder;
	}
	else{
		holder = n->right;
		while (holder->left != NULL){
			holder = holder->left;
		}

		holder->parent = n->parent;
		n->parent->right = holder;
		holder->left = n->left;
		n->left->parent = holder;
		holder->right = n->right;
		n->right->parent = holder;

		adjustHeights(holder);



	}
}

/* findMin(): takes as input a node, and finds the left-most descendant of its
/* right child.  The left-most descendent is returned.
*/
NodeT *BSTY::findMin(NodeT *n) {

	NodeT* holder = n->right;
	while (holder->left != NULL){
		holder = holder->left;
	}
	return holder;
}

void BSTY::myPrintEC() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrintEC(root);
		cout << endl;
	}
}
void BSTY::myPrintEC(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrintEC(n->left);
		cout << alpha[n->data.length()-2];
		myPrintEC(n->right);
	}
}


/************************************************************************/

