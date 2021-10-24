#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class hashTable{
	public:
		hashTable();
		hashTable(unsigned int numItems);
		hashTable(unsigned int numItems, double loadFactor);
		unsigned int hash(string value);
		void insert(string value);
		int find(string value);
	private:
		vector<string> table;
	  	vector<int> pows;
		int size;
};

#endif
