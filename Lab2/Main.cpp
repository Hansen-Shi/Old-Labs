/*
 * Main.cpp
 *
 *  Created on: Feb 22, 2019
 *  Author: Hansen Shi, Matt Novosel
 *  TA: Lauren Olson
 *  Lab 2 File
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

void stars(); //Prints line of asterisks

void print(); //Problem 1 Function declaration

void cByValue(int x); //Problem 2 function declaration

int ranGen(); //Problem 3 function declaration

void cube(int *x); //Problem 4 function declaration

void alias(int &x); //Problem 5 function declaration

void switcheroo(int *x, int *y); //Problem 6 function declaration

void googCode(char c1, char *c2, char &c3, char *c4); //Problem 7 function declaration

bool swap(int &x, int &y); //Problem 8a function declaration

void loop(); //Problem 8b function declaration

int smallVal(int len, int &x); //Problem 8 function declaration

void flip(int len); //Problem 9 function declaration

void fiftyOne(int len, int r); //Problem 10 function declaration

int* testFunc(); //Problem 11 function declaration

void arrFunc(int arr[], int len); //Problem 12 function declaration

int* heapArr(int *x, int *y, int *z); //Problem 13 function declaration

int* stackArr(int x); //Problem 14 function declaration

void printArr(int arr[], int len); //Problem 15 function declaration

void printDArr(double arr[], int len); //Problem 16 function declaration

int* rArr(int arr[], int *len); //Problem 17 function declaration

int hanningArr(int arr[], int w ); //Problem 18 function declaration

void printPlot(int arr[], int len, int max, int min); //Problem 20 function declaration

int** twoDArr(int *x, int *y); //Problem 21 function declaration

int main(){

	srand(time(NULL)); //Initial seeding for rand()

	cout<<"Problem 1:"<<endl;
	print();
	stars();

	cout<<"Problem 2:"<<endl;
	int a = 1;
	cByValue(a);
	cout<<a<<endl; //This is an example of call by value
	cout<<&a<<endl;
	stars();

	cout<<"Problem 3:"<<endl;
	ranGen();
	stars();

	cout<<"Problem 4:"<<endl;
	int b = 3;
	cout<<b<<endl<<&b<<endl; //This is an example of call by pointer
	cube(&b);
	cout<<b<<endl<<&b<<endl;
	stars();

	cout<<"Problem 5:"<<endl;
	int c = 2;
	cout<<c<<endl<<&c<<endl; //This is an example of call by reference
	alias(c);
	cout<<c<<endl<<&c<<endl;
	stars();

	cout<<"Problem 6:"<<endl;
	int d = 10;
	int e = 20;
	switcheroo(&d, &e);
	cout<<d<<endl<<e<<endl; //Prints 32 and 42
	stars();

	cout<<"Problem 7:"<<endl;
	char f = 'z';
	char g = 'p';
	char h = 'i';
	char i = 'y';
	cout<<f<<h<<g<<g<<i<<endl; //zippy
	googCode(g,&h,f,&i);
	cout<<g<<f<<g<<g<<h<<i<<endl; //pupper
	stars();

	cout<<"Problem 8a:"<<endl;
	int j = 1;
	int k = 4;
	int l = 5;
	int m = 4;
	int n = 5;
	cout<<swap(k,j)<<endl; //Tests when input 1 > input 2, 4 and 1 in this case, returns true
	cout<<k<<endl<<j<<endl; //Results of swap(), 1 and 4 in this case
	cout<<swap(m,l)<<endl; //Tests when input 1 < input 2, 4 and 5 in this case returns false
	cout<<m<<endl<<l<<endl;//Results of swap(), 4 and 5 still
	cout<<swap(l,n)<<endl; //Test when input 1 = input 2, 5 and 5 in this case returns false
	cout<<l<<endl<<n<<endl; //Results of swap(), 5 and 5 still
	stars();

	cout<<"Problem 8b:"<<endl;
	loop(); //Each run should produce 20 random pairs and swap ones applicable
	loop();
	loop();
	stars();

	cout<<"Problem 8:"<<endl;
	int o = 0;
	smallVal(5,o); //Prints an array with 5 elements
	cout<<o<<endl; //Prints the smallest value in the array
	smallVal(7,o); //Prints an array with 7 elements
	cout<<o<<endl; //Prints the smallest value in the array
	smallVal(10,o); //Prints an array with 10 elements
	cout<<o<<endl; //Prints the smallest value in the array
	stars();

	cout<<"Problem 9:"<<endl;
	flip(5); //Prints the original array, then the same array in reverse order
	flip(8);
	flip(3);
	stars();

	cout<<"Problem 10:"<<endl;
	fiftyOne(5, 50); //Prints the generated array, then the same array in numerical order
	fiftyOne(3,25);
	fiftyOne(10,10);
	stars();

	cout<<"Problem 11:"<<endl;
	int *y = testFunc();
	//cout<<*y<<endl<<&y<<endl; //Does this work? No it does not, nothing is printed
	stars();				    //Does this compile? Yes, technically it does compile, giving only a warning. But it bricks everything after it

	cout<<"Problem 12:"<<endl;
	int arr[] = {1,2,3};
	arrFunc(arr,3);
	stars();

	cout<<"Problem 12b:"<<endl;
	int arr2[25];
	for (int i = 0; i<25; i++){
		arr2[i] = rand()% 10 + 1;
	}
	arrFunc(arr2,25);
	stars();

	cout<<"Problem 13:"<<endl;
	int p = 0;
	int q = 0;
	int r = 0;
	int *copy[p];
	*copy = heapArr(&p,&q,&r);
	arrFunc(*copy, p);
	stars();

	cout<<"Problem 14:"<<endl;
	//int s = rand()%25 + 25; //This does not work because the array is local and is deleted when the function ends
	//arrFunc(stackArr(s),s);
	stars();

	cout<<"Problem 15:"<<endl;
	int arr3[] = {1,2,3,4};
	int arr4[] = {5,6,7,8,9,10};
	int arr5[] = {11,12,13};
	printArr(arr3, 4);
	printArr(arr4,6);
	printArr(arr5,3);
	stars();

	cout<<"Problem 16:"<<endl;
	double arr6[] = {1.2, 2.4, 4.8};
	double arr7[] = {2.0,3.0};
	double arr8[] = {3.0};
	printDArr(arr6, 3);
	printDArr(arr7,2);
	printDArr(arr8,1);
	stars();

	cout<<"Problem 17:"<<endl;
	int arr9[] = {1,1,2,2,3,3,4,4}; //Tests that it removes adjacent duplicates
	int size = 8;
	int *copy2[size];
	*copy2 = rArr(arr9, &size);
	arrFunc(*copy2, size);

	int arr10[] = {1,2,2,3,4,1,5,5}; //Tests that it does not remove non adjacent duplicates
	int size2 = 8;
	int *copy3[size2];
	*copy3 = rArr(arr10, &size2);
	arrFunc(*copy3, size2);
	stars();

	cout<<"Problem 18:"<<endl;
	int arr11[] = {1,2,3};

	cout<<hanningArr(&arr11[2],3)<<endl;

	cout<<"Problem 20:"<<endl;

	int arr12[] = {1,2,3,4,5,6,7,8,9};
	int arr13[] = {0,-2,-4,-2,0};
	int arr14[] = {0,0,0,0,-1,-2,-1,0,1,1,0,-1,-2,-3,-2,-2,-1,-1,2};

	printPlot(arr12,9,9,1);
	cout<<endl;
	printPlot(arr13,5,0,-4);
	cout<<endl;
	printPlot(arr14,19,2,-3);
	stars();

	cout<<"Problem 21:"<<endl; //Function seems to fail at the first nested for loops, Its similar to how it was shown in the powerpoint so I don't know why it fails.
	int testX = 0;
	int testY = 0;

	twoDArr(&testX,&testY);























	return 0;
}

void stars(){
	cout<<"******************************************************************"<<endl;
} //stars

/*Function has no input parameters and returns nothing
 * Creates a variable, x, assigns it the integer value 5 and prints the value and memory address of x
 */
