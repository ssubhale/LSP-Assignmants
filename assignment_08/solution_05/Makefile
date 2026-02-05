CC = gcc
CFLAGS = -Wall -Wextra -O2

LIB = libmath.a
LIBOBJ = math.o

TARGET = app
APPOBJ = main.o

all: $(LIB) $(TARGET)

lib: $(LIB)

$(LIB): $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

math.o: math.c math.h
	$(CC) $(CFLAGS) -c math.c

app: $(LIB) $(APPOBJ)
	$(CC) $(CFLAGS) $(APPOBJ) -L. -lmath -o $(TARGET)

main.o: main.c math.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(LIB) $(TARGET)

.PHONY: all lib app clean
