/*makeSeuss.hpp
 * Author: Hansen Shi, Matt Novosel
 * TA: Laura Olson
 */

#ifndef MAKESEUSS_HPP_
#define MAKESEUSS_HPP_

#include "hashMap.hpp"
#include <iostream>

using namespace std;

class makeSeuss {
	string fn; // file name for input (“DrSeuss.txt”)
	string newfile; // name of output file
public:
	hashMap *ht; //I made this public so I could use the print function
	makeSeuss(string file,string newf,bool h1, bool c1);
	void readFile();
	void writeFile();
};

#endif /* MAKESEUSS_HPP_ */