void print(){ //Problem 1 function definition

	int x = 5;

	cout<<x<<endl<<&x<<endl;
} //print

/*Function takes in an integer input and returns nothing
 *Adds 4 to the input and prints out the new value and memory address
 */
void cByValue(int x){ //Problem 2 function definition

	x += 4;
	cout<<x<<endl<<&x<<endl;
} //cByValue

/*Function takes in no input parameters and returns an integer
 *Produces a randomly generated integer between 0 and 50, not including 50
 *Returns the value of the integer, prints the value and prints the address
 */
int ranGen(){ //Problem 3 function definition

	int x = rand() % 50;
	cout<<x<<endl<<&x<<endl;
	return x;
} //ranGen

/*Function takes in an integer address and returns nothing
 *Cubes the value stored at the inputed integer address
 *Prints the cubed value
 *Prints the address of the input
 *Prints the address of pointer *x
 */
void cube(int *x){ //Problem 4 function definition

	*x = pow(*x,3);
	cout<<*x<<endl<<x<<endl<<&x<<endl;
} //cube

/*Function takes in an alias for an integer and returns nothing
 *Adds a randomly generated value between 0-10, inclusive, to the input
 *Prints out the random value, the new value, and the address of the alias
 */
void alias(int &x){ //Problem 5 function definition

	int y = rand()%11;
	x += y;
	cout<<y<<endl<<x<<endl<<&x<<endl;
} //alias

