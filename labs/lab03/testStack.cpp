#include <iostream>
#include "Stack.h"
#include "StackNode.h"

int main(){
	Stack * test = new Stack();
	test->push(2);
	test->push(4);
	int num1 = test->top();
	test->pop();
	int num2 = test->top();
	test->pop();
	test->push(num1+num2);
	cout << test->top() << endl;
	delete test;
	return 0;
}
