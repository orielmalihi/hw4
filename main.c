/*
 * main.c
 *
 *  Created on: 7 Jan 2020
 *      Author: oriel
 */
#include <stdio.h>
#include <string.h>
#include <trie.h>

#define WORD 30

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
	char word[WORD];
	/**
	 * get word from the buffer and insert to the trie
	 */
	while((c = getchar()) != EOF){
		int index = 0;
		while(c!='\n' && c!='\t' && c!=' '){
			if(c >= 97 && c<= 122){
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
	return 0;
}


