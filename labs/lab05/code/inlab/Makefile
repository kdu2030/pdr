CXX = clang++
OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o
FLAGS = -Wall -g

main: $(OBJECTS)
	$(CXX) $(OBJECTS) $(FLAGS)

BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

