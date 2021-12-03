/**
 *Name: Kevin Du
 *Date: 12/1/2021
 *ID: kd5eyn
 *Filename: puzzle.cpp
 */

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

map<string, int> dists;
string END = "123456780";

void getNeighbors(vector<string>& neighbors, string start);
int findZero(string target);


/**
 *@brief Performs a breadth first search on the permutations of the grid
 *@param start - The start arrangement of the numbered tiles
 *@pre - The input has been converted from a 3x3 grid to a 1D string representation
 *@return The number of required moves required to get to the solution, or -1 if impossible
 *
 */
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
		vector<string> neighbors;
		getNeighbors(neighbors, target); //Make adjacency list for target
		
		for(vector<string>::iterator i = neighbors.begin(); i != neighbors.end(); i++){
			if(dists[*i] == UINT_MAX){
				dists[*i] = dists[target] + 1;
				nodes.push(*i);
			}
		}
	}
	return -1;

		
}

/**
 *@brief Helper method to swap to characters in a string
 *Used for finding the next arrangements of the numbered tiles given a start arrangement
 *The hole (represented by 0) has to be swapped with a valid tile
 *@param target - The original string that will have its characters swapped
 *@param i - The index of the first number to be swapped
 *@param j - The index of the second number to be swapped
 *@return - The original string except with the characters
 */
string swap(string target, int i, int j){
	//https://stackoverflow.com/questions/8196037/c-string-swap-character-places
	swap(target[i], target[j]);
	return target;
}

/**
 *@brief Finding the next possible arrangements of the numbered tiles given a start arrangement
 *@param start - representation of a 3 x 3 grid in a 1D string, where 0 represents the whole
 *@param neighbors - reference of the string that will store possible consecutive tile arrangements
 *Uses the fact that indicies that are the starts of the row are divisible by 3
 *Also uses the fact that moving up or down a row is similar to swapping the hole with a position 3
 *indicies to the left or to the right of the input string
 *@post Neighbors will have all the possible consecutive tile arrangements
 */
void getNeighbors(vector<string>& neighbors, string start){
	int hole = start.find("0");
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
			neighbors.push_back(neighbor);
			if(dists.count(neighbor) == 0){
				dists[neighbor] = UINT_MAX;
			}
			needSwap = false;
		}	
	}
}


/**
 *@brief Helper method that conducts a linear search on a string to find 0 - the hole
 *@param target - The string to find a hole in
 *@return Index if found hole, -1 if hole not found
 *
 */
int findZero(string target){
	for(int i = 0; i < target.length(); i++){
		if(target.at(i) == '0'){
			return i;
		}
	}
	return -1;
}

/**
 *@brief Will take in input for a 3x3 puzzle, conducts the search. Prints out the number of moves if possible, IMPOSSIBLE otherwise
 *Will transform the 3x3 puzzle into 1D string representation, then conduct a search using search().
 */
int main(){
	cout << "Enter puzzle" << endl;
	string line = "";
	string tile = "";
	while(line.length() != 9){
		cin >> tile;
		if(tile != " " && tile != "/n"){
			line.append(tile);
		}
	}
	cout << "Solving puzzle" << endl;
	int numMoves = search(line);
	if(numMoves == -1){
		cout << "IMPOSSIBLE" << endl;
	}else{
		cout << numMoves << endl;
	}

	return 0;
}
