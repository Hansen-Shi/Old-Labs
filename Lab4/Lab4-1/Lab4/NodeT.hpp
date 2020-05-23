

#ifndef NodeT_HPP_
#define NodeT_HPP_

#include <string>
using namespace std;

class NodeT {
	friend class BSTY;

public:
	string data;
	int height;
	NodeT *left;
	NodeT *right;
	NodeT *parent;


	NodeT(string x);
	~NodeT();
	void printNode();
};



#endif /* NodeT_HPP_ */
