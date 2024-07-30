# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -g

# Source files
SRCS = hash_map.c main.c Map.c

# Header files
HEADERS = hash_map.h Map.h

# Output executable
TARGET = hashmap

# Object files
OBJS = $(SRCS:.c=.o)

# Default target to build the program
all: $(TARGET)

# Rule to build the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Clean target to remove compiled files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
