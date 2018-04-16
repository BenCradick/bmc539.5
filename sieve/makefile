CC = gcc
CFLAGS = -std=c99
TARGET = sieve
OBJS = sieve.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
sieve.o: sieve.c
	$(CC) -c sieve.c
debug:
	$(CC)  sieve.c -DDEBUG -o $(TARGET)

clean:
	/bin/rm -f *.o $(TARGET)