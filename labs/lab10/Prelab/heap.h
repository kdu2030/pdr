#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <iostream>
#include "HuffNode.h"
using namespace std;

class binary_heap {
	public:
		binary_heap();
		binary_heap(vector<HuffNode*> vec);
		~binary_heap();

		void insert(HuffNode* x);
		HuffNode* findMin();
		HuffNode* deleteMin();
		unsigned int size();
		void makeEmpty();
		bool isEmpty();
		void print();
		void print_vector();

	private:
		vector<HuffNode*> heap;
		unsigned int heap_size;

		void percolateUp(int hole);
		void percolateDown(int hole);
};

#endif
