/*
 * Book.hpp
 *
 *  Created on: March 13, 2019
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *  Lab 3 File 1, Book Class
 */
class Book{

	string fName;
	string lName;
	string bName;
	int pYear = 0;
	int *rating = new int[10];

	public:

	Book(string first, string last, string book, int year); //constructor

	Book(string first, string last, string book, int year, int arr[10]); //overloaded constructor

	Book(); //empty constructor for problem 3

	double avgRating(); //averaging method declaration

	void Rating(); //print rating method declaration

	void info(); //book information method declaration

	bool operator > (Book b); //overloading operator <

	~Book(); //destructor
	};
