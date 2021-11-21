/**
 *Name: Kevin Du
 *Date: 11/20/2021
 *ID: kd5eyn
 *Filename: HuffNode.h
 */

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>
using namespace std;

class HuffNode{
	public:
		HuffNode();
		~HuffNode();
		HuffNode(string value, int freq);
		string getValue();
		int getFreq();
		HuffNode* getLeft();
		HuffNode* getRight();
		void setLeftChild(HuffNode* left);
		void setRightChild(HuffNode* right);
		void setFreq(int freq);
		void setValue(string value);

	private:
		HuffNode* left;
		HuffNode* right;
		string value;
		int freq;

	friend class binary_heap;

};


#endif
