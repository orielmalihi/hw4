/*
 * main.c
 *
 *  Created on: 7 Jan 2020
 *      Author: oriel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <trie.h>


int main(int argc, char *argv[]){
	/**
	 * set whether to print the trie pre-order or post-order
	 */
	int order = 1;
	if(argc == 2)
		if(**(argv+1)=='r')
			order = 0;
	/**
	 * build the tree
	 */
	node* trie_head = Trie_alloc();
	char c = 0;
	int size = 10;
	char* word = calloc(1,size*sizeof(char));
	/**
	 * get word from the buffer and insert to the trie
	 */
	while((c = getchar()) != EOF){
		int index = 0;
		while(c!='\n' && c!='\t' && c!=' '){
			if(c>= 65 &&  c<=90){
				c += 32;
			}
			if(c >= 97 && c<= 122){
				if(index==size-1){
					size += 20;
					word = realloc(word, size);
				}
				word[index] = c;
				index++;
			}
			c = getchar();
		}
		word[index] = 0;
		if(strlen(word)>0){
			addWord(trie_head, word);
		}
	}
	/**
	 * print the trie
	 */
	printTrie(trie_head, order);
	freeTrie(trie_head);
	free(word);
	return 0;
}


