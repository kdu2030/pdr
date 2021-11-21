/**
 *Name: Kevin Du
 *Date: 11/19/2021
 *ID: kd5eyn
 *Filename: huffmanenc.cpp
 */
//Printing out prefix codes - https://www2.cs.duke.edu/csed/poop/huff/info/
//Setting decimal precision - https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-points-with-cout
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
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
		if(i->first == ' '){
			cout << "space" << " " << i->second << endl;
		}
		else{
			cout << i->first << " " << i->second << endl;
		}
	}
}


void printEnc(map<char, string>& prefixes, string path){
	printPrefix(prefixes);
	cout << "----------------------------------------" << endl;

	unsigned int length = 0;
	unsigned int encTotal = 0;

	ifstream file(path);
	if(!file.is_open()){
		return;
	}

	char letter;
	while(file.get(letter)){
		if(prefixes.find(letter) != prefixes.end()){
			cout << prefixes[letter] << " ";
			encTotal += prefixes[letter].length();
			length++;
		}
	}
	cout << endl;

	cout << "----------------------------------------" << endl;

	setprecision(5);

	cout << "There are a total of " << length << " symbols that are encoded." << endl;
	cout << "There are " << prefixes.size() << " distinct symbols used." << endl;
	cout << "There were " << length * 8 << " bits in the original file." << endl;
	cout << "There were " << encTotal << " bits  in the compressed file." << endl;
	cout << "This gives a compression ratio of " << (length*8.0) / encTotal << "." << endl;
	cout << "The cost of the Huffman tree is " << encTotal/float(length) << " bits per character."<< endl;
	
}





int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Incorrect number of arguments" << endl;
		return 0;
	}
	string path = argv[1];
	map<char, int> freq;
	getFreq(freq, argv[1]);
	HuffNode* tree = getHuffTree(freq);
	map<char, string> prefixes;
	getPrefixes(tree, prefixes, "");
	printEnc(prefixes, argv[1]);
	return 0;

}
