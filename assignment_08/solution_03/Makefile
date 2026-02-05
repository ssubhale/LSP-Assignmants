CC = gcc
CFLAGS = -Wall -Wextra
TARGET = app
SRC = main.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

help:
	@echo "Usage:"
	@echo "  make        -> Build the project"
	@echo "  make run    -> Run the executable"
	@echo "  make clean  -> Remove executable"
	@echo "  make help   -> Show this help message"

.PHONY: run clean help
