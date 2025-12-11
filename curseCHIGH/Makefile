CC = gcc
CFLAGS = -Wall -Wextra
TARGET = program
OBJECTS = main.o func.o
LDFLAGS = -lm

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

main.o: main.c func.h
	$(CC) $(CFLAGS) -c main.c

func.o: func.c func.h
	$(CC) $(CFLAGS) -c func.c

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)