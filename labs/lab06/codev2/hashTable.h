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
		hashTable(unsigned int numItems, int maxLength);
		hashTable(unsigned int numItems, int maxLength, double loadFactor);
		unsigned int hash(string value);
		void insert(string value);
		int find(string value);
	private:
	  vector<list<string>> table;
	  vector<int> pows[];
};

#endif
