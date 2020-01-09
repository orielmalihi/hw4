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
#define WORD_LENGTH 30
#define PRE_ORDER 1
#define POST_ORDER 0

/**
 * this function allocs the head node of the trie and return
 * a node* pointer to the alloced head.
 */
node* Trie_alloc(){
	node* p = (node*)calloc(1,sizeof(node));
//	printf("aloc complete\n");
	return p;
}

/**
 * this function adds a word to the trie
 */
void addWord(node* head, char* str){
	node* current = head;
	while(*str){
		char c = *str;
		if(current->children[c-LETTER_OFFSET] == NULL){
			current->children[c-LETTER_OFFSET] = (node*)calloc(1, sizeof(node));
			current->children[c-LETTER_OFFSET]->letter = c;
			strcpy(current->children[c-LETTER_OFFSET]->word, current->word);
			int index_last = strlen(current->children[c-LETTER_OFFSET]->word);
			current->children[c-LETTER_OFFSET]->word[index_last] = c;
		}
		current = current->children[c-LETTER_OFFSET];
		str++;
	}
	current->count++;
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
	free(head);
	return;
}

/**
 * this function prints the trie pre-order for order  = 1, and
 * post-order for order = 0.
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




