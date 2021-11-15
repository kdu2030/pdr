CXX = clang++

CXXFLAGS = -Wall -g

# Assembler
AS = nasm

#-f elf64 assemble in 64 bit format for linux
#-g include debugging symbols
ASFLAGS = -f elf64 -g

OBJECTS = mathlib.o mathfun.o

a.out: $(OBJECTS)
	$(AS) $(ASFLAGS) mathlib.s
	$(CXX) $(CXXFLAGS) $(OBJECTS)
