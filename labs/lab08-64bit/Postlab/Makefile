
CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OBJECTS = testLinearSearch.o linearSearch.o

a.out: $(OBJECTS)
	$(AS) $(ASFLAGS) linearSearch.s
	$(CXX) $(CXXFLAGS) $(OBJECTS)
