CC = gcc
CFLAGS = -Wall -Wextra -O2 -fPIC
LDFLAGS_SO = -shared

LIBSO = libmath.so
TARGET = app

all: so app

so: $(LIBSO)

$(LIBSO): math.o
	$(CC) $(LDFLAGS_SO) -o $(LIBSO) math.o

math.o: math.c math.h
	$(CC) $(CFLAGS) -c math.c

app: main.o $(LIBSO)
	$(CC) main.o -L. -lmath -Wl,-rpath=. -o $(TARGET)

main.o: main.c math.h
	$(CC) -Wall -Wextra -O2 -c main.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(LIBSO) $(TARGET)

.PHONY: all so app run clean
