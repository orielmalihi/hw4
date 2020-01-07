CC = gcc
AR = ar
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: frequency

frequency: main.o 
	$(CC) $(FLAGS) -o frequency $^ -I.
main.o: main.c trie.o trie.h
	$(CC) $(FLAGS) -c -o $@ $< -I.
trie.o: trie.c
	$(CC) $(FLAGS) -fPIC -c -o $@ $< -I.		
	
.PHONY: clean all
	
clean:
	rm -f *.o *.out *.a frequency
