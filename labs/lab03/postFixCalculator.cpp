/**
Name: Kevin Du
Date: 9/11/2021
ID: kd5eyn
Filename: postFixCalculator.cpp
*/

//#include <stack>
#include <iostream>
#include <string>
#include "postFixCalculator.h"
#include "Stack.h"
using namespace std;

postFixCalculator::postFixCalculator(){
	//input = new stack<int>();
	input = new Stack();
}

postFixCalculator::~postFixCalculator(){
	delete input;	
}

void postFixCalculator::addToStack(int num){
	input->push(num);
}


void postFixCalculator::add(){
	int num1 = input->top(); //Second to last inserted
	input->pop();
	int num2 = input->top(); //Last inserted
	input->pop();
	input->push(num1 + num2);
}

void postFixCalculator::subtract(){
	int num1 = input->top(); //Second to last inserted
	input->pop();
	int num2 = input->top(); //Last inserted
	input->pop();
	input->push(num2 - num1);
}

void postFixCalculator::negate(){
	int num = input->top(); //Second to last inserted
	input->pop();
	input->push(num * -1);
}

void postFixCalculator::multiply(){
	int num1 = input->top(); //Second to last inserted
	input->pop();
	int num2 = input->top(); //Last inserted
	input->pop();
	input->push(num1 * num2);
}

void postFixCalculator::divide(){
	int num1 = input->top(); //Second to last inserted
	input->pop();
	int num2 = input->top(); //Last inserted
	input->pop();
	input->push(num2 / num1);
}
	

void postFixCalculator::handleInput(string token){
	
	if(token == "+"){
		add();
	}
	else if(token == "-"){
		subtract();
	}
	else if(token == "~"){
		negate();
	}
	else if(token == "*"){
		multiply();
	}
	else if(token == "/"){
		divide();
	}
	else{
		//stoi(token) converts token to an int
		addToStack(stoi(token));
	}
	
}

int postFixCalculator::getResult() const{
	return input->top();	
}

bool postFixCalculator::isEmpty() const{
	return input->isEmpty();
}

void postFixCalculator::print() const{
	input->printStack();
}