/*Function takes in two integer addresses and returns nothing
 *Changes the value of the first input to 32 and the second input to 42
 */
void switcheroo(int *x, int *y){ //Problem 6 function definition

	int *a;
	a = x;
	*a = 32;
	a = y;
	*a = 42;
} //switcheroo

/*Function takes in 4 character inputs, 2 character addresses, 1 character alias, and 1 character value
 *Changes inputs to different characters
 */
void googCode(char c1, char *c2, char &c3, char *c4){ //Problem 7 function definition

	c1 = '?';
	*c2 = 'e';
	c3 = 'u';
	*c4 = 'r';
} //googCode

/*Function takes in two integer alias parameters and returns a boolean
 *Swaps two integer values only if integer 1 is larger than integer 2
 *Using call by reference
 */
bool swap(int &x, int &y){ //Problem 8a function definition

	int n;

	if(x > y){
		n = x;
		x = y;
		y = n;
		return true;
	} //if
	else{
		return false;
	} //else
} //swap

/*Function has no input parameters and returns nothing
 *Loops 20 times, creating 2 random integers between 0-25 inclusive, each loop
 *Prints the 2 generated integers
 *Calls the swap() function and prints the swapped values if applicable
 */
void loop(){ //Problem 8b function definition

	int n;
	int m;

	for (int i = 0; i<20; i++){
		 n = rand()%26;
		 m = rand()%26;
		 cout<<n<<','<<m<<endl;
		 if (swap(n,m) == true){
			 cout<<"swapped: "<<n<<','<<m<<endl;
		 } //if
	} //for
} //loop

/*Function takes in an integer input and an integer alias for call by reference, returns an integer
 *Prints out an array with # of elements equal to the integer input, elements are randomly generated between 1-50
 *Determines the smallest value in the generate array, returns this value, changes the original input to this new value
 */
int smallVal(int len, int &x){ //Problem 8 function definition

	x = -1; //Initialized as -1
	int arr[len]; //Allocates space for an array of ints of length len
	for (int i = 0; i < len; i++){
		arr[i] = rand()% 50 + 1;
		cout<<arr[i]<<' ';
	} //for
	cout<<endl;

	int tiny = arr[0]; //Tracks smallest value in the array
	for (int i = 1; i < len; i++){
		if (arr[i] < tiny){
			tiny = arr[i];
		} //if
	} //for
	x = tiny;
	return x;
} //smallVal

/*Function takes in an integer input and returns nothing
 *Prints out a randomly generated array of length len
 *Prints out the reverse order of the initial array
 */
void flip(int len){ //Problem 9 function definition

	int arr[len];
	for (int i = 0; i<len; i++){
		arr[i] = rand()%51;
		cout<<arr[i]<<' ';
	} //for
	cout<<endl;

	int f;
	for (int i = 0; i<len; i++){
		if (i<len/2){
			f = arr[i];
			arr[i] = arr[len - i - 1 ];
			arr[len - i - 1] = f;
		} //if
		cout<<arr[i]<<' ';
	} //for
	cout<<endl;
} //flip

/*Function takes in two integer inputs and returns nothing
 *Generates a random array of len length with numbers between 0 and r
 *Prints the smallest value in the array, then replaces it
 *Prints out every value in the array in numerical order
 */
void fiftyOne(int len, int r){ //Problem 10 function definition

	int arr[len];
	for (int i = 0; i<len; i++){
		arr[i] = rand()%r;
		cout<<arr[i]<<' ';
	} //for
	cout<<endl;

	int tiny = arr[0];
	int index = 0;
	for (int i = 0; i<len; i++){
		for (int i = 0; i<len; i++){
			if (arr[i] < tiny){
				tiny = arr[i];
				index = i;
			} //if
		} //for
		cout<<tiny<<' ';
		arr[index] = r + 1;
		tiny = r + 1;
	} //for
	cout<<endl;

} //fiftyOne

/*Function has no input paramters and returns an integer address
 *Prints the value and address for a local variable x
 *Attempts to return a local variable address
 */
int* testFunc(){ //Problem 11 function definition

	int x = 3;
	cout<<x<<endl<<&x<<endl;
	return &x;
} //testFunc

