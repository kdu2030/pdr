/**
Name: Kevin Du
Date: 9/11/2021
ID: kd5eyn
Filename: testPostFixCalc.cpp
*/

/*
Sources: 
Accepting both ints and strings as input - http://www.cplusplus.com/forum/beginner/150286/
Switch statements with strings - https://hbfs.wordpress.com/2017/01/10/strings-in-c-switchcase-statements/#:~:text=Indeed%2C%20the%20switch%2Fcase%20statement,aren't%20of%20integral%20types!
Testing calculator - https://www.free-online-calculator-use.com/postfix-evaluator.html#
*/

#include <iostream>
#include <string>
#include "postFixCalculator.h"
#include "Stack.h"
#include "StackNode.h"

using namespace std;

int main(){
	postFixCalculator calc;
	string token;
	while(cin >> token){
		calc.handleInput(token);
	}
 	cout << calc.getResult() << endl;
	return 0;
}
