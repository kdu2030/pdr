CXX = clang++

CXXFLAGS = -Wall -g

# Assembler
AS = nasm

#-f elf64 assemble in 64 bit format for linux
#-g include debugging symbols
ASFLAGS = -f elf64 -g

OBJECTS = mergeSort.o testMergeSort.o

a.out: $(OBJECTS)
	$(AS) $(ASFLAGS) mergeSort.s
	$(CXX) $(CXXFLAGS) $(OBJECTS)
