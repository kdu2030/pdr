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
#include <climits>
#include <queue>
using namespace std;

map<string, list<string>> moves;
map<string, string> paths;
map<string, int> dists;
string END = "123456780";
string start;

void getNeighbors(string start);
int findZero(string target);

int search(string start){
	queue<string> nodes;
	string target;

	//Enqueue start - first node
	nodes.push(start);
	//We visited start, so set distance to 0
	dists[start] = 0;

	while(!nodes.empty()){
		//Dequeue the first node
		target = nodes.front();
		nodes.pop();
		if(target == END){
			return dists[target];
		}
		getNeighbors(target); //Make adjacency list for target
		
		for(list<string>::iterator i = moves[target].begin(); i != moves[target].end(); i++){
			if(dists[*i] == UINT_MAX){
				dists[*i] = dists[target] + 1;
				paths[*i] = target; //NOTE: May not be needed, gets the path
				nodes.push(*i);
			}
		}
	}
	return -1;

		
}

string swap(string target, int i, int j){
	char temp = target[i];
	target[i] = target[j];
	target[j] = temp;
	return target;
}

void getNeighbors(string start){
	int hole = findZero(start);
	int s = 0;
	string neighbor;
	bool needSwap = false;

	for(int i = 0; i < 4; i++){
		if(i == 0 && (hole+1)%3 != 0){
			s = hole + 1;
			needSwap = true;
		}
		else if(i == 1 && hole%3 != 0){
			s = hole - 1;
			needSwap = true;
		}
		else if(i == 2 && hole-3 > 0){
			s = hole - 3;
			needSwap = true;
		}
		else if(i == 3 && hole+3 < start.length()){
			s = hole + 3;
			needSwap = true;
		}

		if(needSwap){
			neighbor = swap(start, s, hole);
			moves[start].push_back(neighbor);
			if(dists.find(neighbor) == dists.end()){
				dists[neighbor] = UINT_MAX;
			}
			needSwap = false;
		}	
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

void printPath(){
	string target = paths[END];
	list<string> path;
	path.push_front(END);
	while(target != start){
		path.push_front(target);
		target = paths[target];
	}

	for(auto i = path.begin(); i != path.end(); i++){
		cout << *i << endl;
	}
}

int main(){
	cout << "Enter puzzle" << endl;
	string line = "";
	for(int i = 0; i < 3; i++){
		getline(cin, line);
		start += line;
	}
	cout << "Solving puzzle" << endl;
	int numMoves = search(start);
	if(numMoves == -1){
		cout << "IMPOSSIBLE" << endl;
	}else{
		cout << numMoves << endl;
	}
	return 0;
}
