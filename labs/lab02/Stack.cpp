#include <iostream>
#include "StackNode.h"
#include "Stack.h"

using namespace std;

Stack::Stack(){
	head = NULL;	
	count = 0;
}

Stack::~Stack(){
	
}

bool Stack::isEmpty(){
	return count == 0;
}

void Stack::push(int value){
	StackNode * addedNode = new StackNode();
	addedNode->value = value;
	if(head == NULL){
		head = addedNode;
	}
	else{
		addedNode->next = head;
		head = addedNode;
	}
}

void Stack::pop(){
	StackNode * oldHead = head;
	head = oldHead->next;
	oldHead->next = NULL;
	delete oldHead;
}

void Stack::top() const{
	return head->value;	
}






