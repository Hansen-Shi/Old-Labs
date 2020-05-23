/*
 * Book.cpp
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

Book::Book(string first, string last, string book, int year){ //constructor sets array to 0

	for (int i = 0; i<10; i++){
		rating[i] = 0;
	}
}

Book::Book(string first, string last, string book, int year, int* arr){ //overloaded constructor initializes values

	fName = first;
	lName = last;
	bName = book;
	pYear = year;
	rating = arr;

}

Book::Book(){ //empty constructor for problem 3

}

double Book::avgRating(){ //function sums values in the array of ratings, returns the average rating as a double

	double sum = 0;

	for (int i = 0; i<10; i++){
		sum += rating[i];
	} //for
	return (sum/10);
} //avgRating()

void Book::Rating(){ //function calls avgRating(), prints out the average rating, or "no ratings yet" when applicable

	double r = avgRating(); //function call

	if (r != 0){
		cout<<"Rating: "<<r<<"/10"<<endl;
	} //if
	else{
		cout<<"(no ratings yet)"<<endl;
	} //else
} //Rating()

void Book::info(){ //method prints out the author's first name, last name, book title, year published, and rating for a book

	cout<<"Author: "<<fName<<","<<lName<<endl;
	cout<<"Title: "<<bName<<","<<endl;
	cout<<"Published: "<<pYear<<endl;
	Rating();
} //info()

bool Book::operator > (Book b){ //overloaded operator determines which book has a higher rating, returns a boolean

	double b1 = avgRating();
	double b2 = b.avgRating();
	return (b1 > b2);
}

Book::~Book(){ //destructor, deletes the array on the heap
	delete []rating;
}


