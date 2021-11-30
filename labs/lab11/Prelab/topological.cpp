/**
 *Name: Kevin Du
 *Date: 11/29/2021
 *ID: kd5eyn
 *Filename: topological.cpp
 */

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

//courseList - adjacency list of the course graph
map<string, vector<string>> courseList;
//indegrees - maps each course to its respective indegree - # of incoming edges into the course node
map<string, int> indegrees;
//courseList and indegrees should have the same keys - the course names

/**
 *@brief adds the courses to the map and initializes an indegree for each course
 *@param start - the first course listed in the line in the input file, or the course node
 *@param adjacent - the second course listed in the line in the input file, or adjacent course nodes
 * @note map in STL library will make sure that there are no duplicate keys
 */
void addCourse(string start, string adjacent){
	courseList[start].push_back(adjacent);
	indegrees[start] = 0;
}

/**
 *@brief calculates each indegree for each course
 *Will iterate through courseList. Each course is mapped to a vector of adjacent courses. Iterate through
 *that vector, and increment the indegrees of each respective course
 *
 */
void calcIndegree(){
	//Iterating through the courseList keys
	for(map<string,vector<string>>::iterator i = courseList.begin(); i != courseList.end(); i++){
		//Iterating through each vector of adjacent courses
		for(vector<string>::iterator j = i->second.begin(); j != i->second.end(); j++){
			indegrees[*j]++;
		}
	}
}

/**
 *@brief Helper function to get a course with 0 as its indegree
 *@return The course name if found, empty string if not
 *
 *Will iterate through map keys until find a course with 0 as its indegree. If found, return.
 *
 */
string getZero(){
	for(map<string, int>::iterator i = indegrees.begin(); i != indegrees.end(); i++){
		if(i->second == 0){
			return i->first;
		}
	}
	return "";
}

/**
 *@brief Will print out the course and its respective indegree
 *@note For debugging purposes
 *
 */
void printIndegree(){
	for(map<string, int>::iterator i = indegrees.begin(); i != indegrees.end(); i++){
		cout << i->first << " " << i->second << endl;
	}
}

/**
 *@brief Will do a topological sort of the graph and will print out the sorted contents
 *@pre Assumes that courseList is a proper adjacency matrix of the input file and that each indegree is calculated
 *
 */
void topSort(){
	//Finds a course with indegree 0
	string courseName = getZero();
	//While there is at least 1 course with indegree 0
	while(courseName != ""){
		//Print out the course name and set indegree of that course to -1
		cout << courseName << " ";
		indegrees[courseName] = -1;
		
		//Decrement the indegrees of respective adjacent vectors
		for(vector<string>::iterator i = courseList[courseName].begin(); i != courseList[courseName].end(); i++){
			indegrees[*i]--;
		}
		
		//Get  a new course with indegree 0
		courseName = getZero();
	}
	cout << endl;
}

/**
 *@brief reads in input file, constructs a graph, and sorts the graph based on topological sort
 *@param argc - the number of inputs + 1 (./a.out command)
 *@param argv[] - array of command line arguments
 *@pre - assumes that the user has typed in only one command line argument representing the input txt file
 */
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

	string start;
	string adjacent;
	while(file >> start && file >> adjacent){
		if(start == "0" && adjacent == "0"){
			break;
		}
		addCourse(start, adjacent);
	}
	calcIndegree();
	topSort();

	return 0;
}
