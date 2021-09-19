/**
*Name: Kevin Du
*Date: 9/2/2021
*ID: kd5eyn
*File name: List.cpp
*/

#include <iostream>
#include "ListNode.h"
#include "List.h"
using namespace std;

List::List(){
	head = new ListNode();
	tail = new ListNode();
	head->next = tail;
	tail->previous = head;
	count = 0;
	
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source){
	head=new ListNode();
   tail=new ListNode();
   head->next=tail;
   tail->previous=head;
   count=0;

    // Make a deep copy of the list
   ListItr iter(source.head->next);
   while (!iter.isPastEnd()) {
       insertAtTail(iter.retrieve());
       iter.moveForward();
   }
}

List::~List(){
	if(!isEmpty()){
		makeEmpty();
	}
	delete head;
	delete tail;
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source){
	if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
	return count == 0;
}

void List::makeEmpty(){
	ListItr i = first();
	while(!i.isPastEnd()){
			i.moveForward();
			delete i.current->previous;
	}
	head->next = tail;
	tail->previous = head;
	count = 0;
}


ListItr List::first(){
	ListItr iterator = ListItr(head->next);
	return iterator;
}

ListItr List::last(){
	ListItr iterator = ListItr(tail->previous);
	return iterator;
}

void List::insertAfter(int x, ListItr position){
	//1. Create new node
	ListNode * addedNode = new ListNode();
	ListNode * targetNode = position.current;
	ListNode * targetNext = targetNode->next;
	addedNode->value = x;
	//2. Set the value of addedNode's previous to the targetNode.
	addedNode->previous = targetNode;
	//3. Set the value of addedNode's next to the target's next
	addedNode->next = targetNext;
	//4. Set the value of the target element's next to the added Node
	targetNode->next = addedNode;
	//5. Set the previous of targetNext to the addednode
	targetNext->previous = addedNode;
	//6. Increment count
	count++;
}

void List::insertBefore(int x, ListItr position){
	//1. Create new node
	ListNode * addedNode = new ListNode();
	ListNode * targetNode = position.current;
	ListNode * targetPre = targetNode->previous;
	addedNode->value = x;
	//2. Set the value of addedNode's previous to the previous of the targetNode
	addedNode->previous = targetPre;
	//3. Set the value of addedNode's next to the memory address of the targetNode
	addedNode->next = targetNode;
	//4. Set the value of the target element's next to the added Node
	targetPre->next = addedNode;
	//5. Set  the previous of targetElement to the addednode
	targetNode->previous = addedNode;
	//6. Increment count
	count++;
}

void List::insertAtTail(int x){
	//1. Create new node
	ListNode * addedNode = new ListNode();
	ListNode * oldTailPre = tail->previous;
	addedNode->value = x;
	//2. Set the value of addedNode's previous to the previous of the tail
	addedNode->previous = oldTailPre;
	//3. Set the value of addedNode's next to the memory address of the tail node
	addedNode->next = tail;
	//4. Set the value of the old last element's next to the added Node
	oldTailPre->next = addedNode;
	//5. Set  the previous of tail to the addednode
	tail->previous = addedNode;
	//6. Increment count
	count++;
}

ListItr List::find(int x){
	//Creates a new ListItr pointed to the first element of the list
	ListItr i = first();
	while(!i.isPastEnd()){
		int data = i.retrieve();
		if(data == x){
			return i;
		}
		i.moveForward();
	}
	//Returns a ListItr pointed to the dummy tail if find was unsuccessful
	return ListItr(tail);
}

void List::remove(int x){
	ListItr i = find(x);
	if(i.current != tail){
		ListNode * preElement = i.current->previous;
		ListNode * nextElement = i.current->next;
		preElement->next = nextElement;
		nextElement->previous = preElement;
		delete i.current;
	}
}

int List::size() const{
	return count;	
}

void printList(List& source, bool forward){
	if(forward){
		ListItr i = source.first();
		while(!i.isPastEnd()){
			cout << i.retrieve() << " ";
			i.moveForward();
		}
		cout << endl;
	}
	else{
		ListItr i = source.last();
		while(!i.isPastBeginning()){
			cout << i.retrieve() << " ";	
			i.moveBackward();
		}
		cout << endl;
	}

}



