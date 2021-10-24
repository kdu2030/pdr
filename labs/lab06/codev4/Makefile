CXX = clang++
CXXFLAGS = -O2
IFLAGS = -O2 -c
OBJECTS = hashTable.o wordPuzzle.o timer.o


main: $(OBJECTS)
	$(CXX) $(IFLAGS) hashTable.cpp
	$(CXX) $(IFLAGS) wordPuzzle.cpp
	$(CXX) $(IFLAGS) timer.cpp
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	
hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h
timer.o: timer.cpp timer.h
