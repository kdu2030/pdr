/**
 *Name: Kevin Du
 *Date: 11/21/2021
 *ID: kd5eyn
 *Filename: huffmandec.cpp
 */

#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <string>

#include "HuffNode.h"

using namespace std;


void createNode(HuffNode* node, string target, string prefix){
	if(prefix.at(0) == '0' && node->getLeft() != NULL){
		createNode(node->getLeft(), target, prefix.substr(1, prefix.length()-1));
	}
	else if(prefix.at(0) == '0' && node->getLeft() == NULL){
		HuffNode* created;
		//If the prefix.length() == 1, that means we need to add a new leaf node
		if(prefix.length() == 1){
			created = new HuffNode(target, 0);
			node->setLeftChild(created);
			return;
		}
		created = new HuffNode();
		node->setLeftChild(created);
		createNode(node->getLeft(), target, prefix.substr(1, prefix.length()-1));
	}
	else if(prefix.at(0) == '1' && node->getRight() != NULL){
		createNode(node->getRight(), target, prefix.substr(1, prefix.length()-1));
	}
	else if(prefix.at(0) == '1' && node->getRight() == NULL){
		HuffNode* created;
		if(prefix.length() == 1){
			created = new HuffNode(target, 0);
			node->setRightChild(created);
			return;
		}
		created =  new HuffNode();
		node->setRightChild(created);
		createNode(node->getRight(), target, prefix.substr(1, prefix.length()-1));
	}
	
}

int main(int argc, char* argv[]){
	// verify the correct number of parameters
	if (argc != 2) {
		cout << "Must supply the input file name as the only parameter" << endl;
		exit(1);
	}

	map<string, string> prefixes;

	// attempt to open the supplied file
	// must be opened in binary mode as otherwise trailing whitespace is discarded
	ifstream file(argv[1], ifstream::binary);
	// report any problems opening the file and then exit
	if (!file.is_open()) {
		cout << "Unable to open file '" << argv[1] << "'." << endl;
		exit(2);
	}

	// read in the first section of the file: the prefix codes
	while (true) {
		string character, prefix;
		// read in the first token on the line
		file >> character;

		// did we hit the separator?
		if (character[0] == '-' && character.length() > 1) {
			break;
		}

		// check for space
		if (character == "space") {
			character = " ";
		}

		// read in the prefix code
		file >> prefix;
		// do something with the prefix code
		prefixes[character] = prefix;
		cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
	}

	// read in the second section of the file: the encoded message
	stringstream sstm;
	while (true) {
		string bits;
		// read in the next set of 1's and 0's
		file >> bits;
		// check for the separator
		if (bits[0] == '-') {
			break;
		}
		// add it to the stringstream
		sstm << bits;
	}
	return 0;

}

