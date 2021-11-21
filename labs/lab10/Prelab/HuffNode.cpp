/**
 *Name: Kevin Du
 *Date: 11/20/2021
 *ID: kd5eyn
 *Filename: HuffNode.cpp
 */
#include "HuffNode.h"
#include <iostream>
using namespace std;

HuffNode::HuffNode(){
	left = NULL;
	right = NULL;
	value = '*';
	freq = 0;
}

HuffNode::HuffNode(char val, int frequency){
	left = NULL;
	right = NULL;
	value = val;
	freq = frequency;

}

HuffNode::~HuffNode(){
	delete left;
	delete right;
}

char HuffNode::getValue(){
 	return value;
}

int HuffNode::getFreq(){
	return freq;
}

void HuffNode::setLeftChild(HuffNode* leftChild){
	left = leftChild;
}

void HuffNode::setRightChild(HuffNode* rightChild){
	right = rightChild;
}

void HuffNode::setValue(char value){
	this->value = value;
}

void HuffNode::setFreq(int freq){
	this->freq = freq;
}

HuffNode* HuffNode::getLeft(){
	return left;
}

HuffNode* HuffNode::getRight(){
	return right;
}

