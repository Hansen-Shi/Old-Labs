/*
 * Main.cpp
 *
 *  Created on: Feb 15, 2019
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *  Lab 1 File
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

void stars(); //Problem 2 function declaration

bool isPrime(int x); //Problem 3 function declaration

void sumThreeHundred(); //Problem 4 function declaration

int exceed(); //Problem 5 function declaration

void mTable(int x); //Problem 6 function declaration

void loopTable(); //Problem 7 function declaration

int colCon(); //Problem 8 function declaration

void leapYear(); //Problem 9 function declaration

void bigX(int x); //Problem 10 function declaration

void colFinal(int x, int y); //Problem 11 function declaration

int main(){
	cout<<"Problem 1:"<<endl;
	cout<<"Hello World!"<<endl;
	stars();

	cout<<"Problem 2:"<<endl;
	stars();

	cout<<"Problem 3:"<<endl;
	cout<<isPrime(64)<<endl; //Expected false or 0
	cout<<isPrime(100)<<endl; //Expected false or 0
	cout<<isPrime(13)<<endl; //Expected true or 1
	stars();

	cout<<"Problem 4:"<<endl;
	sumThreeHundred();
	stars();

	cout<<"Problem 5:"<<endl;
	cout<<exceed()<<endl;
	stars();

	cout<<"Problem 6:"<<endl;
	mTable(12); //Expected {12,24,36,48,[...], 144}
	mTable(9); //Expected {9,18,27,36,[...], 108}
	mTable(2); //Expected {2,4,6,8,[...], 24}
	stars();

	cout<<"Problem 7:"<<endl;
	loopTable();
	stars();

	cout<<"Problem 8:"<<endl;
	colCon();
	stars();

	cout<<"Problem 9:"<<endl;
	leapYear();
	stars();

	cout<<"Problem 10:"<<endl;
	bigX(5); //Expected: x shape with 2 lines of 9 asterisks
	bigX(3); //Expected: x shape with 2 lines of 5 asterisks
	bigX(7); //Expected: x shape with 2 lines of 13 asterisks
	stars();

	cout<<"Problem 11:"<<endl;
	colFinal(1,4); //Expected: 2, Collatz Conjecture is still working. 3, Collatz Conjecture is still working.
	colFinal(2,5); //Expected: 3, Collatz Conjecture is still working. 4, Collatz Conjecture is still working.
	colFinal(1,5); //Expected: 2, Collatz Conjecture is still working. 3, Collatz Conjecture is still working. 4, Collatz Conjecture is still working.
	stars();

	return 0;
} //Main

//Function has no input parameters and returns nothing, prints out a line of asterisks
void stars(){ //Problem 2 function definition

	cout<<"**********************************************************"<<endl;
} //stars

/*Function takes in a single input parameter, an integer, and returns a boolean
 * Indicates whether the integer is prime or not
 */
bool isPrime(int x){ //Problem 3 function definition

	int num = 2;

	while (num < (x-1)){

		if (x%num == 0){

			return false;
		} //If

		num++;
	} //While

	return true;
} //isPrime

/*Function has no input parameters and returns nothing
 * Sums integers from 1-300
 * Prints out current value in intervals of 20
 */
void sumThreeHundred(){ //Problem 4 function definition

	int sum = 0;

	for (int i = 1; i <= 300; i++){

		sum += i;

		if (i%20 == 0){
			cout<<sum<<endl;
		} //If
	} //For
} //sumThreeHundred

/*Function has no input parameters and returns an integer
 * Returns the # of terms (1,2,3,...) needed to exceed 100,000
 * Must be a While Loop
 */
int exceed(){ //Problem 5 function definition

	int i = 0;
	int sum = 0;
	int terms = 1; //Starts at 1 to account for 0 as a term

	while (sum < 100000){

		i++;
		sum += i;
		terms++;
	} //While

	return terms;
} //exceed

/*Function takes in a single input parameter, an integer, and returns nothing
 * Prints out a multiplication table, 1-12 with the input integer
 */
void mTable(int x){ //Problem 6 function definition

	for (int i = 1; i <= 12; i++){

		cout<<x*i<<endl;
	} //For
} //mTable

/*Function has no input parameters and returns nothing
 *Prints out multiplication tables for integers 1-12
 *Must use mTable from problem 6
 */
void loopTable(){ //Problem 7 function definition

	for (int i = 1; i <= 12; i++){

		mTable(i);
	} //For
} //loopTable

/*Function has no input parameters and returns an integer
 *Asks for a, user-input, positive, integer
 *Applies the Collatz Conjecture to the user input
 *Returns and prints the number of iterations of the Collatz Conjecture
 */
int colCon(){ //Problem 8 function definition

	int x;
	int i = 0;

	cout<<"Please enter a positive integer value: ";
	cin >> x;

	while (x > 1){

		if (x%2 == 0){
			x /= 2;
		}
		else{
			x = (x*3)+1;
		} //If

		i++;
	} //While

	cout<<i<<endl;
	return i;
} //colCon

/*Function has no input parameters and returns nothing
 *Prints every leap year from 2017 to 2417
 */
void leapYear(){ //Problem 9 function definition

	for (int i = 2017; i <= 2417; i++){

		if (i%4 == 0){
			if (i%100 == 0){
				if (i%400 == 0){
					cout<<i<<endl;
				}
			}
			else{
				cout<<i<<endl;
			}
		} //Nested ifs to account for rules for a leap year
	} //For
} //leapYear

/*Function takes in an integer input and returns nothing
 *Makes a X with asterisks, size determined by the input
 *Accepts even inputs, but rounds them up to be odd
 */
void bigX(int x){ //Problem 10 function definition

	int s = (2*x)-1; //Size of the asterisk diagonals

	if (x%2 == 0){ //Rounds up even inputs
		x ++;
	} //If

	for (int i = 0; i<s; i++){
		for (int j = 0; j<s; j++){ //Nested for loops, for columns and rows
			if ((i == j) or (i+j == s - 1)){
				cout<<"*";
			}
			else{
				cout<<" ";
			} //If
		} //For
		cout<<endl;
	} //For
} //bigX

/*Function takes in two integer inputs and returns nothing
 *Prints out every number between the integer inputs
 *Assumes that first input is smaller than second input
 *Prints out whether the Collatz Conjecture works on every number in between the integer inputs
 */
void colFinal(int x, int y){ //Problem 11 function definition

	int j;
	while (x+1 <= y-1){
		x++;
		cout<<x<<endl;
		j = x;

		while (j > 1){ //Nested while loop of Collatz Conjecture
			if (j%2 == 0){
				j /= 2;
			}
			else if (j%2 != 0){
				j = (j*3)+1;
			} //If
		} //While
		cout<<"Collatz Conjecture is still working."<<endl;
	} //While
} //colFinal



