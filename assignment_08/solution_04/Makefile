CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = app
OBJ = main.o helper.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

main.o: main.c helper.h
	$(CC) $(CFLAGS) -c main.c

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c

clean:
	rm -f *.o $(TARGET)

.PHONY: clean
