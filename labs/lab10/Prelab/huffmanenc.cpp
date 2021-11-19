/**
 *Name: Kevin Du
 *Date: 11/19/2021
 *ID: kd5eyn
 *Filename: huffmanenc.cpp
 */
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

void getFreq(map<char,int> freq, string path){
	//Create a new ifstream for reading in the file
	ifstream file(path);
	if(!file.is_open()){
		//unable to open file, exit function
		return;
	}
	
	char key;
	//file.get(key) will read in each character and place it in key until file ends
	while(file.get(key)){
		int value = freq[key];
	}

}

int main(int argc, char* argv[]){
	string path = argv[1];
	map<char, int> freq;
	getFreq(freq, argv[1]);

}
