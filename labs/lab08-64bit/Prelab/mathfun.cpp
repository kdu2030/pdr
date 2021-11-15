/*
Name: Kevin Du
Date: 10/30/2021
ID: kd5eyn
File: mathfun.cpp
*/
#include <iostream>
using namespace std;
extern "C" int product(int x, int y);
extern "C" int power(int x, int y);

int main(){
	int x = 0;
	int y = 0;
	cout << "Enter Integer 1: ";
	cin >> x;
	cout << "Enter Integer 2: ";
	cin >> y;
	
	int prod = product(x,y);
	cout << "Product: " << prod <<  endl;
	int pow = power(x, y);
	cout << "Power: " << pow << endl;
	
	return 0;	
}