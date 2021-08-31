/*
 * Name: Kevin Du
 * ID: kd5eyn
 * Date: 8/26/2021
 * File: xToN.cpp
 */

/*Sources:
 *https://www.youtube.com/watch?v=vLnPwxZdW4Y&vl=en
 */

#include <iostream>
using namespace std;

int xton(int base, int exponent){
	if(exponent == 0){
		return 1;
	}
	return base * xton(base, exponent-1);
}


int main() {
	int base = 0;
	int power = 0;
	int answer = 0;
	cin >> base;
	cin >> power;
	answer = xton(base, power);
	cout << answer << endl;	
	return 0;
}
