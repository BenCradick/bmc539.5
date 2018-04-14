CC = gcc
CFLAGS = -std=c99
TARGET = shuffle
OBJS = shuffle.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
sieve.o: sieve.c
	$(CC) -c shuffle.c

clean:
	/bin/rm -f *.o $(TARGET)
git