CXX = clang++
CXXFLAGS = -Wall -g
OBJECTS = TreeCalc.o TreeCalcTest.o TreeNode.o 


main: $(OBJECTS) 
	$(CXX) $(OBJECTS)
	
TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
TreeNode.o: TreeNode.cpp TreeNode.h
