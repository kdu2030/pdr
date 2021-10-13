CXX = clang++
FLAGS = -Wall -g
OBJECTS = AVLNode.o AVLPathTest.o AVLTree.o

main: $(OBJECTS)
	$(CXX) $(OBJECTS) $(FLAGS)

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
