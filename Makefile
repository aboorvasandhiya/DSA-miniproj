PROGRAM = EEEAllocator
CC      = g++
CFLAGS  = -std=c++17 -Wall -Wextra -Wpedantic
CBUILD  = $(CC) $(CFLAGS)

OBJECTS = Helper.o Student.o Vacancy.o StudentManager.o EEEAllocator.o

.PHONY: clean

$(PROGRAM): $(OBJECTS) Main.o
	$(CBUILD) -o $@ $?

%.o: %.cpp
	$(CBUILD) -c $?

clean:
	rm -rf *.o
	rm -rf $(PROGRAM)

