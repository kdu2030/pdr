// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
	expressionStack = stack<TreeNode*>();
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
	while(expressionStack.size() > 0){
		TreeNode* nodeToDelete = expressionStack.top();
		cleanTree(nodeToDelete);
		expressionStack.pop();
	}
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
	if(tree->left != NULL){
		cleanTree(tree->left);
	}
	
	if(tree->right != NULL){
		cleanTree(tree->right);	
	}
	
	delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

bool isOperator(string s);

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    // ASK: Do we need to check if there are enough values
    TreeNode *node = new TreeNode(val);
    if(isOperator(val)){
	//Pop off the last two nodes in the stack
    	TreeNode *node1 = expressionStack.top();
		expressionStack.pop();
		TreeNode *node2 = expressionStack.top();
		expressionStack.pop();
		//Make the two nodes that were popped off the children of
		//the operator node
		node->left = node2;
		node->right = node1;
		//add tree to the stack
		expressionStack.push(node);
    }
    else{
	//If val is a number, add it to the stack
    	expressionStack.push(node);
    }
}

//Helper function to determine if the input string is a function
bool isOperator(string s){
	if(s == "+"){
		return true;
	}
	else if(s == "-"){
		return true;
	}
	else if(s == "*"){
		return true;
	}
	else if(s == "/"){
		return true;
	}
	return false;
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
    // prints the node's value
    cout << tree->value << " ";

    if(tree->left != NULL){
	//If the left is not null, go to the left subtree
    	printPrefix(tree->left);
    }
    
    if(tree->right != NULL){
	//If there isn't a left subtree and right isn't NULL,
	//Traverse right subtree
    	printPrefix(tree->right);
    }

}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
	// print tree in infix format with appropriate parentheses
	if(tree->left != NULL){
		//If the left tree is not null, go to the left subtree
		cout << "(";
		printInfix(tree->left);
	}

	if(isOperator(tree->value)){
		cout << " " << tree->value << " ";	
	}
	else{
		cout << tree->value;
	}

	if(tree->right != NULL){
	   //If the right pointer is not null, go to the right subtree
	   printInfix(tree->right);
	   cout << ")";
	}
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
	if(tree->left != NULL){
		printPostfix(tree->left);	
	}
	
	if(tree->right != NULL){
		printPostfix(tree->right);	
	}
	cout << tree->value << " ";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

//Helper method to do the arithmetic
int calcOps(int num1, int num2, string op){
	if(op == "+"){
		return num1 + num2;
	}
	if(op == "-"){
		return num1 - num2;	
	}
	if(op == "/"){
		return num1 / num2;
	}
	if(op == "*"){
		return num1 * num2;
	}
	return 0;
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
	if(isOperator(tree->value) && (tree->left != NULL && tree->right !=NULL)){
		return calcOps(calculate(tree->left), calculate(tree->right), tree->value);
	}
	else{
		//If it is an int
		return stoi(tree->value);	
	}
	
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
	int result = calculate(expressionStack.top());
	cleanTree(expressionStack.top());
	expressionStack.pop();
    return result;
}
