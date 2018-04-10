

### yes, I took it from my last project. Deal. With. It.

# SECTION: VARIABLES

## The compiler 
CC = g++

## Additional flags
FLAGS =

## Language modifier
LANGUAGE = c++11

## The executable
TARGET = ConcordiaGame

## Headers' inclusion
INCLUDES = -I ./include

## SFML
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

## Objects directory
OBJS-DIR = ./bin

## Source files directory
SRC = ./src

## The source code files
CPPS = $(wildcard $(SRC)/*.cpp)

## Objects required by main
OBJS = $(addprefix $(OBJS-DIR)/,$(notdir $(CPPS:.cpp=.o)))

# SECTION: COMPILING

## Structure: ENTITY : DEPENDENCY

## About variables: $@ refers to the ENTITY. $< refers to the first DEPENDENCY. $^ refers to the entire DEPENDENCY.

## For all entries, the dependency is the target file.
all : $(TARGET)

## To satisfy the target file dependency above, we need the objects.
$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -std=$(LANGUAGE) ./$^ $(SFML) -o ./bin/$@

## To satisfy the objects dependency above, we need the source code files.
$(OBJS-DIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) ./$< -o ./$@

## For entry "clean" (make clean), delete the objects and the executable.
clean :
	$(RM) $(OBJS-DIR)/*.o $(OBJS-DIR)/$(TARGET)
