/* main.cpp
 * Author: Hansen Shi
 * TA: Lauren Olson
 */

#include <time.h>
#include "makeSeuss.hpp"

int main() {
	srand(time(NULL));
	makeSeuss* seuss = new makeSeuss("DrSeuss.txt", "Hash1-CollisionHash1.txt", true, true); //Hash1, Coll 1
	//makeSeuss* seuss2 = new makeSeuss("DrSeuss.txt", "Hash1-CollisionHash2.txt", true, false); //Hash 1, Coll 2
	//makeSeuss* seuss3 = new makeSeuss("DrSeuss.txt", "Hash2-CollisionHash2.txt", false, false); //Hash 2, Coll 2
	//makeSeuss* seuss4 = new makeSeuss("DrSeuss.txt", "Hash2-CollisionHash1.txt", false, true); //Hash 2, Coll 1

	seuss->ht->printMap();
	seuss->ht->getCollisions();
	//seuss2->ht->printMap();
	//seuss2->ht->getCollisions();
	//seuss3->ht->printMap();
	//seuss3->ht->getCollisions();
	//seuss4->ht->printMap();
	//seuss4->ht->getCollisions();
	return 0;
}
