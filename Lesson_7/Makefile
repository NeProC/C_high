#Variables 
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

build:
	$(CC) $(CFLAGS) $(FILE) -o $(basename $(FILE)) -lncurses

run: build
	./$(basename $(FILE))

clean:
	rm -f *.o *.out

big_clean: clean
	rm -f $(basename $(FILE))

