/**
 *Name: Kevin Du
 *Date: 11/19/2021
 *ID: kd5eyn
 *Filename: huffmanenc.cpp
 */
//https://www2.cs.duke.edu/csed/poop/huff/info/

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include "HuffNode.h"
#include "heap.h"

using namespace std;

void getFreq(map<char,int>& freq, string path){
	//Create a new ifstream for reading in the file
	ifstream file(path);
	if(!file.is_open()){
		//unable to open file, exit function
		return;
	}

	char key;
	//file.get(key) will read in each character and place it in key until file ends
	while(file.get(key)){
		if((key >= ' ') && (key <= '~')){
			freq[key]++;
		}
	}

}

HuffNode* getHuffTree(map<char,int>& freq){
	vector<HuffNode*> nodes;

	//For every element in the frequency map, create a new HuffNode and append it to the vector
	for(map<char,int>::iterator i = freq.begin(); i != freq.end(); i++){
		HuffNode* node = new HuffNode(i->first, i->second);
		nodes.push_back(node);
	}

	binary_heap heap(nodes);
	HuffNode* left;
	HuffNode* right;
	//If there was only one character in the input file
	if(heap.size() < 2){
		HuffNode* treeNode = new HuffNode();
		left = heap.deleteMin();
		treeNode->setLeftChild(left);
		return treeNode;
	}	

	while(heap.size() != 1){
		//Create a new node
		HuffNode* treeNode = new HuffNode();
		left = heap.deleteMin();
		right = heap.deleteMin();
		//Set 2 deleted nodes to the new tree Node
		treeNode->setLeftChild(left);
		treeNode->setRightChild(right);
		//Set total frequency
		treeNode->setFreq(left->getFreq() + right->getFreq());
		//Insert tree node back into heap
		heap.insert(treeNode);
	}
	HuffNode* tree = heap.deleteMin();
	return tree;

}

void getPrefixes(HuffNode* node, map<char, string>& prefixes, string path){
	if(node->getLeft() == NULL && node->getRight() == NULL){
		prefixes[node->getValue()] = path;
		return;
	}
	if(node->getLeft() != NULL){
		string newPath = path + "0";
		getPrefixes(node->getLeft(), prefixes, newPath);
	}
	if(node->getRight() != NULL){
		string newPath = path + "1";
		getPrefixes(node->getRight(), prefixes, newPath);
	}
}

void printPrefix(map<char, string>& prefixes){
	for(map<char, string>::iterator i = prefixes.begin(); i != prefixes.end(); i++){
		cout << i->first << ": " << i->second << endl;
	}
}



int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Incorrect number of arguments" << endl;
		return 0;
	}
	string path = argv[1];
	map<char, int> freq;
	cout << argv[1] << endl;
	getFreq(freq, argv[1]);
	HuffNode* tree = getHuffTree(freq);
	map<char, string> prefixes;
	getPrefixes(tree, prefixes, i);
	printPrefix(prefixes);
	return 0;

}
