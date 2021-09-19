/**
*Name: Kevin Du
*Date: 9/2/2021
*ID: kd5eyn
*File name: ListItr.cpp
*/

#include <iostream>
#include "ListNode.h"
#include "List.h"
using namespace std;

ListItr::ListItr(){
	current = NULL;

}

ListItr::ListItr(ListNode* theNode){
	current = theNode;
	
}

bool ListItr::isPastEnd() const{
	return current->next == NULL;
}

bool ListItr::isPastBeginning() const{
	return current->previous == NULL;
}

void ListItr::moveForward(){
	if(!isPastEnd()){
		current = current->next;	
	}
	
}

void ListItr::moveBackward(){
	if(!isPastBeginning()){
		current = current->previous;	
	}
	
}

int ListItr::retrieve() const{
	return current->value;
}



