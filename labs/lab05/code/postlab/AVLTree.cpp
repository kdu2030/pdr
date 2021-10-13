/*
*Name: Kevin Du
*Date: 10/6/2021
*ID: kd5eyn
*File: AVLTree.cpp
*/

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

void AVLTree::insert(AVLNode*& node, const string& x){
	if(node == NULL){
	  node = new AVLNode();
	  node->value = x;      
	}
	else if(x < node->value){
	  insert(node->left, x);
	}
	else if(x > node->value){
	  insert(node->right, x);
	}
	//When insertion is finished, the program will recurse up the tree
	//Updates the height of each AVL tree
	node->height = 1 + max(height(node->left), height(node->right));
	//FOR DEBUGGING ONLY
	//cout << node->value << " " << node->height << endl;
	balance(node);
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
	insert(root, x);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

//Helper method to make it recursive
//Constructs the string path
string AVLTree::pathTo(AVLNode* node, const string& x) const{
	if(node == NULL){
	  return "";
	}
	else if(x < node->value){
	  return node->value + " " + pathTo(node->left, x);
	}
	else if(x > node->value){
	  return node->value + " " + pathTo(node->right, x);
	}
	return node->value;	
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
	if(find(x)){
	  return pathTo(root, x);
	}
	return ""; 
}

AVLNode* AVLTree::find(AVLNode* node, const string& x) const{
   if(node == NULL){
      return NULL;
   }
   //If the current node is greater than the node, go left
   else if(x < node->value){
      return find(node->left, x);
   }
   //If the current node is less than the node, go right
   else if(x > node->value){
      return find(node->right, x);
   }
   return node;
   
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
	if(find(root, x) == NULL){
      return false;
    }
    return find(root, x);
}


int AVLTree::numNodes(AVLNode* node) const{
   if(node == NULL){
      return 0;
   }
   
   int sizeLeft = numNodes(node->left);
   int sizeRight = numNodes(node->right);
   return sizeLeft + sizeRight + 1;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
	return numNodes(root);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
   //YOUR IMPEMENTATION HERE
   int nBalance = findBalance(n);
   if(nBalance == -2 && findBalance(n->left) == -1){
      //left left case
      n = rotateRight(n);
   }
   else if(nBalance == -2 && findBalance(n->left) == 1){
      //left right case
      n->left = rotateLeft(n->left);
      n = rotateRight(n);
   }
   else if(nBalance == 2 && findBalance(n->right) == 1){
      //right right case
      n = rotateLeft(n);
   }
   else if(nBalance == 2 && findBalance(n->right) == -1){
      //right left case
      n->right = rotateRight(n->right);
      n = rotateLeft(n);
   }
   else{
      //If it is already balanced
      return;
   }
   
}

//Finds the balance factor given a node
int AVLTree::findBalance(AVLNode*& node) const{
	int leftHeight = height(node->left);
	int rightHeight = height(node->right);
	return rightHeight - leftHeight;
}

/**
int leftHeight = 0;
   int rightHeight = 0;
   if(node->left != NULL){
      leftHeight = node->left->height;
   }
   if(node->right != NULL){
      rightHeight = node->right->height;
   }
   return rightHeight - leftHeight;
*/

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    //Your implementation goes here
    AVLNode* target = n;
    //pivot will be promoted
    AVLNode* pivot = n->right;
	target->right = pivot->left;
    pivot->left = target;
	//Updates heights of pivot and target
	pivot->height = height(pivot);
	target->height = height(target);
    return pivot;
}

//REMOVE: pivot->left = target->right;

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* target = n;
    AVLNode* pivot = n->left;
	target->left = pivot->right;
    pivot->right = target;
	
	//Updates heights of pivot and target
	pivot->height = height(pivot);
	target->height = height(target);
    return pivot;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the AVL tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print AVL tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
