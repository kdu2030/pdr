#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "StackNode.h"
using namespace std;

class Stack{
	public:
		Stack();
		~Stack();
		bool isEmpty() const;
		void push(int value);
		void pop();
		int top() const;
		void printStack() const;
	
	private:
		StackNode * head;
		int count;

};

#endif