/*Function takes in an integer array and an integer length of the array
 *Prints out the array in a single line with commas in between each number with an endl at the end
 */
void arrFunc(int arr[], int len){ //Problem 12 function definition

	for (int i = 0; i<len; i++){
		if (i != len-1){
			cout<<arr[i]<<',';
		} //if
		else{
			cout<<arr[i];
		} //else
	} //for
	cout<<endl;
} //arrFunc

/*Function takes in 3 int pointer inputs and returns an address
 *Generates a random array between 25-50 size
 *Fills the array with values between -10-10
 *Returns the array and alters the pointer values to be length of the array, the highest value, and lowest value
 */
int* heapArr(int *x, int *y, int *z){ //Problem 13 function definition

	int len = rand()% 25 + 25;
	int *arr = new int[len];
	int high = rand()% 5 + 5;
	int low = rand()% -5 - 5;

	for (int i = 0; i<len; i++){
		arr[i] = rand()% (high - low + 1) + low;
	} //for
	*x = len;
	*y = high;
	*z = low;
	return arr;

} //heapArr

/*Function takes in an integer and returns an address
 *Creates a length of random size between 25-50, fills it, then returns the array (supposedly)
 */
int* stackArr(int x){ //Problem 14 function definition
	int len = x;
	int arr[len];
	int high = rand()% 5 + 5;
	int low = rand()% -5 - 5;

	for (int i = 0; i<len; i++){
		arr[i] = rand()% (high - low + 1) + low;
	} //for
	return arr;
} //stackArr

/*Function takes in an array of integers and an integer len, and returns nothing
 *Prints out every value address in the array
 */
void printArr(int arr[], int len){ //Problem 15 function definition

	for (int i = 0; i<len; i++){
		cout<<&arr[i]<<' ';
	} //for
	cout<<endl;
} //printArr

/*Function takes in an array of doubles and an integer len, returns nothing
 *Prints out every value address in the array
 */
void printDArr(double arr[], int len){ //Problem 16 function definition

	for (int i = 0; i<len; i++){
		cout<<&arr[i]<<' ';
	} //for
	cout<<endl;
} //printDArr

/*Function takes in an integer array and a integer point len, returns an array
 *Removes duplicates in the input array, returns the new array, and changes the len to match the new array
 */
int* rArr(int arr[], int *len){ //Problem 16 function definition

	int temp[*len]; //Temporary array to hold values
	int k = 0;

	for (int i = 0; i<*len-1; i++){
		if (arr[i] != arr[i+1]){
			temp[k++] = arr[i];
		} //if
	} //for

	int *arr2 = new int[k];
	temp[k++] = arr[*len-1];

	for (int i = 0; i<k; i++){
		arr2[i] = temp[i];
		} //for
	*len = k;
	return arr2;
} //rArr

/*Function takes in an array and an integer and returns an integer
 *Performs the hanning window weighted average calculation for a window size w
 */
int hanningArr(int arr[], int w){

	int r = w - 1;
	int it = 1;
	int avg = 0;
	int i = 0;

	for (int i = 0; i<w/2; i++){
		avg = avg + ((arr[i] * it) + (arr[r] * it));

		it ++;
		r--;
	}
	avg = (avg + (arr[i] * it))/9;
	return avg;

}

/*Function takes in an integer array, an integer len, an int max, and an int min, returns nothing
 *Prints out a graph of the array values using asterisks
 */
void printPlot(int arr[], int len, int max, int min){ //Problem 20 function definition

	for (int i = max; i >= min; i--){
		cout<<i<<":";
		for (int j = 0; j<len; j++){
			if (arr[j] == i){
				cout<<"*";
			} //if
			else{
				cout<<" ";
			} //else
		} //for
		cout<<endl;
	} //for
} //printPlot

/*Function takes in two integer addresses and returns a 2d array
 *Generates a 2d array on the heap
 */
int** twoDArr(int* x, int* y){ //Problem 21 function definition

	*x = rand()%5 + 5;
	*y = rand()%4 + 4;

	int **matrix;
	matrix = new int*[*x];

	for (int i = 0; i<*x; i++){
		for (int j = 0; j<*y; j++){
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i<*x; i++){
		for(int j = 0; j<*y; j++){
			cout<<matrix[i][j];
		}
		cout<<endl;
	}

	int count = 0;
	while (count != 5){
		int i = rand()%*x;
		int j = rand()%*y;
		if (matrix[i][j] == 0){
			matrix[i][j] = 1;
		}
		else if (matrix[i][j] == 1){
			count -= 1;
		}
	}
	return matrix;
}




