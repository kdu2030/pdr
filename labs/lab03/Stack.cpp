#include <iostream>
#include <string>
#include "StackNode.h"
#include "Stack.h"

using namespace std;

Stack::Stack(){
	head = NULL;	
	count = 0;
}

Stack::~Stack(){
	while(count > 0){
		pop();
		count--;
	}
	delete head;
}

bool Stack::isEmpty() const{
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
	count++;
}

void Stack::pop(){
	StackNode * oldHead = head;
	head = oldHead->next;
	delete oldHead;
	count--;
}

int Stack::top() const{
	if(count == 0){
		return -100;	
	}
	return head->value;	
}

void Stack::printStack() const{
	string stackString = "";
	StackNode * current = head;
	do{
		cout << current->value << " ";
		current = current->next;
	}
	while(current != NULL);
	cout << endl;
}





