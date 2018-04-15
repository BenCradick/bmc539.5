CC = gcc
CFLAGS = -std=c99
TARGET = main
OBJS = main.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: main.c
	$(CC) -c main.c

debug:
	gcc main.c -DDEBUG -o main

clean:
	/bin/rm -f *.o* $(TARGET)
