/*
 * Main.cpp
 *
 *  Created on: March 13, 2019
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *  Lab 3 File 1, Book Class
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Book.hpp"

void stars(); //asterisks function declaration

int main(){

	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	Book a("Alex","Jones","Book",2006,arr);

	int arr2[] = {5,5,5,10,6,8,7,6,7,10};
	Book b("Billy","Bob","Book 2",2007,arr2);

	int arr3[] = {1,1,1,0,2,3,2,2,2,1};
	Book c("Marie","Anne","Book 3",1998,arr3); //creating 5 instances of class book on the stack

	int arr4[] = {0,0,0,0,0,0,0,0,0,0};
	Book d("Miles","Gumshoe","Book 4 ",2000,arr4);

	int arr5[] = {7,8,8,9,9,10,10,5,9,9};
	Book e("New","Guy","Book 5",2012,arr5);

	Book arr6[] = {a,b,c,d,e}; //array of 5 books

	Book best = arr6[0]; //holds the highest rated book
	for (int i = 1; i<5; i++){ //Compares books based off rating
		if (arr6[i] > best){
			best = arr6[i];
		}
	}
	best.info(); //prints out information of best
	stars();

	int arr7[] = {1,3,5,7,9,10,9,7,5,3};
	Book* f = new Book("Mr.","Heap","Book 6",2021,arr7); //creates a book on the heap
	f->info(); //prints out information of f
	delete f;
	stars();

	int arr8[] = {5,5,5,5,5,5,5,5,5,5};
	Book g = Book("Mr.","Average","Book 7",2016, arr8); //creates a book on the heap

	int arr9[] = {10,10,10,10,10,10,10,9,10,10};
	Book h = Book("Almost","Perfect","Book 8",2020, arr9); //creates a book on the heap

	Book arr10[] = {g,h};

	Book* arr11 = new Book [2]; //creates an array of 2 books on the heap

	arr11 = arr10; //puts 2 books into heap array

	arr11[0].info();
	cout<<endl;
	arr11[1].info();
	stars();


	return 0;
} //main

void stars(){ //asterisks function definition
	cout<<"**********************************************************"<<endl;
} //stars
