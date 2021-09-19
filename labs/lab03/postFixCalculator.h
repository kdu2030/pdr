/**
Name: Kevin Du
Date: 9/11/2021
ID: kd5eyn
Filename: postFixCalculator.h
*/

//#include <stack>
#include <iostream>
#include "Stack.h"
#include "StackNode.h"
using namespace std;

#ifndef POSTFIX_H
#define POSTFIX_H

class postFixCalculator{
	public:
		postFixCalculator();
		~postFixCalculator();
		void add();
		void subtract();
		void negate();
		void multiply();
		void divide();
		void handleInput(string token);
		void addToStack(int num);
		int getResult() const;
		void print() const;
		bool isEmpty() const;
	
	private:
		//stack<int> * input;
		Stack * input;
};

#endif