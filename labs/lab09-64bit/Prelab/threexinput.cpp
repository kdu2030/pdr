/*
 *Name: Kevin Du
 *Date: 11/14/2021
 *ID: kd5eyn
 *File: threexinput.cpp
 */

#include <iostream>
using namespace std;

extern "C" int threexplusone(int x);

int main(){
	int x = 0;
	int numTimes = 0;
	int result = 0;
	
	cout << "Enter a number: ";
	cin >> x;
	cout << "Enter iterations of subroutine: ";
	cin >> numTimes;
	
	result = threexplusone(x);
	for(int i = 0; i < numTimes; i++){
		threexplusone(x);
	}
	cout << "Steps: " << result << endl;
	return 0;
}
