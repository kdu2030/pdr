/*
 *Name: Kevin Du
 *Date: 10/30/2021
 *ID: kd5eyn
 *Filename: traveling.cpp
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, const vector<string>& dests);
void printRoute(const string& start, const vector<string>& dests);


/**
 *@brief Computes the traveling salesman problem for cities in Middle Earth. Prints out the path and the distance
 *@pre {Assumes that the user has entered in 5 command line parameters
 *World height, world width, number of cities in the world, random seed, and cities to visit}
 *Will compute every possible combination of cities to go to, and print out the one combination that has the shortest distance
 *
 */
int main(int argc, char** argv) {
	// check the number of parameters
	if (argc != 6) {
		cout << "Usage: " << argv[0] << " <world_height> <world_width> "
			<< "<num_cities> <random_seed> <cities_to_visit>" << endl;
		exit(0);
	}

	// we'll assume the parameters are all well-formed
	int width = stoi(argv[1]);
	int height = stoi(argv[2]);
	int num_cities = stoi(argv[3]);
	int rand_seed = stoi(argv[4]);
	int cities_to_visit = stoi(argv[5]);

	// create the world, and select your itinerary
	MiddleEarth me(width, height, num_cities, rand_seed);
	vector<string> dests = me.getItinerary(cities_to_visit);

	// TODO: YOUR CODE HERE
	sort(dests.begin() + 1, dests.end());
	
	//https://www.geeksforgeeks.org/ways-copy-vector-c/
	float minDistance = computeDistance(me, dests[0], dests);
       	vector<string> shortestPath = dests;
	
	do{
		float distance = computeDistance(me, dests[0], dests);
		if(distance < minDistance){
			minDistance = distance;
			shortestPath = dests;
		}
		
	} while(next_permutation(dests.begin() + 1, dests.end()));

	cout << "Minimum path has distance " << minDistance << ": ";
	printRoute(shortestPath[0], shortestPath);

	return 0;
}


/**
 *@brief Computes the distance for a list of cities to visit
 *@param me MiddleEarth object containing the randomly placed cities
 *@param start The start and end city
 *@param dests Vector representing the path of cities to visit
 * @note Assumes that the path is a round trip, i.e. start == end
 */
// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, const vector<string>& dests) {
	float total = 0.0;
	for(int i = 0; i < dests.size(); i++){
		//If this is the last city, compute distance between start and last destination
		if(i == dests.size() - 1){
			total += me.getDistance(dests[i], dests[0]);
		}
		else{
			total += me.getDistance(dests[i], dests[i+1]);
		}	
	}
	return total;
}

/**
 *@brief Prints the route out given a list of destinations
 *@param start - the start (and end) city
 *@param dests - the list of cities to visit
 *@note Assumes that the route is a round trip
 */
// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
	//https://stackoverflow.com/questions/47127919/find-if-error-no-viable-conversion-from-iterators
	for(auto i = dests.begin(); i != dests.end(); i++){
		cout << *i << " -> ";
	}
	cout << start << endl;
}


