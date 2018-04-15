CC = gcc
CFLAGS = -std=c99
TARGET = sb
OBJS = sb.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: sb.c
	$(CC) -c sb.c

debug:
	gcc sb.c -DDEBUG -o $(TARGET)

clean:
	/bin/rm -f *.o* $(TARGET)
