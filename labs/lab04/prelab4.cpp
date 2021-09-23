/**
*Kevin Du
*kd5eyn
*9/19/2021
*prelab4.cpp
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

/**
Sources:
Pow - https://www.cplusplus.com/reference/cmath/pow/
Substring - https://www.cplusplus.com/reference/string/string/substr/
Prepending - https://stackoverflow.com/questions/8468597/prepend-stdstring
*/

void sizeOfTest(){
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of bool: " << sizeof(bool) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of char*: " << sizeof(char*) << endl;
	cout << "Size of double*: " << sizeof(double*) << endl;

}

void overflow(){
	unsigned int max = 0;
	for(int i=0; i < 32; i++){
		max += pow(2, i); 
	}
	unsigned int overflow = max + 1;
	cout << max << " + " << 1 << " = " << overflow << endl; 
}

void outputBinary(unsigned int dec){
	string remain = "";
	unsigned int quotient = dec;
	int i = 0;
	while(quotient > 0){
		remain = to_string(quotient%2) + remain;
		quotient = quotient/2;
		i++;
	}
	
	//Adding padded 0s
	int zeros = 32 - remain.length();
	for(int i = 0; i < zeros; i++){
		remain = "0" + remain;	
	}
	
	string output = "";
	
	//Split into nibbles
	for(int i = 0; i < remain.length(); i+=4){
		output += remain.substr(i, 4) + " ";
	}
	cout << output << endl;	
}

int main(){
	int dec = 0;
	cin >> dec;
	sizeOfTest();
	overflow();
	outputBinary(dec);
	return 0;
}
