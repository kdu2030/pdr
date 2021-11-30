/**
 *Name: Kevin Du
 *Date: 11/29/2021
 *ID: kd5eyn
 *Filename: topological.cpp
 */

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Vertex.h"
using namespace std;

map<Vertex, vector<Vertex>>;
int topNum = 0;


void addVertex(string course){
	//Assigning topological numbers
	if(std::find(courses.begin(), courses.end(), course) != courses.end()){
		courses.push_back(co	
		indegrees.push_back(0);
	}

}

void addAdjVertex(string start, string adj){
	int topNum = courses.find(start) - courses.begin();
	adjList[topNum].push_back(courses[adj]);
}

void calculateIndegrees(){
	//Iterate through the entire map
	for(map<int, vector<int>>::iterator j = adjList.begin(); j != adjList.end(); j++){
		//Iterate through each list of adjacent verticies for each vector
		for(vector<int>::iterator k = j->second.begin(); k != j->second.end(); k++){
			//Increment element in indegrees corresponding to the adjacent vertex
			indegrees[*k]++;
		}
	}
}

void printIndegrees(){
	for(vector<int>::iterator j = indegrees.begin(); j != indegrees.end(); j++){
		cout << 
	}
}



int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Wrong number of arguments" << endl;
		return 0;
	}

	ifstream file(argv[1]);
	if(!file.is_open()){
		cout << "Unable to open file" << endl;
		return 0;
	}

	stringstream s;
	string course;
	string startCourse;
	bool start = true;
	while(true){
		file >> course;
		if(course == "0"){
			break;
		}
		addVertex(course);
		if(!start){
			addAdjVertex(startCourse, course);
			startCourse = "";
			start = true;
		}
		else{
			startCourse = course;
			start = false;
		}
	}

		

	return 0;
}
