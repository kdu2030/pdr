CXX = clang++
CXXFLAGS = -Wall -g -O2
IFLAGS = -O2 -c
OBJECTS = hashTable.o wordPuzzle.o timer.o


main: $(OBJECTS)
	$(CXX) $(IFLAGS) hashTable.o
	$(CXX) $(IFLAGS) wordPuzzle.o
	$(CXX) $(IFLAGS) timer.o
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	
hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h
timer.o: timer.cpp timer.h
