/**
 *Name: Kevin Du
 *Date: 12/1/2021
 *ID: kd5eyn
 *Filename: puzzle.cpp
 */

#include <string>
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

map<string, list<string>> moves;
map<string, int> dists;
string END = "123456780";
string start;

void getNeighbors(string start);

int findZero(string target);

string swap(string target, int i, int j){
	char temp = target[i];
	target[i] = target[j];
	target[j] = temp;
	return target;
}


void getNeighbors(string start){
	int hole = findZero(start);
	int i = 0;
	i = hole + 1;
	string neighbor;

	if(i%3 != 0){
		neighbor = swap(start, i, hole);
		moves[start].push_back(neighbor);
	}
	
	i = hole - 1;
	if(hole%3 != 0){
		neighbor = swap(start, i, hole);
		moves[start].push_back(neighbor);
	}
	
	i = hole - 3;
	if(i > 0){
		neighbor = swap(start, i, hole);
		moves[start].push_back(neighbor);
	}

	i = hole + 3;
	if(i < start.length()){
		neighbor = swap(start, i, hole);
		moves[start].push_back(neighbor);
	}
	
}

int findZero(string target){
	for(int i = 0; i < target.length(); i++){
		if(target.at(i) == '0'){
			return i;
		}
	}
	return -1;
}

int main(){
	cout << "Enter puzzle" << endl;
	string line = "";
	for(int i = 0; i < 3; i++){
		getline(cin, line);
		start += line;
	}
	getNeighbors(start);
	return 0;
}
