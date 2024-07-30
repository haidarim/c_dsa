CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = main

all: $(TARGET)

$(TARGET): main.o array_list.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o array_list.o

main.o: main.c array_list.h
	$(CC) $(CFLAGS) -c main.c

array_list.o: array_list.c array_list.h
	$(CC) $(CFLAGS) -c array_list.c

clean:
	rm -f $(TARGET) *.o
