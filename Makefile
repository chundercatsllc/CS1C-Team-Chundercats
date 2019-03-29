# Compiler Specific:
COMP=g++
CFLAG=-c
WFLAG=-Wall
OFLAG=-o

# Program Specific:
SOURCES=

OBJECT_LIST=pHash/pHash.o

OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(SOURCES:.cpp=.h)
EXECUTABLE=


# Start of Make:
Start: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(COMP) $(OBJECTS) $(OBJECT_LIST) $(OFLAG) $@ $(WFLAG)

.cpp.o:
	$(COMP) $(CFLAG) $< $(OFLAG) $@ $(WFLAG)

# Cleanup Routines:
clean:
	rm $(OBJECTS) $(EXECUTABLE)

clean-o:
	rm $(OBJECTS)

clean-b:
	rm $(EXECUTABLE)

clean-tar:
	rm $(EXECUTABLE).tar

show-tar:
	tar -tvf $(EXECUTABLE).tar

tar:
	tar -cf $(EXECUTABLE).tar *.cpp *.h $(EXECUTABLE).scr