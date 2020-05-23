/* hashMap.cpp
 * Author: Hansen Shi
 * TA: Lauren Olson
 */

#include "hashMap.hpp"
#include<string>


hashMap::hashMap(bool hash1, bool coll1){
	first = " ";
	numKeys = 0;

	mapSize = 11;

	h1 = hash1;
	c1 = coll1;
	collisionct1 = 0;
	collisionct2 = 0;

	map = new hashNode* [mapSize];

	for (int i = 0; i<mapSize; i++){
		map[i] = NULL;
	}
}

void hashMap::addKeyValue(string k, string v){
	int index = getIndex(k);

	if (map[index] == NULL){
		map[index] = new hashNode(k,v);
		numKeys++;
	}
	else if (map[index]->keyword == k){
		map[index]->addValue(v);
	}
	else{
		int coll = 0;

		if (c1){
			coll = collHash1(index);
		}
		else{
			coll = collHash2(index);
		}
		collisionct1++;

		if (map[coll] == NULL){
			map[coll] = new hashNode(k,v);
			numKeys++;
		}
		else if (map[coll]->keyword == k){
			map[coll]->addValue(v);

		}
	}

	if (numKeys >= (mapSize * .7)){
		reHash();
	}
}

int hashMap::getIndex(string k){
	if (h1){
		return calcHash(k);
	}
	else{
		return calcHash2(k);
	}
}

/* This hash function adds the first 3 characters (ASCII) of the string being passed in
 * then multiplies them by the length of the string that was passed in
 * then mods by the array size
 * if the string entered has less than 3 characters, only the characters available will be summed
 */
int hashMap::calcHash(string k){
	int h = 0;
	int len = k.length();
	if (k.length() >= 3){
		for (int i = 0; i<3; i++){
			h += (int(k[i]));
		}
	}
	else{
		for (int i = 0; i<len; i++){
			h += (int(k[i]));
		}
	}

	h *= len;
	return h % mapSize;
}

/* This hash function adds every character of the string (ASCII)
 * then divides the sum by the ASCII value of the first character
 * then mods by the array size
 */
int hashMap::calcHash2(string k){
	int h = 0;
	int len = k.length();
	int first = (int(k[0]));

	for (int i = 0; i<len; i++){
		h += (int(k[i]));
	}

	h /= first;
	return h % mapSize;
}

int hashMap::getClosestPrime(){

	int dbl = mapSize*2;

	for (int i = dbl; i<2*dbl; i++){
		if (primeChecker(i) == true){
			dbl = i;
			break;
		}
	}
	cout<<dbl<<endl;
	return dbl;
}

void hashMap::reHash(){
	int size = mapSize;
	mapSize = getClosestPrime();

	hashNode** newMap = new hashNode*[mapSize];
	for (int i = 0; i<mapSize; i++){
		newMap[i] = NULL;
	}
	for (int i = 0; i<size; i++){
		if (map[i] != NULL){
			int tmp2 = getIndex(map[i]->keyword);
			if (newMap[tmp2] == NULL){
				newMap[tmp2] = map[i];
			}
			else{
				int coll;
				if (c1){
					coll = collHash1(tmp2);
				}
				else{
					coll = collHash2(tmp2);
				}
				newMap[coll] = map[i];
			}
		}
	}
	hashNode** older = map;
	map = newMap;
	delete older;
}

/* This collision method is the linear probing method
 * when a collision occurs it will traverse the hashmap for the next empty space
 * it will then insert the offending key in that index instead
 * loops back to zero when applicable
 */
int hashMap::collHash1(int i){
	int next = i + 1;
	bool null = false;

	while (!null){
			if (map[next] == NULL){
				null = true;
			}
			if (next == mapSize){
				next = 0;
			}
			else{
				next ++;
				collisionct2++;
			}
	}
	return next;
}

/* This collision method is the quadratic probing method
 * Similar to linear probing, but instead of incrementing by 1
 * we look at the next index by n^2 where n increments by 1 per iteration
 * loops back to 0 when applicable
 */
int hashMap::collHash2(int i) {
	int newIndex = i + 1;
	bool null = false;
	int counter = 1;

	while (!null){
		if (map[newIndex] == NULL)
			return newIndex;
		else {
			newIndex += (counter * counter);
			counter++;
			collisionct2++;
		}
		if (newIndex > mapSize){
			newIndex = mapSize - counter;
		}
	}
}


int hashMap::findKey(string k){
	int kIndex = getIndex(k);

	if (map[kIndex] != NULL && map[kIndex]->keyword == k){
		return kIndex;
	}
	else{
		return -1;
	}
}

void hashMap::printMap(){
	for (int i = 0; i < mapSize; i++){
		if (map[i] != NULL)
			map[i]->printNode();
		else
			cout << "NULL" << endl;
	}
}



bool hashMap::primeChecker(int n){
	if (n == 2){
		return true;
	}
	else if(n%2 == 0){
		return false;
	}
	else{
		for (int i = 3; i<n; i += 2){
			if (n%i == 0)
				return false;
		}
		return true;
	}
}

void hashMap::getCollisions(){
	cout<< "Collisionct1 = "<< collisionct1 <<endl << "Collisionct2 = "<< collisionct2 <<endl;
}
