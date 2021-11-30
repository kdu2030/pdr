#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
	public:
		/**
		 *@brief Creates a new MiddleEarth object
		 *Constructor that creates a new MiddleEarth object, which contains a graph
		 *of the cities in Middle Earth.
		 *
		 *@param xsize - the length of the map of Middle Earth
		 *@param ysize - the width of the map of Middle Earth
		 *@author - Aaron Bloomfield
		 *@class Middle Earth - representation of Middle Earth from Lord of the Rings
		 */
		MiddleEarth(int xsize, int ysize, int num_cities, int seed);
		/**
		 *@brief Prints out the position of each city
		 */
		void print();
		/**
		 *@brief Prints out the table of the different cities
		 */
		void printTable();
		/**
		 * @brief Calculates the distance between two cities
		 *@param city1 - a reference to a string of the name of city1
		 *@param city2 - a reference to a string of the name of city2
		 *
		 */
		float getDistance(const string& city1, const string& city2);
		
		/**
		 *@brief Returns a series of cities to travel to based on the length
		 *@param The distance traveled
		 */
		vector<string> getItinerary(unsigned int length);

	private:
		int num_city_names, xsize, ysize;
		unordered_map<string, float> xpos, ypos;
		vector<string> cities;
		unordered_map<string, unordered_map<string, float>> distances;

		mt19937 gen; // Mersenne-Twister random number engine
};

#endif
