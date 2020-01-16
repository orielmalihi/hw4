/*
 * trie.c
 *
 *  Created on: 7 Jan 2020
 *      Author: oriel
 */
#include <trie.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_LETTERS ((int)26)
#define LETTER_OFFSET 97
#define PRE_ORDER 1
#define POST_ORDER 0

/**
 * this function allocs the head node of the trie and return
 * a node* pointer to the alloced head.
 */
node* Trie_alloc(){
	node* p = (node*)calloc(1,sizeof(node));
	p->wordSize = 2;
	p->word = calloc(1,2*sizeof(char));
	//	printf("aloc complete\n");
	return p;
}

/**
 * this function adds a word to the trie
 */
void addWord(node* head, char* str){
	node* parent = head;
	node* son;
	while(*str){
		char c = *str;
		son = parent->children[c-LETTER_OFFSET];
		if(son == NULL){
			son = (node*)calloc(1, sizeof(node));
			son->wordSize = parent->wordSize;
			son->word = (char*)calloc(1, son->wordSize);
			son->letter = c;
			strcpy(son->word, parent->word);
			int index_last = strlen(son->word);
			if(index_last == son->wordSize-1){
				son->wordSize += 20;
				son->word = realloc(son->word,son->wordSize);
			}
			son->word[index_last] = c;
			son->word[index_last+1] = 0;
			parent->children[c-LETTER_OFFSET] = son;
		}
		parent = son;
		str++;
	}
	parent->count++;
}

/**
 * this function free all the alloced nodes of the trie
 */

void freeTrie(node* head){
	if(head == NULL)
		return;
	for(int i = 0; i<NUM_LETTERS; i++){
		freeTrie(head->children[i]);
	}
	free(head->word);
	free(head);
	return;
}

/**
 * this function prints the trie pre-order for order = 1,
 *  and post-order for order = 0.
 */

void printTrie(node* head, int order){
	if(head == NULL)
		return;
	if(0 < head->count)
		printf("%s\t%ld\n", head->word, head->count);
	if(order == POST_ORDER){
		for(int i = NUM_LETTERS-1; i>=0; i--)
			printTrie(head->children[i], POST_ORDER);
	}
	if(order == PRE_ORDER){
		for(int i = 0; i<NUM_LETTERS; i++)
			printTrie(head->children[i], PRE_ORDER);
	}
}




